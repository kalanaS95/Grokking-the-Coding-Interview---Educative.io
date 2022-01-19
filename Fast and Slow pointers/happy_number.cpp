/*
	Question: Any number will be called a happy number if, after repeatedly replacing it with a number equal to the sum of the square of all of its digits, leads us to number ‘1’. 
			  All other (not-happy) numbers will never reach ‘1’. Instead, they will be stuck in a cycle of numbers which does not include ‘1’.
			  Input : 23 -> Is a happy number
			  Inlut : 12 -> Not a happy number
*/
class happy_number {
private:
	int number;

	int find_sum_square(int num) {

		int digit = 0, sum = 0;
		while (num > 0) {

			digit = num % 10;
			sum += digit * digit;
			num /= 10;
		}

		return sum;
	}

public:
	happy_number() {
		this->number = 12;
	}

	happy_number(int number) {
		this->number = number;
	}

	bool is_happy_number() {

		int slow = this->number;
		int fast = this->number;

		do {

			slow = this->find_sum_square(slow);
			fast = this->find_sum_square(this->find_sum_square(fast));

		} while (slow != fast);

		return slow == 1; // if each of pointer is pointing to 1 means its a happy fucking number !
	}
};