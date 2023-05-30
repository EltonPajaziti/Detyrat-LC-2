#include <iostream>
#include <vector>
using namespace std;
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
	vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		int count = 0;
		for (int j = 0; j < nums.size(); j++) {
			if (nums[i] > nums[j] && i != j) {
				count++;
			}
		}
		result.push_back(count);
	}
	return result;
}
int main(){
    vector<int> nums;
	nums = {8,1,2,2,3};
	vector<int> result;
	

    result = smallerNumbersThanCurrent(nums);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    

    return 0;
}