#include <iostream>
#include <stack>
#include <string>
using namespace std;

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

    return result;
}

int main() {
    string s = "abbaca";
    string result = removeDuplicates(s);

    cout << "Original String: " << s << endl;
    cout << "String after removing duplicates: " << result << endl;

    return 0;
}
