#include "RPN.hpp"

int pop_return(std::stack<int> &st)
{
	int res = st.top();
	st.pop();
	return res;
}

bool is_operator(const std::string &str)
{
	return (str == "+" || str == "/" || str == "-" || str == "*");
}

int UseOperator(int elm1, int elm2, char option)
{
	switch (option)
	{
		case '+':
			return elm1 + elm2;
		case '-':
			return elm1 - elm2;
		case '*':
			return elm1 * elm2;
		case '/':
			return elm1 / elm2;
	}
	return 0;
}

void calculatePolishNotion(const char *input)
{
	std::stack<int> holder;
	std::stringstream ss(input);
	std::string word;
	while (!ss.eof())
	{
		int elm1;
		int elm2;
		std::getline(ss, word, ' ');
		if (word.length() != 1 || (!std::isdigit(word[0]) && !is_operator(word))){
			std::cout << "Error\n"; return ;}
		if (!is_operator(word))
			holder.push(word[0] -= 48);
		else if (holder.size() < 2){
			std::cout << "Error\n"; return ;}
		else 
		{
			elm2 = pop_return(holder);
			elm1 = pop_return(holder);
			holder.push(UseOperator(elm1, elm2, word[0]));
		}
	}
	if (holder.size() > 1){
		std::cerr << "Error\n"; return ;}
	std::cout << holder.top() << '\n';
}
