#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> searchTargetIndices(vector<int>& nums, int target) {
    vector<int> sortedIndices(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        sortedIndices[i] = i;
    }

    sort(sortedIndices.begin(), sortedIndices.end(),
        [&](int a, int b) { return nums[a] < nums[b]; });

    vector<int> result;
    for (int i = 0; i < sortedIndices.size(); ++i) {
        int index = sortedIndices[i];
        if (nums[index] == target) {
            result.push_back(index);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 5, 2, 3};
    int target1 = 2;
    vector<int> result1 = searchTargetIndices(nums, target1);
    cout << "Indices where nums[i] == " << target1 << ": ";
    for (int index : result1) {
        cout << index << " ";
    }
    cout << endl;

    int target2 = 3;
    vector<int> result2 = searchTargetIndices(nums, target2);
    cout << "Indices where nums[i] == " << target2 << ": ";
    for (int index : result2) {
        cout << index << " ";
    }
    cout << endl;

    int target3 = 5;
    vector<int> result3 = searchTargetIndices(nums, target3);
    cout << "Indices where nums[i] == " << target3 << ": ";
    for (int index : result3) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
