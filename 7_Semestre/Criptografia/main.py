from Encrypt import Encrypt
from utils import argument_parser, save_file
import time

def main():
    args = argument_parser()

    path = args.file
    key = args.key
    tracks = int(args.tracks)

    with open(path, "r", encoding="utf-8") as f:
        plain_text = f.read()

    encrypt = Encrypt()

    start_aes_cipher = time.perf_counter()
    AES_ciphertext = encrypt.encrypt(plain_text, "AES")
    end_aes_cipher = time.perf_counter()
    save_file(AES_ciphertext, "AES_criptografado")

    start_aes_decipher = time.perf_counter()
    AES_decrypted = encrypt.decrypt(AES_ciphertext, "AES")
    end_aes_decipher = time.perf_counter()
    save_file(AES_decrypted, "AES_descriptografado")

    aes_cipher_time = end_aes_cipher - start_aes_cipher
    aes_decipher_time = end_aes_decipher - start_aes_decipher
    print(f"AES Cipher Time: {aes_cipher_time:.6f} seconds")
    print(f"AES Decipher Time: {aes_decipher_time:.6f} seconds")

    encrypt.key = key
    encrypt.tracks = tracks

    start_author_cipher = time.perf_counter()
    Author_ciphertext = encrypt.encrypt(plain_text, "Author")
    end_author_cipher = time.perf_counter()
    save_file(Author_ciphertext, "Author_criptografado")

    start_author_cipher = time.perf_counter()
    Author_decrypted = encrypt.decrypt(Author_ciphertext, "Author")
    end_author_cipher = time.perf_counter()
    save_file(Author_decrypted, "Author_descriptografado")

    author_cipher_time = end_author_cipher - start_author_cipher
    author_decipher_time = end_author_cipher - start_author_cipher
    print(f"Author Cipher Time: {author_cipher_time:.6f} seconds")
    print(f"Author Decipher Time: {author_decipher_time:.6f} seconds")

if __name__=="__main__":
    main()
