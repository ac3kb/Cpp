#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

double average( const array< array<int, 3>, 2> &);

int main()
{
	//part 1
	double arrAverage;
	array< array<int, 3>, 2> t = {1,2,3,6,8,0};

	arrAverage = average(t);
	cout << arrAverage << endl;

	//part 2
	vector<int> part2;
	for (int x = 0; x < 20; x++) {
		cout << "loop iteration " << x << endl;
		int entered;
		cout << "enter a number between 10 and 100 " << "\n";
		cin >> entered;

		sort(part2.begin(), part2.end());

		if (!binary_search(part2.begin(), part2.end(), entered) && (entered >= 10) && (entered <= 100)) {
			part2.push_back(entered);
		}
		else {
			cout << "number has already been entered or is not in the 10 to 100 range, try another number ";
			x--;
			continue;
		}
	}

	for (auto y : part2) {
		cout << y << " ";
	}

}
//part 1
double average(const array< array<int, 3>, 2>& arr) {
	int total = 0;
	int nums = 0;
	double average;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			total += arr[i][j];
			nums++;
		}
	}

	average = (static_cast<double>(total) / nums);
	return average;
}
