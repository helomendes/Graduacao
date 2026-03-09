module Recursoes where

--Escreva uma função recursiva que gere o n-ésimo termo da sequência de
--Fibonacci usando recursão. Dica: a função retorna 0 quando n é igual a 0; 1
--quando n é igual a 1; e a soma dos dois termos anteriores do n-éstimo termo.

a1 :: Int -> Int
a1 0 = 0
a1 1 = 1
a1 x = a1 (x-2) + a1 (x-1)

a2 :: Int -> Int
a2 x
 | x == 0 = 0
 | x == 1 = 1
 | otherwise = a2 (x-2) + a2 (x-1)

--Escreva uma função recursiva que conte o número de dígitos de um número
--inteiro. Considere que o número digitado como entrada é sempre maior que
--zero.

b1 :: Int -> Int
b1 x = if x < 10
    then 1
    else 1 + b1 (div x 10)

b2 :: Int -> Int
b2 x
 | x < 10 = 1
 | otherwise = 1 + b2 (div x 10)

--Escreva uma função recursiva que calcule a soma dos dígitos de um número
--inteiro. Considere que o número digitado como entrada é sempre maior que
--zero.

c1 :: Int -> Int
c1 x = if x < 10
    then x
    else (mod x 10) + c1 (div x 10)

c2 :: Int -> Int
c2 x
 | x < 10 = x
 | otherwise = (mod x 10) + c2 (div x 10)