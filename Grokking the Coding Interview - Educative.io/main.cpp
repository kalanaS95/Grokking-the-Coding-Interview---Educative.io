#include <iostream>
#include <vector>
#include "Introduction.cpp"
#include "Maximum_sum_subarray_of_size_k_(Easy).cpp"
#include "Smallest_subarray_with_a_given_sum_(Easy).cpp"
#include "Longest_substring_with_maximum_k_distinct_characters_(Medium).cpp"
#include "Fruits_in_baskets_(Medium).cpp"
#include "Longest_substring_with_distinct_characters_(Hard).cpp"
#include "Longest_substring_with_same_letters_after_replacement_(Hard).cpp"

using namespace std;

int main() {

	cout << "Average Of Subarray Of Size K" << endl;
	AverageOfSubarrayOfSizeK average_k;
	vector<double> results = average_k.findAverage();
	cout << "Averages are: [ ";
	for (double x : results) {

		cout << x << " ";
	}
	cout << "]" << endl << endl;

	cout << "find MaxSum SubArray" << endl;
	MaxSumSubArrayOfSizeK max_sum;
	cout << "Max sum is: " << max_sum.findMaxSumSubArray() << endl << endl;

	cout << "Smallest Subarray with a given sum " << endl;
	MinSizeSubArraySum min_array;
	cout << "Length of the smallest sub array: " << min_array.findMinSubArray() << endl << endl;

	cout << "Longest Substring with maximum K Distinct Characters " << endl;
	LongestSubstringKDistinct longest_string;
	cout << "Length of longest substring: " << longest_string.findLength() <<endl <<endl;

	cout << "Fruits into Baskets" << endl;
	MaxFruitCountOf2Types max_fruit;
	cout << "Maximum number of fruits in both baskets: " << max_fruit.findLength() << endl << endl;

	cout << "Longest Substring with Distinct Characters" << endl;
	NoRepeatSubstring longest_sub;
	cout << "Length of longest substring: " << longest_sub.findLength() << endl << endl;

	cout << "Longest Substring with Same Letters after Replacement" << endl;
	CharacterReplacement char_replace;
	cout << "Length of the longest substring having the same letters: " << char_replace.findLength() << endl << endl;

	return 0;
}