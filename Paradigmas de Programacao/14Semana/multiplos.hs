module Praticando where

multiplos :: Int -> [Int]
multiplos n = take 10 [x | x <- [1, 2..], mod x n == 0]

multiplos2 :: Int -> [Int]
multiplos2 n = [n*x | x <- [1..10]]

primo :: Int -> Bool
primo n = if length [x | x <- [1..n], mod n x == 0] <= 2
  then True
  else False
