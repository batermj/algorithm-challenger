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
  if( r<=len && srcdata[r]>srcdata[largest] ){
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
