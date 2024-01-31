module Quatro where

frst :: String -> String
frst str = "Sr. " ++ str

scnd :: String -> String
scnd str = "Sra. " ++ str

thrd :: String -> String
thrd str = "Srta. " ++ str

func :: [String] -> (String -> String) -> [String]
func [] _ = []
func (h:t) x = [x h] ++ func t x
