#include <iostream>
#include <algorithm>
#include <cstring>

using std::cout;
using std::endl;
using std::copy;
using std::strlen;

char* duplicate_chars(const char* p);

int main() {
    char* meme = duplicate_chars("Hello world");
    cout << "Duplicated: " << endl;
    char* e = meme;
    for(int i = 0; i < strlen(meme) + 1; ++i) {
        cout << *e;
        ++e;
    }
}

char* duplicate_chars(const char* p) {
    //Allocate enough space; remember to add one for the null
    size_t length = strlen(p) + 1;
    char* result = new char[length];

    //copy into our newly allocated space and return pointer to first element
    copy(p, p + length, result);
    return result;

}
