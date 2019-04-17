#pragma once

#include"electronic_component.h"

class element :public electronic_comp
{
private:

	char* country;
	float price;

public:
	//constructors
	element(int _number, component _kind, int _capacity, mes_unit _mer, char*_country, float _price);
	//get methods
	char* get_country() { return country; };
	float get_price() { return price; };
	//void functions
	void print_info();
	void write_to_file(std::string name);
	//friends function
	friend std::ostream &operator<<(std::ostream &os, element &el);
	friend std::ostream &operator<<(std::ostream &os, element *el);
	//destructor
	~element();
};
