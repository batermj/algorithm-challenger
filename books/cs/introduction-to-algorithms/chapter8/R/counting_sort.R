#
# counting sort algorithm
# introduction to algorithm, 3rd edition, chapter 3
#
# clean the workspace and memory

rm( list=ls() )
gc()

aaa <- sample(10,10,replace = T)

count_sort <- function( aaa ){
  k <- max(aaa)
  bbb <- NULL
  ccc <- rep(0,k)

  for(idx in aaa){
    ccc[idx] <- ccc[idx] + 1
  }
  ccc <- cumsum(ccc)

  aaar <- rev(aaa)
  for(idx in aaar){
    bbb[ccc[idx]] <- idx
    ccc[idx] <- ccc[idx] - 1
  }
  return(bbb)
}

bbb <- count_sort(aaa)
