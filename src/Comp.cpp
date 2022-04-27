#include "Comp.h"

Comp::Comp(const std::shared_ptr<Action> act1, const std::shared_ptr<Action> act2)
	: Action()
{
	m_actA = act1;
	m_actB = act2;
	m_action = "->";
}

Group Comp::eval(std::ostringstream* oss, const std::vector<int>& vect) const {
	auto a = m_actA->eval(oss, vect);
	(*oss) << " -> ";
	auto b = m_actB->eval(oss, a.getVect());
	
	return b;
}


Group Comp::eval(const std::shared_ptr<Action> act1, const std::shared_ptr<Action> act2, std::ostringstream* oss, const std::vector<int>& vect) const {
	return Group();
}