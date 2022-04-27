#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

class Group {
public:
	Group();

	Group(const std::vector<int> vect);

	~Group() = default;

	// Return a copy of the vector
	const std::vector<int> getVect() const;

private:
	// Hold the group
	std::vector<int> m_group;

	// Read input from user, sort and remove duplictes
	void readInput();
};

std::ostream& operator<<(std::ostream&, const Group&);