#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string str = "Show me the money.";
    string str1;
    istringstream iss(str);
    vector<string> v;

    while (iss){
        string subStr;
        iss >> subStr;
        v.push_back(subStr);
    }

    cout << "vector size = " << v.size() << endl;

    for (auto str : v) {
        cout << str << endl;
    }

    cout << (int)v[4][0] << endl;
    return 0;
}
