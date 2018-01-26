#! /usr/bin/python3
'''
/*
* Created by Steven Weikai Lu on 2018/01/15
* 
* Kattis problem: <4thought>
*
* Topic: arithmetic
*
* Level: simple
* 
* Brief problem description: 
* Write a program which, given an integer nn as input, will produce a mathematical expression whose solution is nn.
* The solution is restricted to using exactly four 44’s and exactly three of the binary operations selected from the set {∗,+,−,/}{∗,+,−,/}.
* The number 44 is the ONLY number you can use. 
* You are not allowed to concatenate fours to generate other numbers, such as 4444 or 444444.
* For example given n=0, a solution is 4∗4−4∗4=04∗4−4∗4=0. Given n=7n=7, a solution is 4+4−4 / 4=74+4−4 / 4=7. Division is considered truncating integer division, so that 1/41/4 is 00 (instead of 0.250.25). Assume the usual precedence of operations so that 4+4∗4=204+4∗4=20, not 3232. Not all integer inputs have solutions using four 44’s with the aforementioned restrictions (consider n=11n=11).
* 
*
* Solution Summary:
* - Treat multiplcation and division as strong unit compute first
* - Treat addition and subtraction as weak unit, compute after strong unit
* - Then just exhaustic search...
* 
*
* Used Resources:
* -StackOverflow
*
* I hereby certify that I have produced the following solution myself
* using only the resources listed above in accordance with the CMPUT
* 403 collaboration policy.
*
* --------------------- (Steven Weikai Lu)
*/
'''

import sys, operator

def create_strong_units():
	strong_unit_3 = [
	(['*','*','*'],256),
	(['/','/','/'],0),
	(['*','*','/'],16),
	(['*','/','/'],1)
	]

	strong_unit_2 = [
	(['*','*'],64),
	(['*','/'],4),
	(['/','/'],0),
	]

	strong_unit_1 = [
	(['*'],16),
	(['/'],1)
	]

	strong_unit = [strong_unit_1, strong_unit_2, strong_unit_3]

	return strong_unit


def solve(integer):
	strong_unit = create_strong_units()
	
	for combo in strong_unit[2]:
		if combo[1] == integer:
			return True, combo[0]

	for combo in strong_unit[0]:
		solved, operators = add_weak_1(integer, combo, strong_unit[0])
		if solved:
			return True, operators

	for combo in strong_unit[1]:
		solved, operators = add_weak_2(integer, combo)
		if solved:
			return True, operators

	return False, operators


def add_weak_2(target, combo):
	if combo[1] + 4 == target:
		return True, combo[0]+['+']
	elif combo[1] - 4 == target:
		return True, combo[0]+['-']
	elif 4 - combo[1] == target:
		return True, ['-'] + combo[0]
	
	return False, None


def add_weak_1(target, combo, strong_unit):
	for unit in strong_unit:
		if unit[1] + combo[1] == target:
			return True, unit[0] + ['+'] + combo[0]
		if unit[1] - combo[1] == target:
			return True, unit[0] + ['-'] + combo[0]
		if combo[1] - unit[1] == target:
			return True, combo[0] + ['-'] + unit[0]

	if combo[1] == target:
		return True, combo[0]+['+', '-']
	elif combo[1] + 8 == target:
		return True, combo[0]+['+', '+']
	elif combo[1] - 8 == target:
		return True, combo[0]+['-', '-']
	elif combo[1] == -target:
		return True, ['-', '-'] + combo[0]
	elif 8 - combo[1] == target:
		return True, ['+', '-'] + combo[0]

	return False, None


def main():
	with sys.stdin as f:
		content = f.readlines()
	content = [int(x.strip()) for x in content]

	length = content.pop(0)
	for i in range(length):
		solved, operators = solve(content[i])
		if solved:
			print('4',operators[0],'4',operators[1],'4',operators[2],'4 =', content[i])
		else:
			print('no solution')


	exit(0)


if __name__ == '__main__':
	main()