/*
	Question: Given the head of a Singly LinkedList, write a method to return the middle node of the LinkedList.
			  If the total number of nodes in the LinkedList is even, return the second middle node.

	Brute force: Count the number of nodes and then move (# node)/2 times
	Smart way  : Use two pointers. Slow pointer move by 1 and fast pointer move by 2, when fast pointer at the end slow pointer will be at the middle
*/
#include "linked_list.h"

/*
	Time Complexity: O(n), where n is number of nodes in the list
	Space Complexity: O(1)
*/
class middle_of_ll {
private:
	list_node* head_node;

public:
	middle_of_ll() {

		this->head_node = new list_node(1, nullptr);
		this->head_node->set_next(new list_node(2, nullptr));
		this->head_node->get_next()->set_next(new list_node(3, nullptr));
		this->head_node->get_next()->get_next()->set_next(new list_node(4, nullptr));
		this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(5, nullptr));
		this->head_node->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(6, nullptr));
	}

	list_node* middle_of_the_linked_list() {

		list_node* slow_ptr = this->head_node;
		list_node* fast_ptr = this->head_node;

		do {

			slow_ptr = slow_ptr->get_next();
			fast_ptr = fast_ptr->get_next();

			if (fast_ptr) {
				fast_ptr = fast_ptr->get_next();
			}

		} while (fast_ptr);

		return slow_ptr;
	}
};