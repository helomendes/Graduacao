.section .bss
    .global original_brk
    .global current_brk

    .lcomm original_brk 8
    .lcomm current_brk 8

.section .text
    .global setup_brk
    .global dismiss_brk
    .global memory_alloc
    .global memory_free

    # Obtém o endereço de brk
    setup_brk:
        pushq %rbp
        movq %rsp, %rbp

        movq $0, %rdi
        movq $12, %rax
        syscall
        movq %rax, original_brk
        movq %rax, current_brk
        
        popq %rbp
        ret

    # Restaura o endereço de brk
    dismiss_brk:
        pushq %rbp
        movq %rsp, %rbp

        movq original_brk, %rdi
        movq %rdi, current_brk
        movq $12, %rax
        syscall

        popq %rbp
        ret

    # 1. Procura bloco livre com tamanho igual ou maior que a requisição
    # 2. Se encontrar, marca ocupação, utiliza os bytes necessários do bloco, retornando o endereço correspondente
    # 3. Se não encontrar, abre espaço para um novo bloco
    memory_alloc:
        pushq %rbp                          # inicialização da função
        movq %rsp, %rbp

        movq original_brk, %rdx             # **** %rdx -> bloco USE
        movq original_brk, %r15				# inicialização do ponteiro
        movq %rdi, %rbx                     # move o argumento passado por %rdi para %rbx (tamanho a ser alocado)

        _inicio_for:
            cmp %rdx, current_brk
            jle _alocar_bloco               # current_brk <= %rdx -> ALOCAR BLOCO             
                                            # current_brk > %rdx -> PROCURAR BLOCO LIVRE
            cmpq $0, (%rdx)                 # verifica se o USE é 0 -> se o bloco está livre
            jne _iterar

            cmp 8(%rdx), %rbx               # verifica se o tamanho do bloco disponível é suficiente
            jg _iterar

            movq 8(%rdx), %rax
            cmp %rax, (%r15)                # verifica se o que está armazenado em %r15 é maior ou igual
            jge _iterar
                                            # atualiza o %r15
            movq %rdx, %r15                 # **** %r15 -> bloco USE
            addq $8, %r15                   # **** %r15 -> bloco SIZE

            _iterar:                        # o bloco atual está ocupado
            movq 8(%rdx), %r12              # **** %r12 -> tamanho requerido
            addq $16, %rdx                  # **** %rdx -> bloco EDITÁVEL
            addq %r12, %rdx                 # **** %rdx -> bloco USE próximo

            jmp _inicio_for

            _alocar_bloco:
                cmp original_brk, %r15      # verifica se %r15 ainda aponta para original_brk
                je _alocar_novo

                movq %r15, %rdx             # **** %rdx -> bloco SIZE do bloco a ser utilizado
                subq $8, %rdx               # **** %rdx -> bloco USE do bloco a ser utilizado

                jmp _bloco_livre

            _alocar_novo:
				movq %rbx, %r12             # **** %r12 -> tamanho requerido

				addq $16, %rbx
				addq %rdx, %rbx             # **** %rbx -> = tamanho requerido + 16 + endereço do USE
				movq %rbx, %rdi             
				movq $12, %rax
				syscall                     # aloca o tamanho necessário para o bloco no endereço correto

				cmp %rax, %rdx              # se a alocação de memória funcionou, %rax deve ser diferente de %rdx
				je _erro

				movq $1, (%rdx)             # marca o bloco como ocupado
				movq %r12, 8(%rdx)          # escreve o tamanho do bloco
				addq $16, %rdx              # **** %rdx -> bloco EDITÁVEL

				movq %rbx, current_brk      # atualiza o brk_corrente para o fim do bloco alocado
				movq %rdx, %rax             # define o bloco editável como retorno da função

                jmp _fim_memory_alloc

            _bloco_livre:
                movq %rbx, %r12             # **** %r12 -> tamanho requerido
                movq 8(%rdx), %r13          # **** %r13 -> tamanho disponível       

                movq $1, (%rdx)             # marca o bloco como ocupado

                subq %r12, %r13             # subtrai o tamanho requerido do tamanho disponível
                                            # **** %r13 -> disponível - requerido
                cmp $17, %r13               # compara o resultado com 17 (tamanho mínimo)

                jge _overfit                # %r13 >= $17

                addq $16, %rdx              # **** %rdx -> bloco EDITÁVEL
                movq %rdx, %rax             # define como retorno da função
                jmp _fim_memory_alloc     

                _overfit:
                    movq %rbx, 8(%rdx)      # escreve o tamanho do bloco

                    addq $16, %rdx          # **** %rdx -> bloco EDITÁVEL
                    movq %rdx, %r14         # **** %r14 -> bloco EDITÁVEL
                    addq %rbx, %r14         # **** %r14 -> FIM bloco EDITÁVEL

                    movq $0, (%r14)         # marca o bloco como livre
                    addq $8, %r14           # **** %r14 -> bloco SIZE
                    subq $16, %r13          # subtrai 16 do tamanho restante do bloco (USE e SIZE)
                    movq %r13, (%r14)       # escreve o tamanho disponível

                    movq %rdx, %rax         # define o retorno da função
                    jmp _fim_memory_alloc

            _erro:
				movq $0, %rax
				jmp _fim_memory_alloc

		_fim_memory_alloc:

        popq %rbp
        ret

    # Marca um bloco ocupado como livre
    memory_free:
		pushq %rbp
		movq %rsp, %rbp

		subq $16, %rdi

		cmp current_brk, %rdi
		jg _erro_ponteiro

		cmp original_brk, %rdi
		jl _erro_ponteiro

		cmpq $0, (%rdi)
		je _erro_ponteiro

        # considerando que o %rdx armazena o endereço do USE
        movq $0, (%rdi)
		movq $1, %rax
		jmp _fim_memory_free

		_erro_ponteiro:
			movq $0, %rax
			jmp _fim_memory_free
			
		_fim_memory_free:
		popq %rbp
		ret		
