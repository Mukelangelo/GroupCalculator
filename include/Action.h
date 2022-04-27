#pragma once

#include <memory>
#include <algorithm>
#include "Group.h"
#include <sstream>

class Action{
public:
	virtual ~Action() = default;

	// Evaluate a basic operation
	virtual Group eval(std::ostringstream* oss, const std::vector<int>& vect) const = 0;
	
	// Evaluate a combination of operations
	virtual Group eval(const std::shared_ptr<Action> act1,
						const std::shared_ptr<Action> act2,
						std::ostringstream* oss,
						const std::vector<int>& vect) const = 0;

	// Get the left action of a complex operation
	std::shared_ptr<Action> getActA() const;

	// Get the right action of a complex operation
	std::shared_ptr<Action> getActB() const;

	void printAction(int* count) const;

protected:
	// Store the actions
	std::shared_ptr<Action> m_actA = nullptr;
	std::shared_ptr<Action> m_actB = nullptr;

	// Store the action sign
	std::string m_action = "";

};