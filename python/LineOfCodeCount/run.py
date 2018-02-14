import time
import os
import LOC_count

start = time.time()

if __name__ == "__main__": 		# pragma: no cover
	fold_dir = os.getcwd()
	LOC_count.countlines(fold_dir)
	LOC_count.typeLines_print(fold_dir)
	print(LOC_count.xyz(10, 1000000, "d"))
	print(time.time() - start)
