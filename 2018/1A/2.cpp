#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int solve(vector<int> M, vector<int> S, vector<int> P, int R, int B, int C){

    int Mx = 0;
    for (int i = 0; i < C; i++)
        if (M[i]*S[i]+P[i] > Mx)
            Mx = M[i]*S[i]+P[i];

    vector<vector<int> > cap(Mx+1);

    for (int T = 1; T <= Mx; T++){
        for (int i = 0; i < C; i++)
            cap[T].pb(max(0,min(M[i],(T - P[i])/S[i])));

        sort(cap[T].begin(),cap[T].end());
        if(accumulate(cap[T].end()-R, cap[T].end(),-B) >= 0)
            return T;
    }
}

int main(){

    int T;
    int R,B,C;

    cin >> T;
    for(int t = 0 ; t < T; t++){
        cin >> R >> B >> C;
        vector<int> M, S, P;

        for (int i = 0; i < C ; i++){
            int m,s,p;
            cin >> m >> s >> p;
            M.pb(m);
            S.pb(s);
            P.pb(p);
        }

        cout << "Case #" << t << ": " << solve(M, S, P, R, B, C)<< endl;
    }
    return 0;
}
