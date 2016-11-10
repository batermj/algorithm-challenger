import System.Random

dataset_size = 100
dataset_max_value = 100

main = do
 gen <- getStdGen
 let aaa = take dataset_size (randomRs (0,dataset_max_value) gen) :: [Integer]
 print aaa 
 
 
 return 0
