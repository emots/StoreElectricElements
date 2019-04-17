
#include <iostream>
#include "list_elements.h"

int main()
{
	electronic_comp ec1(1, resistor, 200, om);
	ec1.print_info();
	element el1(2, capacitor, 10, pf, "bulgaria", 3.5);
	el1.print_info();
	std::cout << el1 << std::endl;
	el1.write_to_file("elements");

	List *dek = new List();
	dek->push_front(2, capacitor, 10, pf, "bulgaria", 3.5);
	dek->push_back(1, resistor, 200, om, "bulgaria", 4.5);
	dek->push_back(1, resistor, 200, om, "bulgaria", 4.5);

	dek->search_element(resistor, 100, 300);
	dek->get_elem_to_write(2, "elements");


	delete dek;

	std::cin.get();
}