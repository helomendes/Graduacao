import argparse

def argument_parser():
    parser = argparse.ArgumentParser()
    parser.add_argument("--file", help="Path to file to be encrypted", required=True)
    parser.add_argument("--key", help="Key to be used", required=True)
    parser.add_argument("--tracks", help="Tracks", required=True)
    args = parser.parse_args()
    return args

def save_file(message, name: str):
    if isinstance(message, (bytes, bytearray)):
        with open(f"{name}.txt", "wb") as f:
            f.write(message)
    elif isinstance(message, str):
        with open(f"{name}.txt", "w", encoding="utf-8") as f:
            f.write(message)
    else:
        raise TypeError(f"Unsupported type for save_file: {type(message)}")

def remover_x_extras(texto_decifrado):
    resultado = []
    i = 0
    while i < len(texto_decifrado):
        if i < len(texto_decifrado) - 2:
            a, b, c = texto_decifrado[i], texto_decifrado[i+1], texto_decifrado[i+2]
            if a == c and b == 'X':
                resultado.append(a)
                resultado.append(c)
                i += 3
                continue
        # último caractere padding
        if i == len(texto_decifrado) - 1 and texto_decifrado[i] == 'X':
            break
        resultado.append(texto_decifrado[i])
        i += 1
    return ''.join(resultado)
