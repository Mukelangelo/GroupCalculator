#pragma once

#include <iostream>
#include <vector>
#include "Group.h"
#include "Action.h"
#include "Uni.h"
#include "Inter.h"
#include "Diff.h"
#include "Prod.h"
#include "Comp.h"

class Calculator {
public:
	Calculator();

	// Run the calculator
	void run();
	
	// Print the help menu
	void help();

private:
	// Store the actions of the calculator
	std::vector<std::shared_ptr<Action>> m_actions;

	// Print the list of actions available
	void printMenu();
	
	// Read input from user
	bool readInput(int* choice1, int* choice2);

	//Add action to the calculator
	void addAction(std::string input, int act1, int act2);
};