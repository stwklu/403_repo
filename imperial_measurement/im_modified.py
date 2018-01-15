#! /usr/bin/python3
'''
Problem title: Imperial Measurement

problem site: https://open.kattis.com/problems/measurement

Problem ID: measurement
CPU Time limit: 1 second
Memory limit: 1024 MB
Difficulty: 2.0

Under construction....

'''

import sys

def formalize(name1, name2):
	formalization = {
	'th':'thou',
	'in':'inch',
	'ft':'foot',
	'ch':'chain',
	'fur':'furlong',
	'mi':'mile',
	'lea':'league'
	}
	if name1 in formalization.keys():
		name1 = formalization[name1]
	if name2 in formalization.keys():
		name2 = formalization[name2]

	return name1, name2


def main():

	with sys.stdin as f:
		content = f.readlines()
	content = [x.strip() for x in content]

	degree = {
	'thou':0,
	'inch':1,
	'foot':2,
	'chain':3,
	'furlong':4,
	'mile':5,
	'league':6
	}

	up_degree_rate = {
	0:1000.0,
	1:12.0,
	2:3.0,
	3:22.0,
	4:10.0,
	5:8.0,
	6:3.0,
	}

	for line in content:
		value, from_unit, _, to_unit = line.split()
		value = float(value)
		from_unit, to_unit = formalize(from_unit, to_unit)
		degree_to_unit = degree[to_unit]
		degree_from_unit = degree[from_unit]

		# Convert from big unit to small
		while degree_to_unit - degree_from_unit < 0:
			value = value * up_degree_rate[degree_from_unit-1]
			degree_from_unit -= 1
		# Convert from small unit to big
		while degree_to_unit - degree_from_unit > 0:
			value = value / up_degree_rate[degree_from_unit+1]
			degree_from_unit += 1
		print(value)

	exit(0)


if __name__ == '__main__':
	main()



















