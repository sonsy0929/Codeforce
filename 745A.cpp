#include <iostream>
#include <string>
#include <set>
#include <deque>
using namespace std;
int main(){
    string s;
    cin >> s;
    deque<char> dq;
    set<string> st;
    for (char c : s) dq.push_back(c);
    int ans = 0;
    while (1) {
        string addStr;
        dq.push_front(dq.back());
        dq.pop_back();
        for (char c : dq) addStr += c;
        if (st.count(addStr)) break;
        st.insert(addStr);
        ans++;
    }
    cout << ans << "\n";
}