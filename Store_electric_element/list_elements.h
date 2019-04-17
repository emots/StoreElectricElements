#pragma once

#include"element.h"

//class LIST
class List
{
private:
	struct Element
	{
		element *storage;
		Element *next, *prev;
		Element(int _number, component _kind, int _capacity, mes_unit _mer, char*_country, float _price)
		{
			storage = new element(_number, _kind, _capacity, _mer, _country, _price);
			next = prev = NULL;
		}
	};

	int _size;
	Element *head, *tail;
	bool isDestruct = false;

public:
	//constructor
	List();
	//int functions
	int size();
	int isEmpty();
	//void functions
	//enter element
	void push_front(int _number, component _kind, int _capacity, mes_unit _mer, char*_country, float _price);
	void push_back(int _number, component _kind, int _capacity, mes_unit _mer, char*_country, float _price);
	//peek element
	void peek_front();
	void peek_back();
	void peek_anyWhere(int n);
	//search element
	void search_element(enum component comp, int _start_value, int _end_value);
	//delete element
	void delete_first_element();
	void delete_last_element();
	void delete_element(int n);
	//write to file
	void get_elem_to_write(int n, std::string name);
	//clear list
	void clean_list();
	//end void finctions
	//destruct
	~List();
};
