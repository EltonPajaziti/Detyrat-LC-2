#include <iostream>
#include <unordered_map>

using namespace std;

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

    return count;
}

int main() {
    string s1 = "abccccdd";
    cout << "Longest palindrome length for " << s1 << ": " << longestPalindrome(s1) << endl;

    string s2 = "a";
    cout << "Longest palindrome length for " << s2 << ": " << longestPalindrome(s2) << endl;

    return 0;
}
//Dyjat O(n)
