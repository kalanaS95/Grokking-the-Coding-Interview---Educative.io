/*
	Question: Given an array of characters where each character represents a fruit tree, you are given two baskets, 
			  and your goal is to put maximum number of fruits in each basket. The only restriction is that each basket can have only 
			  one type of fruit.

			  You can start with any tree, but you can’t skip a tree once you have started. You will pick one fruit from each tree until you cannot,
			  i.e., you will stop when you have to pick from a third fruit type.
			  Array: ['A', 'B', 'C', 'A', 'C']
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define NUM_BASKETS 2

class MaxFruitCountOf2Types {

private:
	vector<char> *fruits;

public:
	MaxFruitCountOf2Types() {

		this->fruits = new vector<char>({ 'A', 'B', 'C', 'B', 'B', 'C' });
	}

	MaxFruitCountOf2Types(vector<char>& fruits) {

		this->fruits = new vector<char>(fruits);
	}

	int findLength() {

		int window_start = 0;
		int max_fruit = INT_MIN;
		map<char, int> fruit_map;
		map<char, int>::iterator map_itr;

		for (int window_end = 0; window_end < this->fruits->size(); window_end++) {

			map_itr = fruit_map.find(this->fruits->at(window_end));

			if (map_itr == fruit_map.end()) {

				fruit_map.insert(pair<char, int>(this->fruits->at(window_end), 1));
			}
			else {

				map_itr->second++;
			}

			while (fruit_map.size() > NUM_BASKETS) {

				map_itr = fruit_map.find(this->fruits->at(window_start));
				map_itr->second--;

				if (map_itr->second < 1) {

					fruit_map.erase(map_itr);
				}

				window_start++;
			}

			max_fruit = max(max_fruit, (window_end - window_start + 1));
		}

		return max_fruit;
	}

};