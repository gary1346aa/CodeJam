#include <bits/stdc++.h>

using namespace std;

void solve(int D, string P){
    if (count(P.begin(), P.end(), 'S') > D){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int dmg = 0, ch = 1, swp = 0;
    for (int i = 0; i < P.size(); i++){
        if(P[i] == 'C')
            ch *= 2;
        else if (P[i] == 'S')
            dmg += ch;
    }
    while(dmg > D){
        int ind = P.find_last_of('C');
        if (dmg - (P.size() - 1 - ind)*(ch - ch/2) > D){
            swp += (P.size() - 1 - ind);
            dmg -= (P.size() - 1 - ind)*(ch - ch/2);
            P.erase(P.begin() + ind);
            ch /= 2;
        }
        else{
            swp += (dmg - D)/(ch - ch/2) + ((dmg - D)%(ch - ch/2) > 0 ? 1 : 0);
            break;
        }
    }
    cout << swp << endl;
    return;
}


int main(){
    int T, D;
    string P;
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> D >> P;
        cout << "Case #" << i + 1 << ": ";
        solve(D,P);
    }
}