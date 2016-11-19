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
	for( idx in mid:high ){
		sum <- sum + srcdata[idx]
		if( sum > right_sum ){
			right_sum <- sum
			max_right <- idx
		}
	}
	c( max_left, max_right, left_sum+right_sum )
}

print(srcdata)
low <- 1
high <- length(srcdata)
mid <- floor(high/2)
rtn_crossing <- find_max_crossing_subarray(srcdata,low,mid,high)
print(rtn_crossing)

