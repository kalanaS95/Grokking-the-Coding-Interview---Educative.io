#include <iostream>
#include "Linked_list_cycle_(Easy).cpp"
using namespace std;

int main()
{
	cout << "LinkedList Cycle" << endl;
	linked_list_cycle(false).find_cycle_length();
	linked_list_cycle(true).find_cycle_length();
}

