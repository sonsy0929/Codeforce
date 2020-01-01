#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    int countCommand[128]{};
    while (T--){
        string command;
        cin >> command;
        for (char c : command){
            countCommand[c]++;            
        }
        int LR = min(countCommand['L'], countCommand['R']);
        int UD = min(countCommand['U'], countCommand['D']);
        string answerCommand;
        char direction[4] = {'R', 'U', 'L', 'D'};
        int k = 0;
        for (int i = 0; i < 4; i++){
            if (i % 2 == 0){
                k = LR;
                while (k--) answerCommand += direction[i];
            }
            else{
                k = UD;
                while (k--) answerCommand += direction[i];
            }
        }
        cout << 2 * (LR + UD) << "\n";
        for (char c : answerCommand) cout << c;
        cout << "\n";
    }
}