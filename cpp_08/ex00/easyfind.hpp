#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include "ElementNotFoundException.hpp"
#include <algorithm>

template <typename T>
typename T::iterator easyFind(T container, int element)
{
	typename T::iterator elementPosition = std::find(container.begin(),
		container.end(), element);
	if (elementPosition == container.end())
		throw ElementNotFoundException();
	return elementPosition;
}

#endif