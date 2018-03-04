'''
 * UVa problem: <11247>
 *
 * Topic: Brute Force
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   For a threshold m and tax rate x:
 *	 Find the largest wage that lower than m-1 after tax
 *
 * Solution Summary:
 *
 *   Brute Force
 *
 * Used Resources:
 *
 *   ...
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- (Steven Lu)
 '''

import sys
import math


EPSILON = 1e-6


def main():

	for line in sys.stdin:
		line = line.split();
		m = float(line[0])
		x = (100 - float(line[1])) * 0.01

		if (m==0 and x==1):
			return 0
		if (x==0 or x==100):
			sys.stdout.write("Not found\n")
			continue

		a = (m-1) / x;
		if (a < m):
			sys.stdout.write("Not found\n")
			continue
		else:
			c = math.floor(a)
			if (c <= m):
				c = math.ceil(a)
				if (c <= m): 
					sys.stdout.write("Not found\n")
					continue
			if ((m-1) - (c * x) > EPSILON):
				while ((m-1) - (c * x) >= EPSILON): # Under estimate
					c += 1
				c -= 1
				#print("%d, Under estimate" % c)
			if ((m-1) - (c * x) > EPSILON  and c - m > EPSILON): # Over estimate
				while ((c * x) - (m-1) >= EPSILON):
					c -= 1
				c += 1
				#print("%d,Over estimate" % c)
			c -= 1


		sys.stdout.write("%d\n" % c)



if __name__ == '__main__':
	main()