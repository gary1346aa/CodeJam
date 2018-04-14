#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;

double solve(vector<pair<int,int> > rect, int P){

    int sum = 0;
    vector<double> range(rect.size(),0);

    for (int i = 0; i < rect.size(); i++){
        sum += 2*(rect[i].f + rect[i].s);
        range[i] = 2*(sqrt(rect[i].f*rect[i].f + rect[i].s*rect[i].s) - rect[i].f);
    }
    if (sum == P) return P;

    vector<double> DP(sum + 1,0);

    for (int i = 0; i < rect.size(); i++){
        int side = rect[i].f;
        for(int j = 0; j <= sum; j++)
            if (DP[j])
                DP[j + side] = max(DP[j + side], DP[j] + range[i]);

        DP[side] = max(DP[side], range[i]);
    }

    for (int i = 0; i < sum + 1; i++)
        if (DP[i] > 0 && 2*i + sum <= P)
            DP[i] += 2*i + sum;
        else
            DP[i] = 0;

    double sol = *max_element(DP.begin(),DP.end());
    return (sol > P) ? P : sol;
}

int main(){

    int T,N,P;
    cin >> T;
    for(int i = 0 ;i < T; i++){
        cin >> N >> P;
        vector<pair<int,int> > rect;
        for(int j = 0 ; j < N; j++){
            int a, b;
            cin >> a >> b;
            rect.pb({min(a,b),max(a,b)});
        }
        cout << "Case #" << i + 1 << ": " << solve(rect,P) << endl;
    }
    return 0;
}
