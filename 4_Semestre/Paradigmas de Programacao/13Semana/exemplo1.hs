module Exemple where

maior1 :: Int -> Int -> Int
maior1 a b = if a >= b
	then a
	else b

maior2 :: Int -> Int -> Int
maior2 a b
	| a >= b = a
	| b > a = b

maior3 :: Int -> Int -> Int
maior3 a b
	| a == b = 0
	| otherwise = 1
