

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <stack>

using namespace std;

struct Token{
	string type;
	int number;
	char variable;
	char op;
	char l_parenthese;
	char r_parenthese;
};

void printTokenVector(vector<Token> &equation){
	for (Token token : equation){
		if (token.type == "number"){
			cout << token.number;
		}
		else if (token.type == "variable"){
			cout << token.variable;
		}
		else if (token.type == "l_parenthese"){
			cout << token.l_parenthese;
		}
		else if (token.type == "r_parenthese"){
			cout << token.r_parenthese;
		}
		else if (token.type == "op"){
			cout << token.op;
		}
	}
	cout << "" << endl;
}

void toPostFix(vector<Token> &equation, vector<Token> &output){
	stack<Token> placeholder;
	for (Token token : equation){
		if((token.type == "number") || (token.type == "variable")){
			if (token.type == "number"){
				cout << "find a number" << token.number << endl;
			}
			else{
				cout << "find a number" << token.variable << endl;
			}
			
			output.push_back(token);
		}
		if (token.type == "l_parenthese"){
			cout << "find a left parenthese" << endl;
			placeholder.push(token);
		}
		if (token.type == "r_parenthese"){
			cout << "find a right parenthese" << endl;
			while((placeholder.top().type != "l_parenthese") && (!placeholder.empty())){
				output.push_back(placeholder.top());
				placeholder.pop();
			}
			placeholder.pop();
		}
		if (token.type == "op"){
			cout << "find a operator" << token.op << endl;
			Token latest;
			if(placeholder.empty()){
				output.push_back(token);
			}
			else if (placeholder.top().type == "l_parenthese"){
				output.push_back(token);
			}
			else{
				while(true){
					if(placeholder.empty()){break;}
					if(placeholder.top().type == "l_parenthese"){break;}
					output.push_back(placeholder.top());
					placeholder.pop();
				}
				placeholder.push(token);
			}
		}
	}
	while(!placeholder.empty()){
		output.push_back(placeholder.top());
		placeholder.pop();
	}

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


int main(){
	//map<char, int> values;
	//map<string, int> changes;
	for (string line; getline(std::cin, line);){
		if (line == "#"){
			break;
		}

		vector<Token> equation;
		vector<Token> postfix;
		toVector(line, equation);
		toPostFix(equation, postfix);
		printTokenVector(postfix);

		
	}
	return(0);
}