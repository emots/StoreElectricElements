#include<iostream>

#include "electronic_component.h"

//start class ELECTRONIC_COMP

electronic_comp::electronic_comp(int _number, component _kind, int _capacity, mes_unit _mer)
{
	this->number = _number;
	this->kind = _kind;
	this->capacity = _capacity;
	this->mer = _mer;

	std::cout << "Construct electronic comp.!" << std::endl;
}

electronic_comp::electronic_comp(const electronic_comp &obj)
{
	this->number = obj.number;
	this->kind = obj.kind;
	this->capacity = obj.capacity;
	this->mer = obj.mer;

	std::cout << "copy Construct electronic comp.!" << std::endl;
}

std::string electronic_comp::get_kind()
{
	std::string name;

	switch (this->kind)
	{
	case resistor:
		name = "resistor";
		break;
	case capacitor:
		name = "capacitor";
		break;
	case bobbin:
		name = "bobbin";
		break;
	default:
		break;
	}
	return name;
}

std::string electronic_comp::get_mer()
{
	std::string name;
	;
	switch (this->mer)
	{
	case om:
		name = "om";
		break;
	case pf:
		name = "pf";
		break;
	case l:
		name = "l";
		break;
	default:
		break;
	}
	return name;
}

void electronic_comp::print_info()
{
	std::cout <<
		this->get_number() << " " << this->get_kind().c_str()
		<< " " << this->get_capacity() << this->get_mer().c_str() << std::endl;
}

electronic_comp::~electronic_comp()
{
	std::cout << "Destruct elect. comp.!" << std::endl;
}
//end ELECTRONIC_COMP