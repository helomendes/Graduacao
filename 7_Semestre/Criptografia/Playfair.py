import string

EXTRA_CHARS = [" ", ",", ".", "\n", "\t", ";", ":", "!", "?"]

class Playfair:
    def __init__(self):
        self.matriz = None
        self.pares = None

    def gerar_matriz_playfair(self, chave):
        # Remove duplicatas e junta com alfabeto + extras
        chave = ''.join(dict.fromkeys(chave.upper())) #replace("J", "I")))
        alfabeto = string.ascii_uppercase #replace("J", "")
        base = chave + ''.join([c for c in alfabeto if c not in chave])
        base += ''.join([c for c in EXTRA_CHARS if c not in base])
        # Agora a matriz tem 6 linhas de 5 colunas (30 posições)
        self.matriz = [list(base[i:i+5]) for i in range(0, 35, 5)]

    def preparar_texto_playfair(self, texto):
        # Mantém letras + extras válidos
        texto = texto.upper() #replace("J", "I")
        texto = ''.join([c for c in texto if c in string.ascii_uppercase or c in EXTRA_CHARS])
        pares = []
        i = 0
        while i < len(texto):
            a = texto[i]
            b = texto[i+1] if i+1 < len(texto) else 'X'
            if a == b:
                pares.append(a + 'X')
                i += 1
            else:
                pares.append(a + b)
                i += 2
        self.pares = pares

    def posicao(self, letra):
        for i, linha in enumerate(self.matriz):
            for j, c in enumerate(linha):
                if c == letra:
                    return i, j
        raise ValueError(f"Caractere inválido para Playfair: {repr(letra)}")

    def cifrar_playfair(self, texto, chave):
        self.gerar_matriz_playfair(chave)
        self.preparar_texto_playfair(texto)
        resultado = []
        linhas = len(self.matriz)   
        colunas = len(self.matriz[0])  
        for a, b in self.pares:
            i1, j1 = self.posicao(a)
            i2, j2 = self.posicao(b)
            if i1 == i2:  # mesma linha
                resultado.append(self.matriz[i1][(j1+1)%colunas])
                resultado.append(self.matriz[i2][(j2+1)%colunas])
            elif j1 == j2:  # mesma coluna
                resultado.append(self.matriz[(i1+1)%linhas][j1])
                resultado.append(self.matriz[(i2+1)%linhas][j2])
            else:  # retângulo
                resultado.append(self.matriz[i1][j2])
                resultado.append(self.matriz[i2][j1])
        return ''.join(resultado)

    def decifrar_playfair(self, texto, chave):
        self.gerar_matriz_playfair(chave)
        resultado = []
        linhas = len(self.matriz)      # 6
        colunas = len(self.matriz[0])  # 5
        for i in range(0, len(texto), 2):
            a, b = texto[i], texto[i+1]
            i1, j1 = self.posicao(a)
            i2, j2 = self.posicao(b)
            if i1 == i2:  # mesma linha
                resultado.append(self.matriz[i1][(j1-1) % colunas])
                resultado.append(self.matriz[i2][(j2-1) % colunas])
            elif j1 == j2:  # mesma coluna
                resultado.append(self.matriz[(i1-1) % linhas][j1])
                resultado.append(self.matriz[(i2-1) % linhas][j2])
            else:  # retângulo
                resultado.append(self.matriz[i1][j2])
                resultado.append(self.matriz[i2][j1])
        return ''.join(resultado)
