module Exemplos where

comprimento :: [Int] -> Int
comprimento [] = 0
comprimento (h:t) = 1 + comprimento t

cubo :: [Int] -> [Int]
cubo [] = []
cubo (h:t) = h*h*h : cubo t

verificar :: [Char] -> Char -> Bool
verificar [] x = False
verfica (h:t) x
 | h == x = True
 | otherwise = verificar t x

possuiChar :: [Char] -> Char -> Bool
possuiChar [] ch = False
possuiChar (cabeca:cauda) ch
 | cabeca == ch = True
 | otherwise = possuiChar cauda ch