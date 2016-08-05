 #
 # counting sort algorithm
 # introduction to algorithm, 3rd edition, chapter 3
 #

import numpy

aaa = numpy.random.randint(0,10,10)
k = aaa.max()
bbb = list((1*len(aaa))*(0,))
ccc = list((1+k)*(0,))
total = 0

print aaa
print bbb
print ccc

for idx in aaa:
	print idx
	ccc[idx] += 1

idx = 0
total = 0
while idx<=k:
	total += ccc[idx]
	ccc[idx] = total
	idx += 1

print ccc

for idx in aaa[::-1]:
	print idx,
	print ccc[idx]
	bbb[ccc[idx]-1] = idx
	ccc[idx] -= 1


print aaa
print bbb
print ccc
