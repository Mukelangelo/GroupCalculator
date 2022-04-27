#pragma once

#include "Action.h"

class Uni: public Action {
public:
	Uni();

	Uni(const std::shared_ptr<Action> act1, const std::shared_ptr<Action> act2);

	virtual ~Uni() = default;

	virtual Group eval(std::ostringstream* oss, const std::vector<int>& vect) const;

	virtual Group eval(const std::shared_ptr<Action> act1,
						const std::shared_ptr<Action> act2,
						std::ostringstream* oss,
						const std::vector<int>& vect) const;

private:
};