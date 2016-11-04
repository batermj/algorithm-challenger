#
# quick sort algorithm
# introduction to algorithm, 3rd edition, chapter 7
#
# clean the workspace and memory

rm( list=ls() )
gc()

aaa <- sample(999,10,replace = T)
srcdata <- aaa[aaa>100]

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

print("Quick sort algorithm with original partition pivot")
print(srcdata)
quick_sort(1,length(srcdata),0)
print(srcdata)
print("Quick sort algorithm with randomized partition pivot")
aaa <- sample(999,10,replace = T)
srcdata <- aaa[aaa>100]
print(srcdata)
quick_sort(1,length(srcdata),1)
print(srcdata)
