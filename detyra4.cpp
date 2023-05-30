#include <iostream>
#include <unordered_map>
using namespace std;

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

int main() {
    string s = "leetcode";
    int index = firstUniqChar(s);

    cout << "Input: " << s << endl;
    cout << "Output: " << index << endl;

    return 0;
}
