module Listas where

soma :: [Int] -> Int
soma [] = 0
soma (h:t) = h + soma t

removePar :: [Int] -> [Int]
removePar [] = []
removePar (h:t) = [x | x <- (h:t), mod x 2 /= 0]

inverso :: [Int] -> [Int]
inverso [] = []
inverso (h:t) = inverso t ++ [h]

nomes :: [String] -> [String]
nomes [] = []
nomes (h:t) = [x | x <- (h:t), head x == 'A']

