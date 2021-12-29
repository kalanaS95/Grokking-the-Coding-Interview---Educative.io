/*
	Question: Given an array containing 0s, 1s and 2s, sort the array in-place. You should treat numbers of the array as objects, hence,
			  we can’t count 0s, 1s, and 2s to recreate the array.
			  The flag of the Netherlands consists of three colors: red, white and blue; and since our input array also consists of three
			  different numbers that is why it is called Dutch National Flag problem.
			  Array: [1, 0, 2, 1, 0]
*/
#include <iostream>
#include <vector>
using std::vector;

/*
	Time Complexity: O(n), where n is number of elements in the vector
	Space Complexity: O(1)
*/
class dutch_flag {

private:
	vector<int> arr;

	void swap(int& first_element, int& second_element) {

		int temp = first_element;
		first_element = second_element;
		second_element = temp;
	}

public:
	dutch_flag() {

		this->arr = { 1, 0, 2, 1, 0 };
	}

	dutch_flag(vector<int>& arr) {

		this->arr = arr;
	}

	vector<int> sort_flag() {

		int index = 0;
		int start_ptr = 0;
		int end_ptr = this->arr.size() - 1;

		while (index <= end_ptr) {

			switch (this->arr[index]) {

			case 0:
				swap(this->arr[start_ptr], this->arr[index]);
				start_ptr++;
				index++;
				break;
			case 1:
				index++;
				break;
			case 2:
				swap(this->arr[end_ptr], this->arr[index]);
				end_ptr--;
				break;
			}
		}

		return this->arr;
	}
};