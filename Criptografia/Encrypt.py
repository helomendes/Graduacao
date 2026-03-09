from Crypto.Cipher import AES
from Crypto.Protocol.KDF import PBKDF2
from Crypto.Util.Padding import pad, unpad
from utils import remover_x_extras
from Playfair import Playfair
from RailFence import RailFence
import os

class Encrypt:
    def __init__(self):
        self.key = None
        self.iv = None
        self.tracks = None
        self.mode = { "AES": 0, "Author": 1}

    def encrypt(self, message, cod):
        if not self.mode[cod]:
            # AES algorithm
            self.key = os.urandom(16)
            cipher = AES.new(self.key, AES.MODE_CBC)
            self.iv = cipher.iv

            if isinstance(message, str):
                message = message.encode("utf-8")

            padded_plaintext = pad(message, AES.block_size)
            ciphertext = cipher.encrypt(padded_plaintext)
        else:
            playfair = Playfair()
            railfence = RailFence()

            ciphertext= railfence.cifrar_rail_fence(playfair.cifrar_playfair(message, self.key), self.tracks)

        return ciphertext

    def decrypt(self, ciphertext, cod):
        if not self.mode[cod]:
            # AES algorithm
            decipher = AES.new(self.key, AES.MODE_CBC, self.iv)
            decrypted_padded_text = decipher.decrypt(ciphertext)
            decrypted_plaintext = unpad(decrypted_padded_text, AES.block_size)
        else:
            railfence = RailFence()
            playfair = Playfair()
            texto_rf = railfence.decifrar_rail_fence(ciphertext, self.tracks)
            texto_decifrado = playfair.decifrar_playfair(texto_rf, self.key)
            decrypted_plaintext = remover_x_extras(texto_decifrado)

        return decrypted_plaintext
