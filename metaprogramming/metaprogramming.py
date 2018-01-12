#! /usr/bin/python3
'''
Metaprogramming

problem site: https://open.kattis.com/problems/metaprogramming

Difficulty: 2.8
CPU Time limit: 4 seconds
Memory limit: 1024 MB
'''
import sys

def parseInput(line, labels):
	words = line.split(' ')
	if words[0] == 'define':
		update_label(labels, words[2], words[1])
	elif words[0] == 'eval':
		evaluate(words[1], words[3], words[2], labels)


def update_label(labels, key, value):
	labels[key] = int(value)

def evaluate(key_1, key_2, operand, labels):
	if not key_1 in labels.keys():
		print('undefined')
		return
	elif not key_2 in labels.keys():
		print('undefined')
		return

	if operand == '>':
		print(str(bool(labels[key_1] > labels[key_2])).lower())
	elif operand == '=':
		print(str(bool(labels[key_1] == labels[key_2])).lower())
	elif operand == '<':
		print(str(bool(labels[key_1] < labels[key_2])).lower())


def main():

	with sys.stdin as f:
		content = f.readlines()
	content = [x.strip() for x in content]

	labels = {}

	for line in content:
		parseInput(line, labels)

	del labels, content

	exit(0)


if __name__ == '__main__':
	main()















