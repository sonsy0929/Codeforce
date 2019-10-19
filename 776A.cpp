
#include <iostream>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string name1, name2;
    cin >> name1 >> name2;
    set<string> alived;
    alived.insert(name1);
    alived.insert(name2);
    int N; cin >> N;
    for (int i = 0; i < N; i++){
        string killed, replaced;
        cin >> killed >> replaced;
        for (auto &s : alived) cout << s << " ";
        cout << "\n";
        alived.erase(killed);
        alived.insert(replaced);
    }
    for (auto &s : alived) cout << s << " ";
}