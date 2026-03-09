module Casamentos where

padrao :: Int -> String
padrao 1 = "um"
padrao 2 = "dois"
padrao 3 = "tres"
padrao _ = "não está entre 1 e 3"

padrao1 :: [Int] -> Int
padrao1 [] = 0
padrao1 (_:t) = 1 + padrao1 t

type Tupla4 = (Int, Int, Int, Int)
padrao2 :: Tupla4 -> String
padrao2 (_,_,_,k)
  | k > 10 = "Maior que 10"
  | otherwise = "Não é maior que 10"

f1 :: Int -> Int -> Int -> Int
f1 x y z | x == 1 = 10
           | y == 2 = 20
           | z == 3 = 30
           | otherwise = 0

f2 :: Int -> Int -> Int -> Int
f2 1 _ _ = 10
f2 _ 2 _ = 20
f2 _ _ 3 = 30
f2 _ _ _ = 0

func :: (Int, (Int, Int)) -> Int
func z = if fst z == 1
           then fst (snd z) + snd (snd z)
           else if fst z == 2
             then fst (snd z) - snd (snd z)
             else 0

func2 :: (Int, (Int, Int)) -> Int
func2 (1, (x, y)) = x + y
func2 (2, (x, y)) = x - y
func2 (_, (_, _)) = 0
