#! /usr/bin/python3
'''
/*
* Created by Steven Weikai Lu on 2018/01/15
* 
* Kattis problem: <kattis_metaprogramming>
*
* Topic: others
*
* Level: simple
* 
* Brief problem description: 
*Input
* - Input 
*	consists of one command per line, up to 1000010000 commands, ending at end of file.
* 	A definition command has the form define i x, where i is an integer in the range [−10000,10000][−10000,10000] 1
* 	and x is a string of up to 2020 lowercase alphabet characters (a–z).
*	A comparison command has the form eval x y z, where
*	x and z are strings of the same format as in definitions, and y is one of <<, >>, or ==.
*
* - Output
* 	For each definition, use the string as a label for the given integer,
*	but don’t output anything. Redefinitions are allowed.
*	For each comparison, state whether it is true or false, depending on the current definitions.
*	If the result is not known, output ‘undefined’.
* 
*
* Solution Summary:]
* - simply parse input and store label and value to a dictionary
* - depending on the comparision required output boolean
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















