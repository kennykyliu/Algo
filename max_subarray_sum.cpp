#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySum(vector<int>& nums) {
    int currSum = nums[0];
    int maxSum = nums[0];
    int start = 0;
    int max_start = 0;
    int end = 0;

    for (int i = 1; i < nums.size(); ++i) {
        cout << "i = " << i << " nums[i] = " << nums[i] << ", currSum = " << currSum << endl;
        if (nums[i] > currSum + nums[i]) {
            cout << "nums[i] = " << nums[i] << " > currSum + nums[i] = " << currSum + nums[i] << endl;
            currSum = nums[i];
            cout << "currSum becomes: "  << currSum << endl;
            start = i;
        } else {
            cout << "nums[i] = " << nums[i] << " <= currSum + nums[i] = " << currSum + nums[i] << endl;
            currSum += nums[i];
            cout << "currSum += nums[i]: "  << currSum << endl;
        }
        if (currSum > maxSum) {
            cout << "Replace maxSum from " << maxSum; 
            maxSum = currSum;
            cout << " to " << maxSum << endl;
            max_start = start;
            end = i;
        }
    }

    cout << "max_start = " << start << ", end = " << end << endl;
    return maxSum;
}

int main() {
    vector<int> nums;
    int result = 0;

    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);

    result = maxSubarraySum(nums);
    cout << "Result = " << result << endl;

    return 0;
}
