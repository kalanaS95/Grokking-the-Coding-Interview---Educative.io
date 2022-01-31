/*
	Question: We are given an array containing n objects. Each object, when created, was assigned a unique number from the range 1 to n based on their creation sequence. 
	This means that the object with sequence number 3 was created just before the object with sequence number 4.
	Write a function to sort the objects in-place on their creation sequence number in O(n) and without using any extra space. For simplicity, let’s assume we are passed an integer array containing
	only the sequence numbers, though each number is actually an object.
	Input: [3, 1, 5, 4, 2]
	Output: [1, 2, 3, 4, 5]
*/
#include <vector>
using std::vector;

class cyclic_sort {
private:
	vector<int> arr;

	void swap(int* a, int* b) {

		int temp = *a;
		*a = *b;
		*b = temp;
	}

public:
	cyclic_sort() {
		this->arr = { 3, 1, 5, 4, 2 };
	}

	vector<int> cycle_sort() {

		int curr = 0;

		while (curr < this->arr.size()) {

			if (curr + 1 != this->arr[curr]) {

				swap(&(this->arr[curr]), &(this->arr[this->arr[curr] - 1]));
			}
			else {
				curr++;
			}
		}

		return this->arr;
	}
};