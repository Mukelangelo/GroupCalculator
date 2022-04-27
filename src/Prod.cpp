#include "Prod.h"

Prod::Prod(const std::shared_ptr<Action> act1, const std::shared_ptr<Action> act2)
	: Action()
{
	m_actA = act1;
	m_actB = act2;
	m_action = " * ";
}

Group Prod::eval(std::ostringstream* oss, const std::vector<int>& vect) const {
	auto res = std::vector<int>();
	
	(*oss) << "(";
	auto a = m_actA->eval(oss, res);
	(*oss) << m_action;
	auto b = m_actB->eval(oss, res);
	(*oss) << ")";

	auto vectA = a.getVect();
	auto vectB = b.getVect();

	for (int i = 0; i < vectA.size(); i++) {
		for (int j = 0; j < vectB.size(); j++)
			res.push_back(vectA[i] * vectB[j]);
	}

	return Group(res);
}

Group Prod::eval(const std::shared_ptr<Action> act1, const std::shared_ptr<Action> act2, std::ostringstream* oss, const std::vector<int>& vect) const {
	return Group();
}