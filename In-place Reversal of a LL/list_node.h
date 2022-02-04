#pragma once
/*
	Definition for the list node
*/
class list_node {

private:
	int value;
	list_node* next;

public:
	list_node() {

		this->value = 0;
		this->next = nullptr;
	}

	list_node(int value, list_node* next) {

		this->value = value;
		this->next = next;
	}

	void set_next(list_node* next) {

		this->next = next;
	}

	list_node* get_next() {

		return this->next;
	}

	int get_value() {

		return this->value;
	}
};
