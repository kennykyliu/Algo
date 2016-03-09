#include <iostream>

using namespace std;

int main() {
    int res = 5;
    for (int i = 6; i <= 120; ++i) {
        res &= i;
    }
    cout << res << endl;
    return 0;
}
