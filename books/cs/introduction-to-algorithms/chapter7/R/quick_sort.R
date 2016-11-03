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

partition <- function(p,r){
  print(c(p,r,"",length(srcdata),srcdata))
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

quick_sort <- function(p,r){
  if( p<r ){
    q <- partition(p,r)
    quick_sort(p,q-1)
    quick_sort(q+1,r)
    print(c(p,r, srcdata))
  }
}

print(srcdata)
quick_sort(1,length(srcdata))
print(srcdata)
