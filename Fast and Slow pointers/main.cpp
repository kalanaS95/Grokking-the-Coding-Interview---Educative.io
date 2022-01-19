#include <iostream>
#include "Linked_list_cycle_(Easy).cpp"
#include "start_of_a_linked_list_cycle_(medium).cpp"
#include "happy_number.cpp"
using namespace std;

int main()
{
	cout << "LinkedList Cycle" << endl;
	linked_list_cycle(false).find_cycle_length();
	linked_list_cycle(true).find_cycle_length();
	cout << endl << endl;

	cout << "Start Node of the linked list" << endl;
	cout << "Start nod of the cycle is: " << (start_of_LL_cycle(true).cycle_start())->get_value() << endl << endl;;
		
	cout << "Happy Number" << endl;
	string res = (happy_number().is_happy_number()) ? "Yes" : "No";
	cout << "12 is a happy number: " << res << endl << endl;

}

