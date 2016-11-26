#
# merge sort algorithm
# introduction to algorithm, 3rd edition, chapter 2
#
# clean the workspace and memory

rm( list=ls() )
gc()

aaa <- sample(999,10,replace = T)
srcdata <- aaa[aaa>100]

merge <- function(srcdata,p,q,r){
	ldata <- c(srcdata[p:q],1000)
	rdata <- c(srcdata[(q+1):r],1000)
	idx <- 1
	jdx <- 1
	print(c(p,q,r))
	print(srcdata)
	print(ldata)
	print(rdata)
	for( kdx in p:r ){
		print(c(idx,jdx))
		if( ldata[idx] <= rdata[jdx] ){
			srcdata[kdx] <- ldata[idx]
			idx <- idx + 1
		}else{
			srcdata[kdx] <- rdata[jdx]
			jdx <- jdx + 1
		}
	}
	srcdata
}

merge_sort <- function(srcdata,p,r){
	if( p < r ){
		q <- floor((p+r)/2)
		srcdata[p:q] <- merge_sort(srcdata,p,q)
		srcdata[(q+1):r] <- merge_sort(srcdata,q+1,r)
		srcdata <- merge(srcdata,p,q,r)
	}
	srcdata[p:r]
}

print(srcdata)
srcdata <- merge_sort(srcdata,1,length(srcdata))
print(srcdata)
