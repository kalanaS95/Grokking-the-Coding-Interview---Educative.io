#pragma once
/*
	Defines the data structure for a tree node
*/
class tree_node {
private:
	int data;
	tree_node* left_child;
	tree_node* right_child;

public:
	tree_node() {

		this->data = 0;
		this->left_child = nullptr;
		this->right_child = nullptr;
	}

	tree_node(int data) {

		this->data = data;
		this->left_child = nullptr;
		this->right_child = nullptr;
	}

	int get_data() {

		return this->data;
	}

	void set_data(int data) {

		this->data = data;
	}

	tree_node* get_left_child() {

		return this->left_child;
	}

	void set_left_child(tree_node* left_child) {

		this->left_child = left_child;
	}

	tree_node* get_right_child() {

		return this->right_child;
	}

	void set_right_child(tree_node* right_child) {

		this->right_child = right_child;
	}
};