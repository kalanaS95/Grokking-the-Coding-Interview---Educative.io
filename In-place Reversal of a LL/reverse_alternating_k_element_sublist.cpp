#include <iostream>
#include "list_node.h"

class reverse_alternating_k_element_sublist {
private:
	list_node* head_node;

	void print_list(list_node* current_node) {

		while (current_node) {

			std::cout << current_node->get_value() << " -> ";
			current_node = current_node->get_next();
		}

		std::cout << "NULL" << std::endl;
	}

	std::pair<list_node*, list_node*> reverse_nodes(list_node* current_node, int k) {

		list_node* prev_node = nullptr;
		list_node* q = nullptr;
		int current_k = 0;

		while (current_node && current_k < k) {

			q = prev_node;
			prev_node = current_node;
			current_node = current_node->get_next();

			prev_node->set_next(q);
		}

		// prev_node - start node of the reversed sublist, current_node - start node of the unreversed sublist
		return std::pair<list_node*, list_node*>(prev_node, current_node);
	}

	list_node* reverse_alternating_sublists(int k) {

		bool is_reverse = false;
		// first reversal is done at this point
		list_node* reverse_sublist_end = this->head_node;
		list_node* prev_reverse_sublist_end = reverse_sublist_end;
		std::pair<list_node*, list_node*> res = this->reverse_nodes(reverse_sublist_end, k);
		list_node* reverse_sublist_start = res.first;
		list_node* next_sublist_start = res.second;
		// our new head should be pointing to the first node of the reversed sublist
		this->head_node = reverse_sublist_start;

		while (next_sublist_start) {

			if (!is_reverse) { // executes non reversing section

				// take the reverse sublist end to the start of the non reversing sublist
				reverse_sublist_end = next_sublist_start;
				// then lets connect the two sublists (i.e. prev_reverse_sublist ---> reverse_sublist)
				prev_reverse_sublist_end->set_next(reverse_sublist_end);
				// take the prev_reverse_sublist_end pointer to the reverse sublist end pointers place
				// so we can all these pointer in the below loop
				prev_reverse_sublist_end = reverse_sublist_end;

				int current_k = 0;
				while (next_sublist_start && current_k < k) {

				}
				
			}
		}
	}

public:
	reverse_alternating_k_element_sublist() {

		this->head_node = new list_node(1, nullptr);
		this->head_node->set_next(new list_node(2, nullptr));
		this->head_node->get_next()->set_next(new list_node(3, nullptr));
		this->head_node->get_next()->get_next()->set_next(new list_node(4, nullptr));
		this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(5, nullptr));
		this->head_node->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(6, nullptr));
		this->head_node->get_next()->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(7, nullptr));
		this->head_node->get_next()->get_next()->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(8, nullptr));
	}


};