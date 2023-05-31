#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int maxArea = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int currentArea = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, currentArea);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}

int main() {
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max area of water for height1: " << maxArea(height1) << endl;

    vector<int> height2 = {1, 1};
    cout << "Max area of water for height2: " << maxArea(height2) << endl;

    return 0;
}
