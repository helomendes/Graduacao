module Condicionais where

--Escreva uma função que receba a idade de uma pessoa e determine se ela
--possui idade para consumir bebidas alcoólicas. Considere que a idade mínima
--permitida para consumo de álcool seja 18. A função deve retornar uma string.
-- - Implemente a versão com guardas
-- - Implemente a versão com if-then-else

a1 :: Int -> String
a1 x = if x >= 18
 then "Maior de Idade"
 else "Menor de Idade"

a2 :: Int -> String
a2 x
 | x >= 18 = "Maior de Idade"
 | otherwise = "Menor de Idade"

--Escreva uma função que receba um número e determine se ele é positivo,
--negativo ou igual a zero. A função deve retornar uma string.
-- - Implemente a versão com guardas
-- - Implemente a versão com if-then-else

b1 :: Int -> String
b1 x = if x > 0
 then "Positivo"
 else if x == 0
 then "Igual a zero"
 else "Negativo"

b2 :: Int -> String
b2 x
 | x > 0 = "Positivo"
 | x == 0 = "Igual a zero"
 | otherwise = "Negativo"

--Escreva uma função que verifique se um ano é bissexto ou não. A função deve
--retornar true ou false.
--Dica: Um ano é bissexto se for divisível por 4, exceto quando é divisível por 100.
--No entanto, se um ano for divisível por 400, ele também é bissexto.
-- - Implemente a versão com if-then-else
-- - Implemente a versão com if-then-else usando where
-- - Implemente a versão com guardas usando where

c1 :: Int -> Bool
c1 x = if mod x 4 == 0 && mod x 100 == 0
 then True
 else if mod x 4 == 0
  then True
  else False

c2 :: Int -> Bool
c2 x = ehBissexto
 where
  ehBissexto = if mod x 4 == 0 && mod x 100 == 0
   then True
   else if mod x 4 == 0
    then True
    else False

c3 :: Int -> Bool
c3 x
 | mod x 4 == 0 && mod x 100 == 0 = True
 | mod x 4 == 0 = True
 | otherwise = False

c4 :: Int -> Bool
c4 x
 | condicao1 == True && condicao2 == True = True
 | condicao1 = condicao1
 | otherwise = False
 where
  condicao1 = if mod x 4 == 0
   then True
   else False

  condicao2 = if mod x 100 == 0
   then True
   else False