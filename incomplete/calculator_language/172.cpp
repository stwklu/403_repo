/*
Created by Steven Weikai Lu on 2018/01/16
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

struct Token{
	string type;
	int number;
	char variable;
	char op;
	char l_parenthese;
	char r_parenthese;
};

struct  Node{
	string type;
	Token token;
	bool leaf;
	int value;
	vector<Node> children;
	//Node* parent;
};

void toVector(string &equation, vector<Token> &placeholder);
int binaryCalculationNode(Node node1, Node op_node, Node node2, map<char, int> &values);
int binaryCalculationInt(Node node1, Node op_node, int number, map<char, int> &values);
int evaluate(Node head, map<char, int> &values);
void buildComputationalGraph(vector<Token> &equation, Node &head);

void buildComputationalGraph(vector<Token> &equation, Node &head){
	int i = 0;
	while (i < equation.size()){
		Token token = equation[i];
		Node node;
		// Send entire out-most parenthese to a subgraph node
		if (token.type == "l_parenthese"){
			//cout << "subgraph extented" << endl;
			i++;
			int paren_layer = 0;
			vector<Token> children;
			while(!((paren_layer == 0) && (equation[i].type == "r_parenthese"))){
				//cout << equation[i].type << " ";
				if (equation[i].type == "l_parenthese"){
					paren_layer++;
					children.push_back(equation[i]);
				}
				else if (equation[i].type == "r_parenthese"){
					paren_layer--;
				}
				children.push_back(equation[i]);
				i++;
			}
			i++;
			//cout << "in the subgraph" << endl;
			//node.parent = &head;
			node.leaf = false;
			node.type = "subgraph";
			buildComputationalGraph(children, node);
		}
		// Convert token into a leaf node
		else{
			node.type = "token";
			node.token = token;
			node.leaf = true;
			//node.parent = &head;
			i++;
		}
		head.children.push_back(node);
	}
}

int evaluate(Node head, map<char, int> &values){


	// Leaf node
	if (head.leaf){
		cout << "evaluating a leaf node" <<endl;
		if(head.type == "variable"){
			return(values[head.token.variable]);
		}
		else{
			return(head.token.number);
		}
	}

	// at least 3 children
	Token operand1, operand2;
	int total;
	// Evaluate from end since right associative
	int i = head.children.size() - 1;
	// Evaluate the last two operand
	Node node1 = head.children[i-2];
	Node op_node = head.children[i-1];
	Node node2 = head.children[i];
	i -= 3;
	total = binaryCalculationNode(node1, op_node, node2, values);


	while (i > 0)
	{
		node1 = head.children[i-1];
		op_node = head.children[i];
		total = binaryCalculationInt(node1, op_node, total, values);
	}

	return(total);

}
int binaryCalculationInt(Node node1, Node op_node, int number, map<char, int> &values){
	// Deal with variable assignment
	if (op_node.token.op == '='){
		values[node1.token.variable] = number;
		return number;
	}

	int value, operand1;
	char op = op_node.token.op;
	// Deal with intermediate node
	if (!(node1.leaf)){
		operand1 = evaluate(node1, values);
	}

	// Deal with leaf variable
	else if (node1.token.type == "variable"){
		operand1 = values[node1.token.variable];
	}
	// Deal with leaf number
	else{operand1 = op_node.token.number;}

	// Arithmetic
	switch(op){
		case '+':
			value = operand1 + number;
			break;
		case '-':
			value = operand1 - number;
			break;
		case '*':
			value = operand1 * number;
			break;
		case '/':
			value = operand1 / number;
			break;
	}
	return value;
}

int binaryCalculationNode(Node node1, Node op_node, Node node2, map<char, int> &values){
	int value, operand1, operand2;
	char op = op_node.token.op;

	operand2 = evaluate(node2, values);

	// Deal with variable assignment
	if (op_node.token.op == '='){
		values[node1.token.variable] = operand2;
		return operand2;
	}

	// Deal with intermiediate node
	if (!(node1.leaf)){
		operand1 = evaluate(node1, values);
	}
	// Deal with leaf variable
	else if (node1.token.type == "variable"){
		operand1 = values[node1.token.variable];
	}
	// Deal with leaf number
	else{
		operand1 = op_node.token.number;
	}

	// Arithmetic
	switch(op){
	case '+':
		value = operand1 + operand2;
		break;
	case '-':
		value = operand1 - operand2;
		break;
	case '*':
		value = operand1 * operand2;
		break;
	case '/':
		value = operand1 / operand2;
		break;
	}
	return value;
}

void toVector(string &equation, vector<Token> &placeholder){
	equation.erase(remove(equation.begin(), equation.end(), ' '), equation.end());
	int i = 0;
	while(i < equation.length()){
		// negative number
		if (equation[i] == '_'){
			i++;
			string num_char = "-";
			while (isdigit(equation[i])){
				num_char += equation[i];
				i++;
			}
			int number = stoi(num_char);
			Token token = Token();
			token.type = "number";
			token.number = number;
			placeholder.push_back(token);
		}
		// number
		else if (isdigit(equation[i])){
			string num_char = "";
			while (isdigit(equation[i])){
				num_char += equation[i];
				i++;
			}
			int number = stoi(num_char);
			Token token = Token();
			token.type = "number";
			token.number = number;
			placeholder.push_back(token);
		}
		// variable
		else if (isalpha(equation[i])){
			char variable = equation[i];
			Token token = Token();
			token.type = "variable";
			token.variable = variable;
			placeholder.push_back(token);
			i++;
		}
		// parenthese
		else if (equation[i] == '('){
			char parenthese = equation[i];
			Token token = Token();
			token.type = "l_parenthese";
			token.l_parenthese = parenthese;
			placeholder.push_back(token);
			i++;
		}
		else if (equation[i] == ')'){
			char parenthese = equation[i];
			Token token = Token();
			token.type = "r_parenthese";
			token.r_parenthese = parenthese;
			placeholder.push_back(token);
			i++;
		}
		// operator
		else{
			char op = equation[i];
			Token token = Token();
			token.type = "op";
			token.op = op;
			placeholder.push_back(token);
			i++;
		}
	}
}

void printNode(Node node){
	if (node.leaf){
		if (node.token.type == "number"){
			cout << node.token.number << " ";
		}
		else if (node.token.type == "variable"){
			cout << node.token.variable << " ";
		}
		else if (node.token.type == "op"){
			cout << node.token.op << " ";
		}
	}
	if (node.children.size()){
		cout << "subgraph:";
		for (Node child : node.children){
			printNode(child);
		}
		cout << "end" << endl;
	}
}

int main(){
	map<char, int> values;
	map<char, int> changes;
	for (string line; getline(std::cin, line);){
		if (line == "#"){
			break;
		}

		//cout << line << endl;
		vector<Token> equation;
		toVector(line, equation);

		Node head;
		buildComputationalGraph(equation, head);
		//evaluate(head, changes);
		printNode(head);
		cout << "" << endl;
		cout << "" << endl;

		
	}
	return(0);
}



















