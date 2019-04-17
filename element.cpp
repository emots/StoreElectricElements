#include<iostream>
#include<fstream>

#include "element.h"

//start class ELEMENT

element::element(int _number, component _kind, int _capacity, mes_unit _mer, char*_country, float _price)
	:electronic_comp(_number, _kind, _capacity, _mer)
{
	country = new char[strlen(_country) + 1];
	strcpy(country, _country);

	price = _price;

	std::cout << "Construct element!" << std::endl;
}

void element::print_info()
{
	std::cout <<
		this->get_number() << " " << this->get_kind().c_str() << " " <<
		this->get_capacity() << this->get_mer().c_str() << " " <<
		this->get_country() << " " << this->get_price() << std::endl;
}

void element::write_to_file(std::string name)
{
	name.append(".txt");
	std::ofstream file(name, std::ios::app);
	if (file.is_open())
	{
		file << this << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Cann't open file!" << std::endl;
	}
}

element::~element()
{
	std::cout << "Destruct element!" << std::endl;
	delete[] country;
}
//end class ELEMENT