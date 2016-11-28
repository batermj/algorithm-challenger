#
# insertion sort algorithm
# introduction to algorithm, 3rd edition, chapter 2
#
# clean the workspace and memory

rm( list=ls() )
gc()

aaa <- sample(999,10,replace = T)
srcdata <- aaa[aaa>100]

insertion_sort <- function(srcdata){
	for( idx in seq(length(srcdata))[-1] ){
		iValue <- srcdata[idx]
		jdx <- idx - 1
		while( ( jdx>=1 ) && ( srcdata[jdx] > iValue ) ){
				srcdata[jdx+1] <- srcdata[jdx] 
				jdx <- jdx - 1
		}
		srcdata[jdx+1] <- iValue
	}
	srcdata
}

print(srcdata)
srcdata <- insertion_sort(srcdata)
print(srcdata)
