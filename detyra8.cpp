#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());

    unordered_map<int, int> count;
    for (int i = 0; i < sortedNums.size(); i++) {
        if (count.find(sortedNums[i]) == count.end()) {
            count[sortedNums[i]] = i;
        }
    }

    vector<int> result;
    for (int num : nums) {
        result.push_back(count[num]);
    }

    return result;
}

int main() {
    vector<int> nums = {8, 1, 2, 2, 3};
    vector<int> counts = smallerNumbersThanCurrent(nums);

    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Output: ";
    for (int count : counts) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
//Time:O(n log n)
//Space:O(n)
