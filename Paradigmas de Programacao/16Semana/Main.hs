module Main where

import Quatro
import Cinco

main :: IO ()
main = do
  --let lista1 = func ["Joao", "Jose", "Jonas"] frst
  --let lista2 = func ["Maria", "Madalena", "Maiara"] scnd
  --let lista3 = func ["Ana", "Anastacia", "Alice"] thrd
  --print(lista1)
  --print(lista2)
  --print(lista3)
  let lista = [-3, -2, -1, 0, 1, 2, 3]
  let filtered = filt lista ehZero
  print(filtered)
