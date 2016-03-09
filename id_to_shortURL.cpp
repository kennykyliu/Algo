#include <iostream>

using namespace std;

// Base 62 map
string map = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

string id2URL(int n) {
    string result = "";

    while (n > 0) {
        result += map[n % 62];
        n /= 62;
    }
    reverse(result.begin(), result.end());

    return result;
}

int url2ID(string str) {
    int result = 0;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            result = result * 62 + str[i] - 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            result = result * 62 + str[i] - 'A' + 26;
        } else if (str[i] >= '0' && str[i] <= '9') {
            result = result * 62 + str[i] - '0' + 52;
        }
    }
    return result;
}

int main() {
    int id = 12345;
    string url = id2URL(id);

    cout << "Origin ID: ";
    cout << "ID to URL: " << url << endl;
    cout << "URL to ID: " << url2ID(url) << endl;

    return 0;
}
