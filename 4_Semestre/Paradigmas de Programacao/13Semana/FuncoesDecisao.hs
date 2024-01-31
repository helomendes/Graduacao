module FuncoesDecisao where

ehPar1 :: Int -> Bool
ehPar1 a = if mod a 2 == 0
 then True
 else False

ehPar2 :: Int -> Bool
ehPar2 a
 | mod a 2 == 0 = True
 | otherwise = False

triangulo1 :: Int -> Int -> Int -> Bool
triangulo1 x y z = if (x + y) > z && (x + z) > y && (y + z) > x
 then True
 else False

formarTriangulo1 :: Int -> Int -> Int -> Bool
formarTriangulo1 a b c =
 if somaAB > c && somaAC > b && somaBC > a
  then True
  else False
 where
  somaAB = a + b
  somaAC = a + c
  somaBC = b + c

formarTriangulo2 :: Int -> Int -> Int -> Bool
formarTriangulo2 a b c = condicao
 where
  somaAB = a + b
  somaAC = a + c
  somaBC = b + c
  condicao = if somaAB > c && somaAC > b && somaBC > a
   then True
   else False

triangulo2 :: Int -> Int -> Int -> Bool
triangulo2 x y z
 | x + y > z && x + z > y && y + z > x = True
 | otherwise = False

formarTriangulo3 :: Int -> Int -> Int -> Bool
formarTriangulo3 x y z
 | somaXY > z && somaXZ > y && somaYZ > x = True
 | otherwise = False

 where
  somaXY = x + y
  somaXZ = x + z
  somaYZ = y + z

media1 :: Float -> Float -> Float -> String
media1 a b c
 | media_aritmetica >= 7 = "Aprovado"
 | otherwise = "Reprovado"

 where
  media_aritmetica = (a + b + c)/3
