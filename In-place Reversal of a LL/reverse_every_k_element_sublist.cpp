/*
	Question: Given the head of a LinkedList and a number ‘k’, reverse every ‘k’ sized sub-list starting from the head.
			  If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.
	Input: 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - NULL
	k : 3
	Output: 3 - 2 - 1 - 6 - 5 - 4 - 8 - 7 - NULL
*/
#include <iostream>
#include "list_node.h"

/*
	Time Complexity: O(n), where n is number nodes in the linked list
	Space Complexity: O(1)
*/
class reverse_every_k_element_sublist {
private:
	list_node* head_node;

	void print_list(list_node* current_node) {

		while (current_node) {

			std::cout << current_node->get_value() << " -> ";
			current_node = current_node->get_next();
		}

		std::cout << "NULL" << std::endl;
	}

	std::pair<list_node*,list_node*> reverse_list(list_node* current_node,int k) {

		list_node* prev_node = nullptr;
		list_node* q = nullptr;
		int curr_k = 0;
		
		while (current_node && curr_k < k) {

			q = prev_node;
			prev_node = current_node;
			current_node = current_node->get_next();

			prev_node->set_next(q);
			curr_k++;
		}

		// prev node points to the start node of the reversed sublist and current_node points to the first node of the next sublist we are going to reverse
		return std::pair<list_node*, list_node*>(prev_node, current_node);
	}

	list_node* reverse_every_k(int k) {

		// if k <= 1 we dont have to anything
		if (k <= 1) {
			return this->head_node;
		}

		list_node* prev_reversed_end = this->head_node;

		std::pair<list_node*, list_node*> res = this->reverse_list(prev_reversed_end, k);
		// after first sublist reversal our head node will be starting node of the first reversed sublist
		this->head_node = res.first;
		list_node* next_unreversed_sublist = res.second;

		while (next_unreversed_sublist) {

			std::pair<list_node*,list_node*> res = this->reverse_list(next_unreversed_sublist, k);
			// set previos sublists end to the currently reversed sublists start node
			prev_reversed_end->set_next(res.first);
			// previous reversed end should point to the currenly reversed last node (i.e. pointed by the next unreversed sublist)
			prev_reversed_end = next_unreversed_sublist;
			// update next unreversed sublist variable
			next_unreversed_sublist = res.second;
		}

		// finally return the new head node
		return this->head_node;
	}

public:
	reverse_every_k_element_sublist() {

		this->head_node = new list_node(1, nullptr);
		this->head_node->set_next(new list_node(2, nullptr));
		this->head_node->get_next()->set_next(new list_node(3, nullptr));
		this->head_node->get_next()->get_next()->set_next(new list_node(4, nullptr));
		this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(5, nullptr));
		this->head_node->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(6, nullptr));
		this->head_node->get_next()->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(7, nullptr));
		this->head_node->get_next()->get_next()->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(8, nullptr));
	}

	void print_reversed_k_sublists(int k){
		
		std::cout << "Original list: " << std::endl;
		this->print_list(this->head_node);
		std::cout << "Reversed sublist where k=" << k << std::endl;
		this->print_list(this->reverse_every_k(k));
	}

};