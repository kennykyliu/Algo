#include <iostream>

using namespace std;

int main() {
    string str = "-123*456/789+101112";
    size_t size = 0;

    cout << stoi(str, &size) << endl;
    cout << size <<endl;

    return 0;
}
