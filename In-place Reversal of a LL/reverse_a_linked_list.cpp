/*
	Question: Given the head of a Singly LinkedList, reverse the LinkedList. Write a function to return the new head of the reversed LinkedList.
*/
#include "list_node.h"
#include <iostream>

class reverse_a_linked_list {
private:
	list_node* head_node;

	void print_list(list_node* curr_node) {

		while (curr_node) {

			std::cout << curr_node->get_value() << " -> ";
			curr_node = curr_node->get_next();
		}

		std::cout << "NULL" << std::endl;
	}

	list_node* reverse_list() {

		list_node* curr_node = this->head_node;
		list_node* prev_node = nullptr;
		list_node* q = nullptr;

		while (curr_node) {

			q = prev_node;
			prev_node = curr_node;
			curr_node = curr_node->get_next();

			prev_node->set_next(q);
		}

		return prev_node;
	}

public:
	reverse_a_linked_list() {

		this->head_node = new list_node(2, nullptr);
		this->head_node->set_next(new list_node(4, nullptr));
		this->head_node->get_next()->set_next(new list_node(6, nullptr));
		this->head_node->get_next()->get_next()->set_next(new list_node(8, nullptr));
		this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(10, nullptr));
	}

	void print_reversed_list() {

		std::cout << "Original Linked List: " << std::endl;
		this->print_list(this->head_node);
		std::cout << "Reversed Linked List: " << std::endl;
		this->print_list(this->reverse_list());
	}
};