#include <iostream>

#include "10_2.h"

using std::cout;
using std::endl;

int main() {

    cout << "Let's test an array!" << endl;
    int numbers[] = { 5, 4, 6, 9, 1, 6, 8, 9, 6, 1, 4, 6, 1, 8, 10 };
    int numbers2[] = { 5, 7, 8, 3, 5, 2, 9, 2, 1, 8, 2, 3, 6, 4, 7 };

    int med = median(numbers, numbers + 15, 0);
    int med2 = median(numbers2, numbers2 + 15, 0);

    cout << "Median: " << med << endl;
    cout << "Median (2nd arr): " << med2 << endl;
}
