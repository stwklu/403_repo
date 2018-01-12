#! /usr/bin/python3
'''
4 thought

problem site: https://open.kattis.com/problems/4thought

CPU Time limit: 1 second
Memory limit: 1024 MB
Difficulty: 2.7
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