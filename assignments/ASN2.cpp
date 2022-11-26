/*
	Assignment number 2
*/

#include <iostream>
using namespace std;


int main() {

	//program 1:
	cout << "////////////PROGRAM 1//////////// \n" << endl;
	int prod = 1;
	for (int a{ 1 }; a <= 15; a += 2) {
		cout << a << " " << (prod *= a) << endl;
	}

	cout << "\n" << "the product is " << prod;
	

	cout << "\n \n \n////////////PROGRAM 2//////////// \n" << endl;
	//program 2:
	char buy{'T'};
	int prodNum, quantity;
	double total{ 0.0 };
	while (buy == 'T') {
		cout << "input product number and quanitity" << endl;
		cin >> prodNum >> quantity;
		
		switch (prodNum) {
		case 1:
			total += (2.98 * quantity);
			break;
		case 2:
			total += (4.50 * quantity);
			break;
		case 3:
			total += (9.98 * quantity);
			break;
		case 4:
			total += (4.49 * quantity);
			break;
		case 5:
			total += (6.87 * quantity);
			break;
		default:
			cout << "your product number does not exist" << endl;
		}

		cout << "would you like to continue buying? enter T (yes) OR F (no) " << endl;
		cin >> buy;
		switch (buy) {
		case 'f':
		case 'F':
			buy = 'F';
			break;
		case 't':
		case 'T':
			buy = 'T';
			break;
		default:
			cout << "T or F are the only values allowed" << endl;
			break;
		}

		if (buy == 'F') {
			cout << "your total is " << total << endl;
		}
		
	}

}
