#
# quick sort algorithm
# introduction to algorithm, 3rd edition, chapter 7
#
# clean the workspace and memory

rm( list=ls() )
gc()

swap <- function(i,j){
  temp <- srcdata[i]
  srcdata[i] <<- srcdata[j]
  srcdata[j] <<- temp
}

partition <- function(p,r,partitionType){
  print(c(p,r,"",length(srcdata),srcdata))
  if(partitionType>0){
	i <- p + sample(r-p,1)
	swap(i,p)
  }
  x <- srcdata[r]
  idx <- p-1
  for(jdx in p:(r-1)){
    if( srcdata[jdx] >= x ){
      idx <- idx + 1
      swap(idx,jdx)
    }
  }
  swap(idx+1,r)
  print(c(p,r,idx+1,length(srcdata),srcdata))
  return( idx+1 )
}

quick_sort <- function(p,r,partitionType){
  if( p<r ){
    q <- partition(p,r,partitionType)
    quick_sort(p,q-1,partitionType)
    quick_sort(q+1,r,partitionType)
    print(c(p,r, srcdata))
  }
}

quick_sort_v2 <- function(srcdata){
  if( length(srcdata)<=1 ) return(srcdata)
  
  q <- 1
  pivot <- srcdata[q]
  srcdata <- srcdata[-1]

  data_smaller <- srcdata[srcdata<=pivot]
  data_bigger <- srcdata[srcdata>pivot]
  
  return(c(quick_sort_v2(data_smaller),pivot,quick_sort_v2(data_bigger)))
}

print("Quick sort algorithm with original partition pivot")
aaa <- sample(999,10,replace = T)
srcdata <- aaa[aaa>100]
print(srcdata)
quick_sort(1,length(srcdata),0)
print(srcdata)

print("Quick sort algorithm with randomized partition pivot")
aaa <- sample(999,10,replace = T)
srcdata <- aaa[aaa>100]
print(srcdata)
quick_sort(1,length(srcdata),1)
print(srcdata)

print("Quick sort algorithm with result returned by function")
aaa <- sample(999,10,replace = T)
srcdata <- aaa[aaa>100]
print(srcdata)
srcdata <- quick_sort_v2(srcdata)
print(srcdata)
