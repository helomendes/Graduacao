module Cinco where

ehPositivo :: Int -> Bool
ehPositivo x = if x > 0
  then True
  else False

ehNegativo :: Int -> Bool
ehNegativo x = if x < 0
  then True
  else False

ehZero :: Int -> Bool
ehZero x = if x == 0
  then True
  else False

filt :: [Int] -> (Int -> Bool)-> [Int]
filt [] _ = []
filt (h:t) f = [x | x <- (h:t), f x == True]
