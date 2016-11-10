#
# radix sort algorithm
# introduction to algorithm, 3rd edition, chapter 3
#
# clean the workspace and memory

rm( list=ls() )
gc()

aaa <- sample(999,20,replace = T)
aaa <- aaa[aaa>100]
digit <- 3

count_sort <- function( srcdata,aaa ){
  k <- max(aaa)
  bbb <- rep(0,length(aaa))
  ccc <- rep(0,k+1)
  
  for(idx in aaa){
    ccc[idx+1] <- ccc[idx+1] + 1
  }
  ccc <- cumsum(ccc)
  
  aaar <- rev(aaa)
  srcdatar <- rev(srcdata)
  
  for(idx in seq(length(aaar))){
    bbb[ccc[aaar[idx]+1]] <- srcdatar[idx]
    ccc[aaar[idx]+1] <- ccc[aaar[idx]+1] - 1
  }
  return(bbb)
}

getDigit <- function(iValue, iDigit){
  (iValue %/% (10^(iDigit-1))) %% 10
}

print(aaa)
ccc <- seq(length(aaa))
for(idx in seq(digit)){
  bbb <- NULL
  for(iValue in aaa){
    bbb <- c(bbb,getDigit(iValue,idx))
  }
  aaa <- count_sort(aaa,bbb)
}
print(aaa)
