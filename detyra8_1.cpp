#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    // Square each element in the array
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = nums[i] * nums[i];
    }
    
    // Sort the squared array
    sort(nums.begin(), nums.end());
    
    return nums;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquares(nums);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    
    return 0;
}
