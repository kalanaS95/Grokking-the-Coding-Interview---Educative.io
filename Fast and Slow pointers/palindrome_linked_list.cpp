#include "linked_list.h"
#include <iostream>

class palindrome_linked_list {
private:
	list_node* head_node;

	list_node* reverse(list_node* curr) {

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

	void print_list(list_node* p) {

		while (p != nullptr) {

			std::cout << p->get_value() << " -> ";
			p = p->get_next();
		}

		std::cout << "NULL" << std::endl;
	}

	list_node* find_middle_node() {

		// set both slow and fast pointers to the head
		list_node* slow_ptr = this->head_node;
		list_node* fast_ptr = this->head_node;

		while (fast_ptr && fast_ptr->get_next()) {

			slow_ptr = slow_ptr->get_next();
			fast_ptr = fast_ptr->get_next()->get_next();
		}

		return slow_ptr;
	}

public:
	palindrome_linked_list() {

		this->head_node = new list_node(2, nullptr);
		this->head_node->set_next(new list_node(4, nullptr));
		this->head_node->get_next()->set_next(new list_node(6, nullptr));
		this->head_node->get_next()->get_next()->set_next(new list_node(4, nullptr));
		this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(2, nullptr));

	}

	palindrome_linked_list(bool make_palindrome) {

		if (make_palindrome) {

			this->head_node = new list_node(2, nullptr);
			this->head_node->set_next(new list_node(4, nullptr));
			this->head_node->get_next()->set_next(new list_node(6, nullptr));
			this->head_node->get_next()->get_next()->set_next(new list_node(4, nullptr));
			this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(2, nullptr));
		}
		else {

			this->head_node = new list_node(2, nullptr);
			this->head_node->set_next(new list_node(4, nullptr));
			this->head_node->get_next()->set_next(new list_node(6, nullptr));
			this->head_node->get_next()->get_next()->set_next(new list_node(6, nullptr));
			this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(2, nullptr));
			this->head_node->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(2, nullptr));
		}

	}

	bool check_palindrome() {

		list_node* middle = find_middle_node();
		list_node* start = this->head_node;
		//this->print_list(middle);

		list_node* reversed = reverse(middle);
		list_node* reversed_copy = reversed;

		this->print_list(reversed);
		
		while (reversed && start) {

			if (reversed->get_value() != start->get_value()) {

				return false;
			}

			reversed = reversed->get_next();
			start = start->get_next();
		}

		// revert the reverse to build the original linked list back
		reverse(reversed_copy);
		
		return true;
	}
};