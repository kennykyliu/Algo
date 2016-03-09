#include <iostream>

using namespace std;

int main() {
    string str;
    str += "abc";
    cout << str << endl;
    str.clear();
    cout << str << endl;
    str += "def";
    if (str == "def") {
        cout << "str == def" << endl;
    } else {
        cout << "str is not def" << endl;
    }
    return 0;
}
