#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


string letter_grade(double grade);

int main() {
    cout << "Please type in a grade... ";
    double g;
    cin >> g;
    cout << "This is a " << letter_grade(g) << endl;

}

string letter_grade(double grade) {
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };

    //Static constant array of constant char* pointers
    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    //How can we get the number of grades we have? (Length of the array?)
    //Well, each char is guaranteed to be 1 byte, so we can do...
    //  where sizeof() is a function which returns the number of bytes in a value
    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

    //Given a numeric grade, find and return the associated letter grade
    for(size_t i = 0; i < ngrades; ++i) {
        if(grade >= numbers[i])
            return letters[i];
    }

    //Multiple "?" marks in C++ shouldn't be done; we should escape
    return "?\?\?";
}
