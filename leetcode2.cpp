#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<stack>
#include<queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LeetCode2{
public:
//STACK
//1.Final Prices With a Special Discount in a Shop
//Kompleksiteti kohor:O(n^2)
//Kompleksiteti hapesinor:O(n)
vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> result(n, 0);

    for (int i = 0; i < n; i++) {
        int discount = 0;
        for (int j = i + 1; j < n; j++) {
            if (prices[j] <= prices[i]) {
                discount = prices[j];
                break;
            }
        }
        result[i] = prices[i] - discount;
    }

    return result;
}
//2.Remove All Adjacent Duplicates In String
//Time:O(n)
//Space:O(n)
string removeDuplicates(string s) {
    stack<char> st;
    string result = "";

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;}
    //3.Valid Parentheses
    //Time:O(n)
//Space:O(n)
bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.empty();}
//----------------------------------------------------------------------
    //QUEUE
    //4.First Unique Character in a String
//Time: O(n) 
//Space: O(n) 
    int firstUniqChar(string s) {
    unordered_map<char, int> count;

    for (char c : s) {
        count[c]++;
    }

    for (int i = 0; i < s.length(); i++) {
        if (count[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

//5 . Implement Stack using Queues
    // Time: O(1) amortizum
    // space: O(1) amortizum


    class MyStack {
    private:
        vector<int> stack;

    public:
        void push(int x) {
            stack.push_back(x);
        }
        
        int pop() {
            if (!empty()) {
                int topElement = stack.back();
                stack.pop_back();
                return topElement;
            }
            return -1;
        }
        
        int top() {
            if (!empty()) {
                return stack.back();
            }
            return -1;
        }
        
        bool empty() {
            return stack.empty();
        }
    };
     // 6. Time Needed to Buy Tickets
    // Time: O(n)
    // space: O(n)

    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> queue;
        int time = 0;

        for (int i = 0; i < tickets.size(); i++)
        {
            queue.push(tickets[i]);
        }
        int target = k;

        while(true){
            if (queue.front() != 0)
            {
                time ++;
                if (target == 0)
                {
                    if (queue.front() == 1)
                    {
                        return time;
                    }   
                    else
                        target = queue.size();
                }
                queue.push(queue.front() - 1);
                queue.pop();
            }
            else{
                queue.pop();
            }
            target --;
        }
    }
//------------------------------------------------------------------------
//SORTING
//7.How Many Numbers Are Smaller Than the Current Number
//Time:O(n^2)
//Space: O(n)
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
	return result;}
//8.Squares of a Sorted Array
// Time:O(n log n)
//Space:O(1) 
    vector<int> sortedSquares(vector<int>& nums) {
    // Square each element in the array
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = nums[i] * nums[i];
    }
    
    // Sort the squared array
    sort(nums.begin(), nums.end());
    
    return nums;}

//9.	Missing Number
//Time:O(n)
//Space:O(1)


    int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2; // Sum of numbers from 0 to n
    int actualSum = accumulate(nums.begin(), nums.end(), 0); // Sum of numbers in the array
    return expectedSum - actualSum;
}
//----------------------------------------------------------------------------------
//GREEDY
//10.Longest Palindrome
//Time:O(n)
//Space:O(n)
int longestPalindrome(string s) {
    unordered_map<char, int> frequency;
    int count = 0;

    // Count the frequency of each character
    for (char c : s) {
        frequency[c]++;
    }

    // Check the frequency of each character
    for (auto& pair : frequency) {
        count += pair.second / 2 * 2; 

        
        if (pair.second % 2 == 1 && count % 2 == 0) {
            count++;
        }
    }
}
//11.Latest Time by Replacing Hidden Digits
//Time:O(1)
//Space:O(1)
string maximumTime(string time) {
    if (time[0] == '?' && time[1] == '?') {
        time[0] = '2';
        time[1] = '3';
    } else if (time[0] == '?') {
        time[0] = (time[1] <= '3') ? '2' : '1';
    } else if (time[1] == '?') {
        time[1] = (time[0] == '2') ? '3' : '9';
    }

    if (time[3] == '?') {
        time[3] = '5';
    }
    if (time[4] == '?') {
        time[4] = '9';
    }

    return time;}
//12.Container With Most Water
//Time:O(n)
//Space:O(1)

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

    return maxArea;}
    // BINARY SEARCH    

    // 13. Find Target Indices After Sorting Array
    // Time: O(nlogn)
    // Space: O(n)

    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++){
            if (nums.at(i) == target)
                answer.push_back(i);
        }
        return answer;
    }
//14.Maximum Count of Positive Integer and Negative Integer
// Time: O(n)
    // Space: O(1)

    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0)
                neg ++;
            else if (nums[i] < 0)
                pos ++;
        }
        return max(pos, neg);
    }
        // 15. Kth Missing Positive Number
    // Time: O(n)
    // Space: O(1)

    int findKthPositive(vector<int>& arr, int k) {
        for (auto a : arr) {
            if (a <= k) k++;
        }
        return k;
    }
   

    int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;}


//----------------------------------------------------------------
//TREE

    // 16. Root Equals Sum of Children
    // Time: O(1)
    // Space: O(1)

    bool checkTree(TreeNode* root) {
        if (root->left->val + root->right->val == root->val)
            return true;
        return false;
    }

    // 17. Search in a Binary Search Tree
    // Time: O(n)
    // Space: O(n)

    TreeNode* searchBST(TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;
    else if (root->val > val)
        return searchBST(root->left, val);
    else 
        return searchBST(root->right, val);
    }

    // 18. Maximum Depth of Binary Tree
    // Time: O(n)
    // Space: O(n)

    int maxDepth(TreeNode* root) {
        if(!root) 
            return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
    }
// LINKED LIST

    // 19. Delete Node in a Linked List
    // Time: O(1)
    // Space: O(1)
   
    void deleteNode(ListNode* node) {
        auto next = node->next;
        *node = *next;
        delete next;
    }

    // 20. Reverse Linked List
    // Time: O(n)
    // Space: O(1)

    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
    return prevNode;
    }
};
int main(){
    //1.
/*LeetCode2 x;
vector<int> prices = {8, 4, 6, 2, 3};
    vector<int> discountedPrices = x.finalPrices(prices);

    cout << "Original Prices: ";
    for (int price : prices) {
        cout << price << " ";
    }

    cout << "\nDiscounted Prices: ";
    for (int price : discountedPrices) {
        cout << price << " ";
    }*/
    //----------------------------------------------------------------
    //2.
    /*LeetCode2 a;
 string s = "abbaca";
    string result = a.removeDuplicates(s);

    cout << "Original String: " << s << endl;
    cout << "String after removing duplicates: " << result << endl;*/
    //------------------------------------------------------------------
    //3.
    /*LeetCode2 b;
string s = "()";
    bool isValidString = b.isValid(s);

    cout << "Input: " << s << endl;
    cout << "Output: " << (isValidString ? "true" : "false") << endl;*/
    //------------------------------------------------------------------
   //4.
   /* LeetCode2 w;
string s = "leetcode";
    int index = w.firstUniqChar(s);

    cout << "Input: " << s << endl;
    cout << "Output: " << index << endl;*/
    //-------------------------------------------------------------------
   //6.
    // vector<int> tickets = {2, 3, 2};
    // int k = 2;
    // LeetCode2 timeRequired;
    // cout << "Time required is: " << timeRequired.timeRequiredToBuy(tickets, k) << endl;
   //---------------------------------------------------------------------
    //7.
    /*LeetCode2 p;
    vector<int> nums;
	nums = {8,1,2,2,3};
	vector<int> result;
	

    result = p.smallerNumbersThanCurrent(nums);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }  */
    //--------------------------------------------------------------------
   //8.
   /* LeetCode2 k;
     vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = k.sortedSquares(nums);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;*/
    //---------------------------------------------------------------------
    //9.
    /*LeetCode2 m;
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int missingNum = m.missingNumber(nums);
    cout << "Missing number: " << missingNum << endl;*/
    //---------------------------------------------------------------------
    //10.
    /*LeetCode2 m;
    string s1 = "abccccdd";
    cout << "Longest palindrome length for " << s1 << ": " << m.longestPalindrome(s1) << endl;

    string s2 = "a";
    cout << "Longest palindrome length for " << s2 << ": " <<m.longestPalindrome(s2) << endl;*/
    //------------------------------------------------------------------------------------------
    //11.
    /*LeetCode2 p;
    string time1 = "2?:?0";
    cout << "Maximum time for " << time1 << ": " << p.maximumTime(time1) << endl;

    string time2 = "0?:3?";
    cout << "Maximum time for " << time2 << ": " << p.maximumTime(time2) << endl;*/
    //----------------------------------------------------------------------------------------
  //12.
  /*LeetCode2 k;
  vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max area of water for height1: " << k.maxArea(height1) << endl;

    vector<int> height2 = {1, 1};
    cout << "Max area of water for height2: " << k.maxArea(height2) << endl;*/
    //-----------------------------------------------------------------------
  
   
    // BINARY SEARCH

    // 13. Find Target Indices After Sorting Array

    // vector<int> nums = {1, 2, 5, 2, 3};
    // int target = 2;
    // LeetCode2 i;
    // vector<int> indices = i.targetIndices(nums, target);
    // for (int i = 0; i < indices.size(); i++)
    // {
    //     cout << indices[i] << " ";
    // }
    //---------------------------------------------------------------------
    //14.
    // vector<int> nums = {-2, -1, -1, 1, 2, 3};
    // LeetCode2 maximumCount;
    // int max = maximumCount.maximumCount(nums);
    // cout << max;
    //---------------------------------------------------------------
    // 15. Kth Missing Positive Number
    // vector<int> arr = {2, 3, 4, 7, 11};
    // int k = 5;
    // LeetCode2 findKthPositive;
    // int kPos = findKthPositive.findKthPositive(arr, k);
    // cout << kPos;
    //------------------------------------------------------------------------
    // TREE 

    // 16. Root Equals Sum of Children
    // TreeNode* leftNode = new TreeNode(6);
    // TreeNode* rightNode = new TreeNode(6);
    // TreeNode* rootNode = new TreeNode(10, leftNode, rightNode);

    // LeetCode2 checkTree;
    // bool result = checkTree.checkTree(rootNode);

    // cout << "Result: " << (result ? "true" : "false") << endl;

    // delete leftNode;
    // delete rightNode;
    // delete rootNode;

// ----------------------------------------------------------------------------
// 17. Search in a Binary Search Tree
    // TreeNode* node1 = new TreeNode(1);
    // TreeNode* node3 = new TreeNode(3);
    // TreeNode* node2 = new TreeNode(2, node1, node3);
    // TreeNode* node7 = new TreeNode(7);
    // TreeNode* rootNode = new TreeNode(4, node2, node7);

    // LeetCode2 searchBST;
    // TreeNode* result = searchBST.searchBST(rootNode, 2);


    // if (result != nullptr){
    //     cout << "Result: " << result->val << endl;
    //     cout << "Result: " << result->left->val << endl;
    //     cout << "Result: " << result->right->val << endl;
    // }
    // else
    //     cout << "Result: Not found" << endl;

    // delete node1;
    // delete node3;
    // delete node2;
    // delete node7;
    // delete rootNode;

// ------------------------------------------------------------------------------
// 18. Maximum Depth of Binary Tree
    // TreeNode* node15 = new TreeNode(15);
    // TreeNode* node7 = new TreeNode(7);
    // TreeNode* node20 = new TreeNode(20, node15, node7);
    // TreeNode* node9 = new TreeNode(9);
    // TreeNode* rootNode = new TreeNode(3, node9, node20);

    // LeetCode2 maxDepth;
    // int result = maxDepth.maxDepth(rootNode);

    // cout << "Max Depth: " << result << endl;

    // delete node15;
    // delete node7;
    // delete node20;
    // delete node9;
    // delete rootNode;

    //-------------------------------------------------------------------------------------
 // LINKED LIST

    // 19. Delete Node in a Linked List
    // ListNode* head = new ListNode(4);
    // ListNode* node1 = new ListNode(5);
    // ListNode* node2 = new ListNode(1);
    // ListNode* node3 = new ListNode(9);

    // head->next = node1;
    // node1->next = node2;
    // node2->next = node3;

    // LeetCode2 del;
    // del.deleteNode(node1);

    // ListNode* current = head;
    // while (current != nullptr) {
    //     cout << current->val << " ";
    //     current = current->next;
    // }

    // current = head;
    // while (current != nullptr) {
    //     ListNode* next = current->next;
    //     delete current;
    //     current = next;
    // }


    // 20. Reverse Linked List
    // ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);

    // LeetCode2 r;
    // ListNode* reversedHead = r.reverseList(head);

    // ListNode* current = reversedHead;
    // while (current != nullptr) {
    //     cout << current->val << " ";
    //     current = current->next;
    // }

    // current = reversedHead;
    // while (current != nullptr) {
    //     ListNode* next = current->next;
    //     delete current;
    //     current = next;
    // }


    
    return 0;
}



