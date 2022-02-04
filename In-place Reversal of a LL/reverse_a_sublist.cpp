/*
	Question: Given the head of a LinkedList and two positions ‘p’ and ‘q’, reverse the LinkedList from position ‘p’ to ‘q’.
	Input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
	P: 2
	q: 4
	Output: 1 -> 4 -> 3 -> 2 -> 5 -> NULL
*/
#include "list_node.h"
#include <iostream>

/*
	Time Complexity: O(n), where n is number of nodes in the list, the algorithm only goes through the nodes once
	Space Complexity: O(1)
*/
class reverse_a_sublist {
private:
	list_node* head_node;

	void print_list(list_node* curr_node) {

		while (curr_node) {

			std::cout << curr_node->get_value() << " -> ";
			curr_node = curr_node->get_next();
		}

		std::cout << "NULL" << std::endl;
	}

	list_node* reverse_nodes(list_node* start, list_node* end) {

		list_node* current_node = start;
		list_node* prev_node = nullptr;
		list_node* q = nullptr;

		// move end to the next node
		end = end->get_next();
		// we need to loop one end node + 1 times or until we encounter nullptr if end is the last node
		while (current_node != end) {

			q = prev_node;
			prev_node = current_node;
			current_node = current_node->get_next();

			prev_node->set_next(q);
		}

		return prev_node;
	}

	list_node* reverse_subset(int p, int q) {

		// we need to find p - 1, used when we merge back to the sub-list
		list_node* current_p = this->head_node;
		list_node* p_minus_1 = nullptr;
		for (int x = 0; x < p - 1; x++) {

			p_minus_1 = current_p;
			current_p = current_p->get_next();
		}

		// we need to find q to pass into the reverse_nodes function
		list_node* current_q = this->head_node;
		for (int x = 0; x < q - 1; x++) {
			current_q = current_q->get_next();
		}

		// we will find q + 1, will be used when we merge back to the sub-list
		list_node* q_plus_1 = (current_q) ? current_q->get_next() : nullptr;

		list_node* reverse_sublist_start = this->reverse_nodes(current_p, current_q);

		// extract the end of the reversed_sublist, that is always pointed by the current_p
		list_node* reverse_sublist_end = current_p;
		
		// connect reverse_sublist end to the q_plus_1
		reverse_sublist_end->set_next(q_plus_1);

		// connect p-1 to the reverse_sublist_start, only if there are nodes (i.e. p_minus_1 != nullptr)
		// otherwise, if there are no nodes left in the left side, reverse sublist start should be our head node
		if (p_minus_1) {

			p_minus_1->set_next(reverse_sublist_start);
		}
		else {

			this->head_node = reverse_sublist_start;
		}

		return this->head_node;
	}

public:
	reverse_a_sublist() {

		this->head_node = new list_node(1, nullptr);
		this->head_node->set_next(new list_node(2, nullptr));
		this->head_node->get_next()->set_next(new list_node(3, nullptr));
		this->head_node->get_next()->get_next()->set_next(new list_node(4, nullptr));
		this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(5, nullptr));
	}

	void print_results(int p, int q) {

		std::cout << "Original Linked List: " << std::endl;
		this->print_list(this->head_node);
		std::cout << "Reverse Sublist where p=" << p << " q=" << q << std::endl;
		this->print_list(this->reverse_subset(p, q));
	}
};