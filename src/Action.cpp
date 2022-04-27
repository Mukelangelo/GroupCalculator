#include "Action.h"

std::shared_ptr<Action> Action::getActA() const {
	return m_actA;
}

std::shared_ptr<Action> Action::getActB() const {
	return m_actB;
}

// Recursivly print the action with different group names
void Action::printAction(int* count) const {
	char groupName = 'A' + (*count);

	if (m_actA == nullptr && m_actB == nullptr)
		std::cout << "(" << groupName++ << m_action << groupName++ << ")";
	else {
		std::cout << "(";
		m_actA->printAction(count);
		std::cout << ") " << m_action << " (";
		(*count) += 2;
		m_actB->printAction(count);
		std::cout << ")";
	}
}