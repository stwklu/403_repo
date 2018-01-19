#! /usr/bin/python3
'''
Created by Steven Weikai Lu on 2018/01/16

Problem title:
problem site: 
'''
import sys

def main():

	with sys.stdin as f:
		content = f.readlines()
	#content = [x.strip() for x in content]
	for line in content:
		parsed = eval(line)
		print(line)


	exit(0)


if __name__ == '__main__':
	main()
