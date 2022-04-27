#include "Calculator.h"

Calculator::Calculator() {
	// Add first three basic operations
	m_actions.push_back(std::make_shared<Uni>());
	m_actions.push_back(std::make_shared<Inter>());
	m_actions.push_back(std::make_shared<Diff>());
}

void Calculator::run() {
	int action1, action2;
	std::ostringstream oss;
	std::string input;
	printMenu();
	std::cin >> input;

	while (input != "exit") {
		
		if (input == "uni" || input == "inter" || input == "diff" || input == "prod" || input == "comp") {
			if (!readInput(&action1, &action2))
				std::cout << "Invalid combination!\n";
			else 
				addAction(input, action1, action2);
		}

		else if (input == "eval" || input == "del") {
			int choice;
			std::cin >> choice;

			if (choice >= m_actions.size() || choice < 0)
				std::cout << "Operation #" << choice << " doesn't exist\n";

			else if (input == "eval") {
				auto res = m_actions[choice]->eval(&oss, std::vector<int>());
				oss << " = " << res;
				std::cout << oss.str() << std::endl;
				oss.str("");
				oss.clear();
			}
			else {
				m_actions.erase(m_actions.begin() + choice);
			}
		}

		else if (input == "help")
			help();

		else
			std::cout << "Command not found\n";

		printMenu();
		std::cin >> input;

	}
	std::cout << "Goodbye :)\n";
}

void Calculator::printMenu() {
	int count;
	std::cout << std::endl;
	std::cout << "List of available set operations: \n";
	for (int i = 0; i < m_actions.size(); i++) {
		std::cout << i << ".		";
		count = 0;
		m_actions[i]->printAction(&count);
		std::cout << std::endl;
	}

	std::cout << "Enter command ('help' for the list of available commands): ";
}

bool Calculator::readInput(int* choice1, int* choice2) {
	std::cin >> (*choice1) >> (*choice2);
	if (*choice1 < 0 || *choice1 >= m_actions.size() || *choice2 < 0 || *choice2 >= m_actions.size())
		return false;
	return true;
}

void Calculator::addAction(std::string input, int act1, int act2) {
	if(input == "uni")
		m_actions.push_back(std::make_shared<Uni>(m_actions[act1], m_actions[act2]));
	
	else if(input == "inter")
		m_actions.push_back(std::make_shared<Inter>(m_actions[act1], m_actions[act2]));

	else if(input == "diff")
		m_actions.push_back(std::make_shared<Diff>(m_actions[act1], m_actions[act2]));

	else if(input == "prod")
		m_actions.push_back(std::make_shared<Prod>(m_actions[act1], m_actions[act2]));

	else
		m_actions.push_back(std::make_shared<Comp>(m_actions[act1], m_actions[act2]));
}

void Calculator::help() {
	std::cout << "The available commands are:\n\
		* eval(uate) num ... - compute the result of function #num on the following\n\
		set(s); each set is prefixed with the count of numbers to read\n\
		* uni(on) num1 num2 - Creates an operation that is the union of operation\n\
		#num1 and operation #num2\n\
		* inter(section) num1 num2 - Creates an operation that is the intersection\n\
		of operation #num1 and operation #num2\n\
		* diff(erence) num1 num2 - Creates an operation that is the difference of\n\
		operation #num1 and operation #num2\n\
		* prod(uct) num1 num2 - Creates an operation that returns the product of\n\
		the items from the results of operation #num1 and operation #num2\n\
		* comp(osite) num1 num2 - creates an operation that is the composition of\n\
		operation #num1 and operation #num2\n\
		* del(ete) num - delete operation #num from the operation list\n\
		* help - print this command list\n\
		* exit - exit the program" << std::endl;
}