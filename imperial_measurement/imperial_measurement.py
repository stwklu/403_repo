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


class UnitGraph():
	

	def __init__(self):
		self.nodes = []
		self.connection = {}
		self.formalization = {
		'th':'thou',
		'in':'inch',
		'ft':'foot',
		'ch':'chain',
		'fur':'furlong',
		'mi':'mile',
		'lea':'league'
		}

	def add_node(self, node):
		self.nodes.append(node)

	def connect(self, from_node, to_node, covertion_rate):
		self.connection[from_node] = (covertion_rate, to_node)

	def convert(self, from_node, to_node, value):
		if from_node == to_node:
			return value

		current_node = from_node
		while True:
			covertion_rate, next_node = self.connection[current_node]
			value = covertion_rate * value
			current_node = next_node
			if current_node == to_node:
				return value

	def formalizeName(self, name):
		if name in self.formalization.keys():
			return self.formalization[name]
		else:
			return name


def main():

	with sys.stdin as f:
		content = f.readlines()
	content = [x.strip() for x in content]

	unit_graph = UnitGraph()
	unit_graph.connect('inch','thou', 1000.0)
	unit_graph.connect('foot','inch', 12.0)
	unit_graph.connect('yard','foot', 3.0)
	unit_graph.connect('chain','yard', 22.0)
	unit_graph.connect('furlong','chain', 10.0)
	unit_graph.connect('mile','furlong', 8.0)
	unit_graph.connect('league','mile', 3.0)
	unit_graph.connect('thou','league', 1 / 190080000.0)

	for line in content:
		words = line.split()
		from_unit = unit_graph.formalizeName(words[1])
		to_unit = unit_graph.formalizeName(words[3])
		value = unit_graph.convert(from_unit, to_unit, float(words[0]))
		print(value)

	exit(0)


if __name__ == '__main__':
	main()



















