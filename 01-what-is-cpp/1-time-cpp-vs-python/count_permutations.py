#!python3

import itertools
import time

def count_permutations(N:int)->int:
	count=0
	for p in itertools.permutations(range(1,N+1)):
		count += 1
	return count

if __name__=="__main__":
	for N in range(1,13):
		print ("Permutations of 1..{}:".format(N), flush=True)
		start = time.time()
		count = count_permutations(N) 
		end = time.time()
		duration_in_seconds = end-start
		print("  {} permutations calculated in {} seconds".format(count, duration_in_seconds), flush=True)

