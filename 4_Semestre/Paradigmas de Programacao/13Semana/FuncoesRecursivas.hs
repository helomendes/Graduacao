module FuncoesRecursivas where

fatorial1 :: Int -> Int
fatorial1 x
 | x == 0 = 1
 | x > 0 = x * fatorial1 (x-1)

fatorial2 :: Int -> Int
fatorial2 0 = 1
fatorial2 x = x * fatorial2 (x-1)

potencia1 :: Int -> Int -> Int
potencia1 x n
 | n == 0 = 1
 | n > 0 = x * potencia1 x (n-1)

potencia2 :: Int -> Int -> Int
potencia2 x 0 = 1
potencia2 x n = x * potencia2 x (n-1)

somatorio1 :: Int -> Int
somatorio1 a 
 | a <= 0 = 0
 | a > 0 = a + somatorio1 (a-1)
--otherwise

somatorio2 :: Int -> Int
somatorio2 0 = 0
somatorio2 a = a + somatorio2 (a-1)
