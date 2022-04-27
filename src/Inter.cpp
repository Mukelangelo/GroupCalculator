#include "Inter.h"

Inter::Inter()
	:Action()
{
	m_action = " ^ ";
}

Inter::Inter(const std::shared_ptr<Action> act1, const std::shared_ptr<Action> act2)
	: Action()
{
	m_actA = act1;
	m_actB = act2;
	m_action = " ^ ";
}

Group Inter::eval(std::ostringstream* oss, const std::vector<int>& vect) const {
	auto res = std::vector<int>();

	if (m_actA == nullptr && m_actB == nullptr) {
		auto a = (!vect.empty()) ? Group(vect) : Group();
		auto b = Group();

		(*oss) << "(" << a << m_action << b << ")";
		std::ranges::set_intersection(a.getVect(), b.getVect(), std::back_inserter(res));
	}
	else {
		return (!vect.empty()) ? eval(m_actA, m_actB, oss, vect) : eval(m_actA, m_actB, oss, res);
	}

	return Group(res);
}

Group Inter::eval(const std::shared_ptr<Action> act1, const std::shared_ptr<Action> act2, std::ostringstream* oss, const std::vector<int>& vect) const {
	auto res = std::vector<int>();
	
	(*oss) << "(";
	auto a = (!vect.empty()) ? m_actA->eval(oss, vect) : m_actA->eval(oss, res);
	(*oss) << m_action;
	auto b = m_actB->eval(oss, res);
	(*oss) << ")";

	
	std::ranges::set_intersection(a.getVect(), b.getVect(), std::back_inserter(res));

	return Group(res);
}