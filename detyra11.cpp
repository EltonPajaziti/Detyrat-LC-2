#include <iostream>
#include <string>

using namespace std;

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

    return time;
}

int main() {
    string time1 = "2?:?0";
    cout << "Maximum time for " << time1 << ": " << maximumTime(time1) << endl;

    string time2 = "0?:3?";
    cout << "Maximum time for " << time2 << ": " << maximumTime(time2) << endl;

    return 0;
}
