#
# heap sort algorithm
# introduction to algorithm, 3rd edition, chapter 6
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

left <- function(i){
  return(2*i)
}

right <- function(i){
  return(2*i+1)
}

max_heapify <- function(len,i){
  l <- left(i)
  r <- right(i)
  largest <- 0
  
  if( l<=len && srcdata[l]>srcdata[i] ){
    largest <- l
  }else largest <- i
  if( r<=len && srcdata[r]>srcdata[i] ){
    largest <- r
  }
  
  if( largest != i ){
    swap(i,largest)
    max_heapify(len,largest)
  }
}

build_max_heap <- function(len){
  
  for( idx in floor(len/2):1 ){
	max_heapify(len,idx)
  }
}

heap_sort <- function(len){
  
  build_max_heap(len)
  for( idx in len:2 ){
	swap(idx,1)
	len <- len-1
	max_heapify(len,1)
  }
}

print(srcdata)
#quick_sort(1,length(srcdata))
heap_sort(length(srcdata))
print(srcdata)
