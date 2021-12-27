/*
	Question: Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order.
			  Array: [-2, -1, 0, 2, 3]
*/
#include <iostream>
#include <vector>
using namespace std;

/*
	Time Complexity: O(n), where n is number of elements in the given sorted array
	Space Complexity: O(n), where n is number of elements in the given sorted array
*/
class sorted_array_squared {

private:
	vector<int> sorted_array;

public:
	sorted_array_squared() {

		this->sorted_array = { -2, -1, 0, 2, 3 };
	}

	sorted_array_squared(vector<int>& sorted_array) {

		this->sorted_array = sorted_array;
	}

	vector<int> square_array() {

		vector<int> results(this->sorted_array.size(), 0);
		int result_vector_index = this->sorted_array.size() - 1;
		int start_ptr = 0;
		int end_ptr = this->sorted_array.size() - 1;

		while (start_ptr <= end_ptr) {

			int start_sqrt = this->sorted_array[start_ptr] * this->sorted_array[start_ptr];
			int end_sqrt = this->sorted_array[end_ptr] * this->sorted_array[end_ptr];

			if (start_sqrt >= end_sqrt) {

				results[result_vector_index] = start_sqrt;
				result_vector_index--;
				start_ptr++;
			}
			else {

				results[result_vector_index] = end_sqrt;
				result_vector_index--;
				end_ptr--;
			}
		}
		
		return results;
	}
};