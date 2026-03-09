module Quicksort where

quicksort :: [Int] -> [Int]
quicksort [] = []
quicksort (h:t) = quicksort[y | y <- t, y < h] ++[h] ++ quicksort[y | y<- t, y>= h]
