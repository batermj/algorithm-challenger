
qsort [] = []
qsort (x:xs) = qsort smaller ++ [x] ++ qsort larger
				where
					smaller = [a| a <- xs, a <= x]
					larger = [a| a <- xs, a > x]

qsort [3,1,4,1,5,9,2,6]
