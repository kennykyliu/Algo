#include <iostream>
#include <vector>

using namespace std;

string convertHundred(int num) {
    vector<string> set1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> set2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string res;

    int num1 = num / 100;
    int num2 = num % 100;
    int num3 = num % 10;

    if (num1 > 0) {
        res += set1[num1] + " Hundred";
    }
    if (num2 < 20) {
        res += " " + set1[num2];
    } else {
        res += " " + set2[num2 / 10];
        if (num3 > 0) {
            res += " " + set1[num3];
        }
    }
    return res;
}

int main() {
    cout << convertHundred(658) << endl;
    cout << INT_MAX << endl;
    return 0;
}
