#include <iostream>
#include <vector>

using namespace std;

class package {
public:
    package(vector<package> v, int n): dep(v), num(n) {}
    vector<package> getDirectDependencies() { return dep; }
    int num;
private:
    vector<package> dep;
};

void dumpAll(package obj, vector<int>& result) {
    if (obj.getDirectDependencies().size() == 0) {
        return;
    }
    vector<package> pac_list = obj.getDirectDependencies();
    for (int i = 0; i < pac_list.size(); ++i) {
        result.push_back(pac_list[i].num);
        dumpAll(pac_list[i], result);
    }
}

int main() {
    vector<package> dummy;
    package p1(dummy, 1);
    package p2(dummy, 2);
    package p3(dummy, 3);
    vector<package> vp1;
    vector<package> vp2;
    vp1.push_back(p1);
    vp1.push_back(p2);
    vp1.push_back(p3);
    vp2.push_back(p2);
    vp2.push_back(p3);
    package p5(vp2, 5);
    package p6(vp1, 6);
    vector<package> vp3;
    vp3.push_back(p5);
    vp3.push_back(p6);

    package p7(vp3, 7);


    vector<int> result;
    dumpAll(p7, result);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
