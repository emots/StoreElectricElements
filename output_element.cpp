#include<iostream>
#include "element.h"

//overwride <<
std::ostream &operator<<(std::ostream &os, element &el)
{
	os <<
		el.get_number() << " " << el.get_kind().c_str() << " " <<
		el.get_capacity() << el.get_mer().c_str() << " " <<
		el.get_country() << " " << el.get_price();
	return os;
}

std::ostream &operator<<(std::ostream &os, element *el)
{
	os <<
		el->get_number() << " " << el->get_kind().c_str() << " " <<
		el->get_capacity() << el->get_mer().c_str() << " " <<
		el->get_country() << " " << el->get_price();
	return os;
}
