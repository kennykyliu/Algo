#include <iostream>

using namespace std;

int countOnes(int num) {
    int count = 0;

    while (num != 0) {
        count++;
        num = num & (num - 1);
    }
    return count;
}

int main() {
    cout << "# of 1 in 18: " << countOnes(18) << endl;
    cout << "# of 1 in 23: " << countOnes(23) << endl;
    cout << "# of 1 in 29: " << countOnes(29) << endl;
    cout << "# of 1 in -2: " << countOnes(-2) << endl;

    return 0;
}
