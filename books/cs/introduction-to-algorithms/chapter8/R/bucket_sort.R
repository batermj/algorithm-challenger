#
# bucket sort algorithm
# introduction to algorithm, 3rd edition, chapter 3
#
# clean the workspace and memory

rm( list=ls() )
gc()

srcdata <- sample(99,10,replace = T) /100
len = length(srcdata)
print(srcdata)
print(len)

aaa <- list()
for( idx in seq(len) ){
	aaa[[idx]] <- c(-1)
}

for( dValue in srcdata ){
	aaa[[1+floor(dValue*len)]] <- c(aaa[[1+floor(dValue*len)]],dValue)
}
print(aaa)
for( idx in seq(len) ){
	aaa[[idx]] <- sort(aaa[[idx]][-1])
}
print(aaa)
print(unlist(aaa))
