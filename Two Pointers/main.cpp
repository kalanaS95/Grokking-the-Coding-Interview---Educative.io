#include <iostream>
#include "Pair_with_target_sum_(Easy).cpp"
using namespace std;

int main()
{
    cout << "Pair with Target Sum" << endl;
    pair_with_target_sum target_sum;
    pair<int, int> indexes = target_sum.search();
    cout << "Pair in the array whose sum is equal to the given target " << indexes.first << ", " << indexes.second << endl << endl;
}

