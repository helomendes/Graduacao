module AltaOrdem where

-- Funções que podem receber outra função como argumento ou retornar uma função como resultado
-- Mapeamento: recebe uma lista e aplica uma operação sobre todos os elementos daquela lista
-- Filtro: recebe uma função de teste e seleciona os elementos da lista que satisfazem a condição desejada

-- Exemplo 1 - Função Mapeamento
-- função recursiva que recebe uma lista de inteiros e devolve outra com os valores da primeira elevados ao cubo

-- Calcula o cubo de um valor
cubo :: Int -> Int
cubo x = x*x*x

-- MAPEAMENTO
-- Calcula o cubo dos elementos da lista
aoCubo :: [Int] -> [Int]
aoCubo [] = []
aoCubo (h:t) = cubo h : aoCubo t

quadrado :: Int -> Int
quadrado x = x*x

aoQuadrado :: [Int] -> [Int]
aoQuadrado [] = []
aoQuadrado (h:t) = quadrado h : aoQuadrado t


