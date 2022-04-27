#include "Group.h"

Group::Group() {
	readInput();
}

Group::Group(const std::vector<int> vect) {
	for (int i = 0; i < vect.size(); i++)
		m_group.push_back(vect[i]);

	std::ranges::sort(m_group);

	auto [newEnd, end] = std::ranges::unique(m_group);
	m_group.erase(newEnd, end);
}

void Group::readInput() {
	int size,
		val;

	std::cin >> size;
	
	for (int i = 0; i < size; i++) {
		std::cin >> val;
		m_group.push_back(val);
	}

	std::ranges::sort(m_group);

	auto [newEnd, end] = std::ranges::unique(m_group);
	m_group.erase(newEnd, end);

}

const std::vector<int> Group::getVect() const {
	return m_group;
}

std::ostream& operator<<(std::ostream& os, const Group& group) {
	auto temp = group.getVect();

	os << "{ ";
	for (int i = 0; i < temp.size(); i++) {
		os << temp[i];
		if (i == temp.size() - 1)
			break;
		os << ", ";
	}
	os << " }";

	return os;
}