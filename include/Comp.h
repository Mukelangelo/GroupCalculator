#pragma once

#include "Action.h"

class Comp : public Action {
public:
	Comp() = default;
	
	Comp(const std::shared_ptr<Action> act1, const std::shared_ptr<Action> act2);

	virtual ~Comp() = default;

	virtual Group eval(std::ostringstream* oss, const std::vector<int>& vect) const;
	
	virtual Group eval(const std::shared_ptr<Action> act1,
						const std::shared_ptr<Action> act2,
						std::ostringstream* oss,
						const std::vector<int>& vect) const;

private:
};