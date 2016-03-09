#include <iostream>
#include <vector>

using namespace std;


void combinationSumDFS(vector<int>& candidates, int target, int start_candi, vector<int> curr, vector<vector<int> >& result) {
   if (target < 0) {
        return;
   }
   if (target == 0) {
        result.push_back(curr);
        return;
   }
   for (int i = start_candi; i < candidates.size(); ++i) {
        curr.push_back(candidates[i]);
        combinationSumDFS(candidates, target - candidates[i], i, curr, result);
        curr.pop_back();
   }
   return;
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
   vector<int> curr;
   vector<vector<int> > result;

   sort(candidates.begin(), candidates.end());
   combinationSumDFS(candidates, target, 0, curr, result);

   return result;
}

/*
void combinationSumDFS(vector<int> &candidates, int target, int start, vector<int> &out, vector<vector<int> > &res);

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > res;
    vector<int> out;
    sort(candidates.begin(), candidates.end());
    combinationSumDFS(candidates, target, 0, out, res);
    return res;
}

void combinationSumDFS(vector<int> &candidates, int target, int start, vector<int> &out, vector<vector<int> > &res) {
    if (target < 0) return;
    else if (target == 0) res.push_back(out);
    else {
        for (int i = start; i < candidates.size(); ++i) {
            out.push_back(candidates[i]);
            combinationSumDFS(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
}
*/

int main() {
    vector<int> testSet;
    testSet.push_back(2);
    testSet.push_back(3);
    testSet.push_back(6);
    testSet.push_back(7);

    vector<vector<int> > result = combinationSum(testSet, 7);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
