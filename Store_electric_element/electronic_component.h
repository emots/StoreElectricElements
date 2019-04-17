#pragma once
#include<string>

enum component { resistor, capacitor, bobbin };
enum mes_unit { pf, om, l };

//class ELECTRONIC_COMP
class electronic_comp
{
private:
	int number;
	component kind;
	int capacity;
	mes_unit mer;

public:
	//constructors
	electronic_comp(int _number, component _kind, int _capacity, mes_unit _mer);
	electronic_comp(const electronic_comp &obj);
	//get methods
	int get_number() { return number; };
	std::string get_kind();
	int get_capacity() { return capacity; };
	std::string get_mer();
	//void function
	void print_info();
	//destruct
	~electronic_comp();
};
