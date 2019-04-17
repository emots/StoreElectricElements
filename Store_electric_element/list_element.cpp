#include<iostream>

#include "list_elements.h"


List::List()
{
	_size = 0;
	head = tail = NULL;
}
int List::size()
{
	if (_size != 0)
		return _size;
	else
		return 0;
}

int List::isEmpty()
{
	if (_size == 0)
	{
		return 0;
	}
	else
		return 1;
}

void List::push_front(int _number, component _kind, int _capacity, mes_unit _mer, char*_country, float _price)
{
	Element *node = new Element(_number, _kind, _capacity, _mer, _country, _price);
	if (_size == 0)
	{
		head = tail = node;
	}
	else
	{
		node->next = head;
		head->prev = node;
		node->prev = tail;
		head = node;
	}
	_size++;
}

void List::push_back(int _number, component _kind, int _capacity, mes_unit _mer, char*_country, float _price)
{
	Element *node = new Element(_number, _kind, _capacity, _mer, _country, _price);
	if (_size == 0)
	{
		tail = head = node;
	}
	else
	{
		node->prev = tail;
		tail->next = node;
		node->next = head;
		tail = node;
	}
	_size++;
}

void List::peek_front()
{
	if (_size == 0)
	{
		std::cout << 0;
	}
	else
		head->storage->print_info();
}

void List::peek_back()
{
	if (_size == 0)
	{
		std::cout << 0;
	}
	else
		tail->storage->print_info();
}

void List::peek_anyWhere(int n)
{
	Element *tmp = head;
	if (_size == 0)
	{
		std::cout << 0;
	}
	else
	{
		if (n <= _size)
		{
			for (int i = 0; i < n; i++)
			{
				tmp = tmp->next;
			}
			tmp->storage->print_info();
		}
		else
			std::cout << 0;
	}
}

void List::search_element(enum component comp, int _start_value, int _end_value)
{
	Element *tmp = head;
	if (_size == 0)
	{
		std::cout << 0;
	}
	else
	{
		std::string name;
		bool has_elem = true;

		switch (comp)
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
			has_elem = false;
			break;
		}
		if (has_elem)
		{
			for (int i = 0; i < _size; i++)
			{
				if ((!name.compare(tmp->storage->get_kind())) &&
					(tmp->storage->get_capacity() > _start_value) &&
					(tmp->storage->get_capacity() < _end_value))
				{
					tmp->storage->print_info();
				}
				tmp = tmp->next;
			}
		}
		else
		{
			std::cout << "No such element!" << std::endl;
		}

	}
}

void List::delete_first_element()
{
	element *value;
	if (_size == 0)
	{
		std::cout << 0;
	}
	else
	{
		value = head->storage;

		if (!isDestruct)
		{
			value->print_info();
		}

		if (_size == 1)
		{
			delete head->storage;
			delete head;
			head = tail = NULL;
		}
		else
		{
			Element *tmp = head;
			head = tmp->next;
			head->prev = tail;
			tail->next = head;
			delete value;
			delete tmp;
		}
		_size--;
	}
}

void List::delete_last_element()
{
	element* value;

	if (_size == 0)
	{
		std::cout << 0;
	}
	else
	{
		value = tail->storage;

		if (!isDestruct)
		{
			value->print_info();
		}

		if (_size == 1)
		{
			delete tail;
			tail = head = NULL;
		}
		else
		{
			Element *tmp = tail;
			tail = tmp->prev;
			tail->next = head;
			head->prev = tail;
			delete value;
			delete tmp;

		}
		_size--;

	}
}

void List::delete_element(int n)
{
	element* value;

	Element *tmp = head;
	Element *tmp1, *tmp2;

	if (_size == 0)
	{
		std::cout << 0;
	}
	else if (n == 1)
	{
		delete_first_element();
	}
	else if (n == 2)
	{
		delete_last_element();
	}
	else
	{
		if (n <= _size)
		{
			for (int i = 0; i < n; i++)
			{
				tmp = tmp->next;
			}
			tmp1 = tmp->prev;
			tmp2 = tmp->next;
			tmp1->next = tmp2;
			tmp2->prev = tmp1;
			value = tmp->storage;
			delete value;
			delete tmp;
			_size--;
		}
		else
			std::cout << 0;
	}
}

void List::get_elem_to_write(int n, std::string name)
{
	Element *tmp = head;
	if (_size == 0)
	{
		std::cout << 0;
	}
	else
	{
		if (n <= _size)
		{
			for (int i = 0; i < n; i++)
			{
				tmp = tmp->next;
			}
			tmp->storage->write_to_file(name);
		}
		else
			std::cout << 0;
	}
}

void List::clean_list()
{
	Element *node;

	while (isEmpty())
	{
		node = head;
		head = head->next;
		delete node->storage;
		delete node;
		--_size;
	}
	_size = 0;
	head = tail = NULL;
}

List::~List()
{
	std::cout << "destruct list!" << std::endl;
	isDestruct = true;
	while (isEmpty())
	{
		delete_first_element();
	}
	_size = 0;
	delete head;
	delete tail;
	isDestruct = false;
}