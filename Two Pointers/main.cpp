#include <iostream>
#include "Pair_with_target_sum_(Easy).cpp"
#include "Remove_duplicates_(Easy).cpp"
using namespace std;

int main()
{
    cout << "Pair with Target Sum" << endl;
    pair_with_target_sum target_sum;
    pair<int, int> indexes = target_sum.search();
    cout << "Pair in the array whose sum is equal to the given target " << indexes.first << ", " << indexes.second << endl << endl;

    cout << "Remove Duplicates" << endl;
    remove_duplicates remov_dups;
    cout << "Array length after removing duplicates: " << remov_dups.remove_dups() << endl << endl;
}

