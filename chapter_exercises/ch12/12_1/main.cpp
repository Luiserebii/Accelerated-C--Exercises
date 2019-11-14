#include <iostream>
#include "string.h"

using std::cout;
using std::endl;
using std::cin;

int main() {

    Str s = "meme";
    cout << s.end() - s.begin() << endl;
    cout << s << endl;
    Str n;
    n = "zoot";
    cout << n << endl;
    n += "uguu~";
    cout << n << endl;

    Str m;
    cin >> m;
    cout << m << endl;
}
