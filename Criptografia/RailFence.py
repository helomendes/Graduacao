class RailFence:
    def __init__(self):
        None

    def cifrar_rail_fence(self, texto, trilhos):
        # cria as "linhas" dos trilhos
        linhas = ['' for _ in range(trilhos)]
        rail = 0
        direcao = 1  # 1 descendo, -1 subindo
        for letra in texto:
            linhas[rail] += letra
            rail += direcao
            if rail == 0 or rail == trilhos - 1:
                direcao *= -1
        return ''.join(linhas)

    def decifrar_rail_fence(self, texto, trilhos):
        n = len(texto)
        # cria "máscara" indicando posições
        rail_pattern = []
        rail, direcao = 0, 1
        for _ in range(n):
            rail_pattern.append(rail)
            rail += direcao
            if rail == 0 or rail == trilhos - 1:
                direcao *= -1

        # distribui caracteres em trilhos
        rails = [[] for _ in range(trilhos)]
        idx = 0
        for r in range(trilhos):
            for i, p in enumerate(rail_pattern):
                if p == r:
                    rails[r].append(texto[idx])
                    idx += 1

        # reconstrói texto original
        resultado = []
        pos = [0] * trilhos
        for r in rail_pattern:
            resultado.append(rails[r][pos[r]])
            pos[r] += 1

        return ''.join(resultado)
