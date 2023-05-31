#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2; // Sum of numbers from 0 to n
    int actualSum = accumulate(nums.begin(), nums.end(), 0); // Sum of numbers in the array
    return expectedSum - actualSum;
}

int main() {
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int missingNum = missingNumber(nums);
    cout << "Missing number: " << missingNum << endl;
    return 0;
}
//Time:O(n)
//Space:O(1)
