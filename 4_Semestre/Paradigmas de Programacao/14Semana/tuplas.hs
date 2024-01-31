module Tuplas where

um :: Int -> (Int, Int, Int, Int)
um x = (x*2, x*3, x*4, x*5)

dois :: Int -> (Int, String)
dois n1
  | mod n1 2 == 0 = (div n1 2, "Par")
  | otherwise = (div n1 2, "Impar")

tres :: [Int] -> (Int, Int)
tres [] = (0, 0)
tres (h:t) = (somaPositivos (h:t), somaNegativos (h:t))
  where
    somaPositivos [] = 0
    somaPositivos (h:t) = if h >= 0
      then h + somaPositivos t
      else somaPositivos t
    somaNegativos [] = 0
    somaNegativos (h:t) = if h < 0
      then h + somaNegativos t
      else somaNegativos t

type NomeAluno = String
type MediaNota = Int
type Aluno = (NomeAluno, MediaNota)
type Turma = [Aluno]
aprovados :: Turma -> Int -> [NomeAluno]
aprovados tma nota = [nome | (nome, media) <- tma, media >= nota]

type Turistico = (String, Int, String)
type Cidade = [Turistico]
pontosTuristicos :: Int -> Cidade -> Cidade
pontosTuristicos nota cdd = [ (nome, av, tipo) | (nome, av, tipo) <- cdd, av > nota]
