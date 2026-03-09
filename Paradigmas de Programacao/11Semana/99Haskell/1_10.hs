module OneToTen where

-- 1

-- Casos base
myLast :: [a] -> a
--myLast [] = error "No end for empty lists!" 
--myLast [x] = x

-- Execução
myLast = last

--Não entendi
--myLast = foldr1 (const id)
--myLast'' = foldr1 (flip const)
--myLast''' = head . reverse
--myLast'''' = foldl1 (curry snd)
--myLast''''' [] = error "No end for empty lists!"
--myLast'''''' x = x !! (length x - 1)


-- 2

myButLast :: [a] -> a
myButLast = last . init
