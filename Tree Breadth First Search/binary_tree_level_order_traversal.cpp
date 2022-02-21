#include <iostream>
#include <queue>
#include "tree_node.h"

class binary_tree_level_order_traversal {
private:
	tree_node* root;
	std::queue<tree_node*> tree_node_queue;
	std::vector<std::vector<int>> results;

public:
	binary_tree_level_order_traversal() {

		this->root = new tree_node(12);
		root->set_left_child(new tree_node(7));
		root->set_right_child(new tree_node(1));
		root->get_left_child()->set_left_child(new tree_node(9));
		root->get_right_child()->set_left_child(new tree_node(10));
		root->get_right_child()->set_right_child(new tree_node(5));

		this->tree_node_queue = std::queue<tree_node*>();
		this->results = std::vector<std::vector<int>>();
	}

	void calculate_level_order() {

		// add the root node to the queue
		this->tree_node_queue.push(root);
		// keep executing until the queue is empty. I.e. until all the nodes are processed
		while (!this->tree_node_queue.empty()) {
			
			// create a vector to store all the node information in the current level
			std::vector<int> curr_level_nodes;
			// get the current queue size. This makes sure we are only iterating children amount of times
			int current_queue_size = this->tree_node_queue.size();
			// iterate through all the nodes in the current level
			for (int curr_index = 0; curr_index < current_queue_size; curr_index++) {

				// grab the top most node in the current queue
				tree_node* curr_tree_node = this->tree_node_queue.front();
				this->tree_node_queue.pop();
				curr_level_nodes.push_back(curr_tree_node->get_data());

				// check if the current node has a left child
				if (curr_tree_node->get_left_child()) {
					this->tree_node_queue.push(curr_tree_node->get_left_child());
				}

				// check if the current node has a right child
				if (curr_tree_node->get_right_child()) {
					this->tree_node_queue.push(curr_tree_node->get_right_child());
				}
			}

			// once the level is processes add the nodes in the level to the results vector
			this->results.push_back(curr_level_nodes);
		}
	}

	void print_level_order() {

		this->calculate_level_order();

		for (std::vector<int> curr_list : this->results) {

			for (int curr_node : curr_list) {

				std::cout << curr_node << " ";
			}

			std::cout << std::endl;
		}
	}
};