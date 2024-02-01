#!python3

import itertools
import time
import math
from typing import *

def find_shortest_hamiltonian_cycle (distances)->str:
	num_of_towns = len(distances)
	shortest_distance_so_far = math.inf
	shortest_path_so_far = None
	all_towns = range(0,num_of_towns)
	for path in itertools.permutations(all_towns):
		distance = 0
		for i in range(1,len(path)+1):
			prev_town = path[i-1]
			cur_town = path[i % len(path)]
			cur_distance = distances[prev_town][cur_town]
			distance += cur_distance
		if distance < shortest_distance_so_far:
			shortest_distance_so_far = distance
			shortest_path_so_far = list(path)

	# show the shortest path
	path = shortest_path_so_far
	result=str(path[0])
	for i in range(1,len(path)+1):
		prev_town = path[i-1]
		cur_town = path[i % len(path)]
		cur_distance = distances[prev_town][cur_town]
		result += " --" + str(cur_distance) + "--> " + str(cur_town)
	result += ": == "+str(shortest_distance_so_far)
	return result


if __name__=="__main__":
		
	distances = [  # 3 towns -- 6 permutations
		[0,2,3],
		[4,0,6],
		[7,8,0]
	]
	print(find_shortest_hamiltonian_cycle(distances), flush=True)

	distances = [ # 11 towns -- 11! permutations
		[1,0,3,4,5,6,7,8,9,10,11],
		[1,2,3,4,5,6,7,0,9,10,11],
		[1,2,3,0,5,6,7,8,9,10,11],
		[1,2,0,4,5,6,7,8,9,10,11],
		[1,2,3,4,5,6,7,8,0,10,11],
		[1,2,3,4,5,0,7,8,9,10,11],
		[1,2,3,4,5,6,7,8,9,0,11],
		[1,2,3,4,0,6,7,8,9,10,11],
		[0,2,3,4,5,6,7,8,9,10,11],	
		[1,2,3,4,5,6,7,8,0,10,11],	
		[1,2,3,4,5,6,7,8,2,8,11],	
	]
	start = time.process_time()
	print(find_shortest_hamiltonian_cycle(distances), flush=True)
	end = time.process_time()
	duration_in_seconds = end-start
	print("Shortest path calculated in {} seconds".format(duration_in_seconds), flush=True)
