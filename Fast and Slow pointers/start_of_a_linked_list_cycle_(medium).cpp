/*
	Problem: Given the head of a Singly LinkedList that contains a cycle, write a function to find the starting node of the cycle.
	Approach: First find the if the LL contains a loop
			  If yes, lets find the length of the cycle
			  Assume cycle length is K
			  Then start the slow and fast pointer at the beginnning of the list
			  Move fast pointer by K times (only once)
			  Then move fast and slow one step at a time.
			  Eventually, they will both meet at the start of the cycle
*/
#include <iostream>
#include "linked_list.h"

/*
	Time Complexity: O(n), where n is number of nodes in the LL
	Space Complexity: O(1)
*/
class start_of_LL_cycle {
private:
	list_node* head_node;
	list_node* slow_ptr;
	list_node* fast_ptr;

public:
	start_of_LL_cycle() {

		this->head_node = new list_node(1, nullptr);
		this->head_node->set_next(new list_node(2, nullptr));
		this->head_node->get_next()->set_next(new list_node(3, nullptr));
		this->head_node->get_next()->get_next()->set_next(new list_node(4, nullptr));
		this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(5, nullptr));
		this->head_node->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(6, nullptr));

		this->slow_ptr = this->fast_ptr = this->head_node;
	}

	start_of_LL_cycle(bool make_cycle) {

		this->head_node = new list_node(1, nullptr);
		this->head_node->set_next(new list_node(2, nullptr));
		this->head_node->get_next()->set_next(new list_node(3, nullptr));
		this->head_node->get_next()->get_next()->set_next(new list_node(4, nullptr));
		this->head_node->get_next()->get_next()->get_next()->set_next(new list_node(5, nullptr));
		this->head_node->get_next()->get_next()->get_next()->get_next()->set_next(new list_node(6, nullptr));

		if (make_cycle) {

			this->head_node->get_next()->get_next()->get_next()->get_next()->get_next()->set_next(this->head_node
				->get_next()
				->get_next()
				->get_next());
		}

		this->slow_ptr = this->fast_ptr = this->head_node;
	}

	/*
		if loop exists: slow and fast private members will be set to where they were met
		return false if no loop
		Time Complexity: O(n)
		Space Complexity: O(1)
	*/
	bool find_loop_exists() {

		// set both head and slow pointer to the head pointer (already done at the constructor)

		do {

			// moving slow pointer by one step
			this->slow_ptr = this->slow_ptr->get_next();
			// moving fast pointer by two steps
			this->fast_ptr = this->fast_ptr->get_next(); // move by one and then one just to be on the safe side :)
			if (this->fast_ptr) {
				this->fast_ptr = this->fast_ptr->get_next();
			}

			// if both meet there's a loop
			if (this->slow_ptr == this->fast_ptr) {
				return true;
			}

		} while (this->slow_ptr && this->fast_ptr);

		// no loop found
		return false;
	}

	/*
		Time Complexity: O(n)
		Space Complexity: O(1)
	*/
	int find_cycle_length() {

		if (this->find_loop_exists()) {

			// at this point both slow and fast pointers are met, inside the loop
			list_node* temp = this->slow_ptr;
			int count = 0;

			//lets move the temp again until we meet the slow/fast pointer again
			do {

				count++;
				temp = temp->get_next();

			} while (temp != this->slow_ptr);

			return count;
		}

		return 0;
	}

	/*
		Time Complexity: O(n)
		Space Complexity: O(1)
	*/
	list_node* cycle_start() {

		int cycle_length = this->find_cycle_length();
		if (cycle_length > 0) {

			// reset the slow and fast pointer to the head
			this->slow_ptr = this->fast_ptr = this->head_node;
			// move the fast pointer by cycle lenght
			for (int x = 0; this->fast_ptr && x < cycle_length; x++) {
				this->fast_ptr = this->fast_ptr->get_next();
			}
			// again lets move slow and fast pointers one step at a time. So they will eventually meet at the cycle start
			while (this->slow_ptr != this->fast_ptr) {

				this->slow_ptr = this->slow_ptr->get_next();
				this->fast_ptr = this->fast_ptr->get_next();
			}

			return this->slow_ptr;
		}

		return nullptr;
	}
};