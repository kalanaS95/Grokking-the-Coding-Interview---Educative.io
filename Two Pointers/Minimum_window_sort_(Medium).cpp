/*
	Question: Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.
			  Array: [1, 2, 5, 3, 7, 10, 9, 12]

	Algorithm: 
				* From the beginning and end of the array, find the first elements that are out of the sorting order. The two elements will be our candidate subarray.
				* Find the maximum and minimum of this subarray.
				* Extend the subarray from beginning to include any number which is bigger than the minimum of the subarray.
				* Similarly, extend the subarray from the end to include any number which is smaller than the maximum of the subarray.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::max_element;
using std::min_element;
using std::advance;

/*
	Time Complexity: O(5n) == O(n), where n is number of elements in the vector
	Space Complexity: O(1)
*/
class minimum_window_sort {

private:
	vector<int> arr;

public:
	minimum_window_sort() {

		this->arr = { 3, 2, 1 };
	}

	minimum_window_sort(vector<int>& arr) {

		this->arr = arr;
	}

	int min_window_size() {

		int start_ptr = 0;
		int end_ptr = this->arr.size() - 1;

		// O(n)
		while (start_ptr < end_ptr) {

			if (this->arr[start_ptr] < this->arr[start_ptr + 1]) {
				start_ptr++;
			}

			if (this->arr[end_ptr] > this->arr[end_ptr - 1]) {
				end_ptr--;
			}

			if (this->arr[start_ptr] >= this->arr[start_ptr + 1] && this->arr[end_ptr] <= this->arr[end_ptr - 1]) {
				break;
			}
		}

		// finding min and max
		vector<int>::iterator start_itr = this->arr.begin();
		vector<int>::iterator end_itr = this->arr.begin();
		// advance the iterators to point to the correct positions pointed by the two int pointers above
		advance(start_itr, start_ptr);
		advance(end_itr, end_ptr);

		// find min and max
		int window_max = *max_element(start_itr, end_itr); // O(n)
		int window_min = *min_element(start_itr, end_itr); // O(n)

		// lets check if we need to extend the left side of the window
		// i.e. if there's is any value greater than the min value on the left side
		// O(n)
		for (int left_ptr = start_ptr - 1; left_ptr >= 0; left_ptr--) {

			if (this->arr[left_ptr] > window_min) {

				left_ptr--;
				start_ptr--;
			}
			else {
				break;
			}
		}
		
		// lets check if we need to extend the right side of the window
		// i.e. if there's is any value smaller than the max value on the right side
		// O(n)
		for (int right_ptr = end_ptr + 1; right_ptr <= this->arr.size() - 1; right_ptr++) {

			if (this->arr[right_ptr] < window_max) {

				right_ptr++;
				end_ptr++;
			}
			else {
				break;
			}
		}

		int length = end_ptr - start_ptr; // if this value is zero that means the array is already sorted. So we just return 0 otherwise we need to add 1
		return (length > 0) ? length + 1 : 0;
	}
};