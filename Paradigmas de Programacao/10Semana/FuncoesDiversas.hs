module FuncoesDiversas where

reajusteSalario :: Double -> Double
reajusteSalario x = x + (25*x)/100

calcularMedia :: Float -> Float -> Float -> Float -> Float -> Float -> Float
calcularMedia a b c d e f = (a*b + c*d + e*f)/(b + d+ f)

converterTemperatura :: Float -> Float
converterTemperatura x = x*(9.0/5.0)+32.0

calcularIdade :: Int -> Int
calcularIdade x = 2032 - x

calcularMinutos :: Int -> Int -> Int
calcularMinutos x y = x*60 + y

somaQuadrados :: Int -> Int -> Int -> Int
somaQuadrados x y z = x*x + y*y + z*z

somaQuadrados2 :: Float -> Float -> Float -> Float
somaQuadrados2 x y z = x ** 2 + y ** 2 + z ** 2

somaQuadrados3 :: Int -> Int -> Int -> Int
somaQuadrados3 x y z = x ^ 2 + y ^ 2 + z ^ 2

verificarImpar :: Int -> Bool
verificarImpar x = not (even x)

verificarImpar2 :: Int -> Bool
verificarImpar2 x = (mod x 2) == 1

verificarDivisivel :: Int -> Int -> Bool
verificarDivisivel x y = (mod x y) == 0

calcularSalario :: Float -> Float
calcularSalario x = x + (x*5)/100 - (x*7)/100
