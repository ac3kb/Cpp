#include <iostream>
using namespace std;

void twice(int*);

int main()
{
    //part 1
    int num = 5;
    twice(&num);
    cout << num << endl;

    //part 2
    unsigned int values[5] = { 2,4,6,8,10 };
    unsigned int* vPtr;

    vPtr = values;
    vPtr = &values[0];

    for (int i = 0; i < 5; i++) {
        cout << "at address " << (vPtr + i) << ": " << * (vPtr + i) << endl;
    }

    cout << "the fifth element is " << vPtr[4] << endl;

    cout << "question: " << "If vPtr points to the first element of array values \n";
    cout << "then what address is referenced by vPtr + 3 ? (manually calculate) \n" << endl;
    cout << "answer: " << "address of (vPtr + 3) is \n        1002500 + (3 * 2) = 1002506 \n" << endl;
    cout << "the value stored at that location is " << "vPtr[3] == 5" << endl;

}


void twice(int* pointer) {
    *pointer += *pointer;
}
