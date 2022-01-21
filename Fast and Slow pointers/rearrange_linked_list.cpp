/*
	Question: Given the head of a Singly LinkedList, write a method to modify the LinkedList such that the nodes from the second half of the LinkedList
			  are inserted alternately to the nodes from the first half in reverse order.

	Input: 2 -> 4 -> 6 -> 8 -> 10 -> 12 -> null
	Ouput: 2 -> 12 -> 4 -> 10 -> 6 -> 8 -> null 
*/
#include "linked_list.h"
#include <iostream>
using std::cout;
using std::endl;

class rearrange_linked_list {
private:
	list_node* head_node;

	list_node* find_middle_node() {
		
		list_node* slow_ptr = this->head_node;
		list_node* fast_ptr = this->head_node;

		while (fast_ptr != nullptr && fast_ptr->get_next() != nullptr) {
			
			slow_ptr = slow_ptr->get_next();
			fast_ptr = fast_ptr->get_next()->get_next();
		}

		return slow_ptr;
	}

	list_node* reverse_linked_list(list_node* middle_node) {

		list_node* curr = middle_node;
		list_node* prev = nullptr;
		list_node* q = nullptr;

		while (curr != nullptr) {

			q = prev;
			prev = curr;
			curr = curr->get_next();

			prev->set_next(q);
		}

		return prev;
	}

	void re_arrange_linked_list_() {

		list_node* middle_node = find_middle_node();
		list_node* second_half = reverse_linked_list(middle_node);

		list_node* first_half = this->head_node;
		list_node* first_half_next = first_half->get_next();
		list_node* second_half_next = second_half->get_next();

		// becase second half next going to be end up at nullptr in both even and odd cases
		while (second_half_next != nullptr) {

			// adding the node from the current second half infront of the current first half node
			first_half->set_next(second_half);
			// set current second half nodes next to the node infront of the current first half node
			second_half->set_next(first_half_next);
			// move first half and second half pointers to the next node
			first_half = first_half_next;
			second_half = second_half_next;
			// move first half next and second half next to the next node
			first_half_next = first_half_next->get_next();
			second_half_next = second_half_next->get_next();
		}
	}

	void print_list(list_node* start_node) {

		list_node* curr = start_node;

		while (curr != nullptr) {

			cout << curr->get_value() << " -> ";
			curr = curr->get_next();
		}

		cout << "NULL" << endl;
	}

public:
	rearrange_linked_list() {

		this->head_node = new list_node(1, nullptr);
		this->head_node->set_next(new list_node(2, nullptr));
		this->head_node->get_next()->set_next(new list_node(3, nullptr));
		this->head_node->get_next()->get_next()->set_next(new list_node(4, nullptr));
		this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(5, nullptr));
		this->head_node->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(6, nullptr));
	}

	rearrange_linked_list(bool even_linked_list) {

		if (even_linked_list) {

			this->head_node = new list_node(1, nullptr);
			this->head_node->set_next(new list_node(2, nullptr));
			this->head_node->get_next()->set_next(new list_node(3, nullptr));
			this->head_node->get_next()->get_next()->set_next(new list_node(4, nullptr));
			this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(5, nullptr));
			this->head_node->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(6, nullptr));
		}
		else {

			this->head_node = new list_node(2, nullptr);
			this->head_node->set_next(new list_node(4, nullptr));
			this->head_node->get_next()->set_next(new list_node(6, nullptr));
			this->head_node->get_next()->get_next()->set_next(new list_node(8, nullptr));
			this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(10, nullptr));
		}
	}

	void re_arrange_linked_list() {

		this->re_arrange_linked_list_();
		this->print_list(this->head_node);
	}

};