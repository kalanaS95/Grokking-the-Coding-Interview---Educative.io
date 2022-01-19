/*
	Question: Given the head of a Singly LinkedList, write a function to determine if the LinkedList has a cycle in it or not.
			  Extra credit: find the length of the cycle
*/

#include <iostream>
#include "linked_list.h"
using std::cout;
using std::string;
using std::endl;

/*
	Time Complexity: O(n), where n is number of nodes in the linked list
	Space Complexity: O(1)
*/
class linked_list_cycle {

private:
	list_node* head_node; 
	list_node* slow_ptr;
	list_node* fast_ptr;

public:
	linked_list_cycle() {

		this->head_node = new list_node(1, nullptr);
		this->head_node->set_next(new list_node(2, nullptr));
		this->head_node->get_next()->set_next(new list_node(3, nullptr));
		this->head_node->get_next()->get_next()->set_next(new list_node(4, nullptr));
		this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(5, nullptr));
		this->head_node->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(6, nullptr));

		this->slow_ptr = this->fast_ptr = this->head_node;
	}

	linked_list_cycle(bool make_cycle) {

		this->head_node = new list_node(1, nullptr);
		this->head_node->set_next(new list_node(2, nullptr));
		this->head_node->get_next()->set_next(new list_node(3, nullptr));
		this->head_node->get_next()->get_next()->set_next(new list_node(4, nullptr));
		this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(5, nullptr));
		this->head_node->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(6, nullptr));

		if (make_cycle) {

			this->head_node->get_next()->get_next()->get_next()->get_next()->get_next()->set_next(this->head_node
																								      ->get_next()
																									  ->get_next());
		}

		this->slow_ptr = this->fast_ptr = this->head_node;
	}

	void print_list() {

		list_node* current = this->head_node;
		while (current != nullptr) {

			cout << current->get_value() << " --> ";
			current = current->get_next();
		}

		cout << "nullptr" << endl;
	}

	bool find_cycle() {
		/*
			Following variables are defined as private class members
			s.t I can use them in the length calculation function

			list_node* slow_ptr = this->head_node;
			list_node* fast_ptr = this->head_node;
		*/
		
		while (fast_ptr != nullptr && fast_ptr->get_next() != nullptr) {

			slow_ptr = slow_ptr->get_next();
			fast_ptr = fast_ptr->get_next()->get_next();

			if (slow_ptr == fast_ptr) {

				return true;
			}
		}

		return false;
	}

	void find_cycle_length() {

		bool result = this->find_cycle();
		string output = (result) ? "Linked list contain a cycle" : "Linked list does not containt a cycle";
		cout << output << endl;

		if (result) {

			int count = 0;
			list_node* counting_ptr = this->slow_ptr;

			do {

				count++;
				counting_ptr = counting_ptr->get_next();

			} while (counting_ptr != this->slow_ptr);

			cout << "Length of the cycle is: " << count << endl <<endl;
		}
	}
};