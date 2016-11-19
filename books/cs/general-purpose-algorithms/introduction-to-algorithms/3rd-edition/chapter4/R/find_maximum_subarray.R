#
# divid and conquer
# find max subarray algorithm
# introduction to algorithm, 3rd edition, chapter 4
#
# clean the workspace and memory

rm( list=ls() )
gc()

aaa <- sample(999,10,replace = T)
srcdata <- aaa[aaa>100]
for( idx in seq(length(srcdata)) ){
	sign <- 1
	if( sample(10,1) > 5 ) sign <- -1
	srcdata[idx] <- srcdata[idx]*sign 
}

find_max_crossing_subarray <- function(srcdata,low,mid,high){
	left_sum <- -2^31
	max_left <- mid
	sum <- 0
	for( idx in mid:low ){
		sum <- sum + srcdata[idx]
		if( sum > left_sum ){
			left_sum <- sum
			max_left <- idx
		}
	}	

	right_sum <- -2^31
	max_right <- mid
	sum <- 0
	for( idx in (mid+1):high ){
		sum <- sum + srcdata[idx]
		if( sum > right_sum ){
			right_sum <- sum
			max_right <- idx
		}
	}
	c( max_left, max_right, left_sum+right_sum )
}

find_maximum_subarray <- function(srcdata,low,high){
	rtn <- c()
	if( high == low ){
		rtn <- c(low,high,srcdata[low])
	}else{
		mid <- floor( (low+high)/2 )
		rtn_left <- find_maximum_subarray(srcdata,low,mid)
		rtn_right <- find_maximum_subarray(srcdata,mid+1,high)
		rtn_crossing <- find_max_crossing_subarray(srcdata,low,mid,high)
		if( (rtn_left[3] > rtn_right[3]) && (rtn_left[3]>rtn_crossing[3]) ){
			rtn <- rtn_left
		}else if( (rtn_right[3] > rtn_left[3]) && (rtn_right[3] > rtn_crossing[3]) ){
			rtn <- rtn_right
		}else{
			rtn <- rtn_crossing
		}
	}	
	rtn
}

print(srcdata)
low <- 1
high <- length(srcdata)
rtn_crossing <- find_maximum_subarray(srcdata,low,high)
print(rtn_crossing)

