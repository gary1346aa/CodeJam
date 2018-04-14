#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second

using namespace std;

bool solve(vector<vector<bool> > A, int H, int V, int chop){
    if (chop%((H+1)*(V+1)) != 0)
        return false;

    int val = chop/((H+1)*(V+1));
    vector<int> hline, vline;

    int tmp = -1;
    for (int h = 0; h < H; h++)
    {
        int h_acc = 0;
        while (h_acc < (chop / (H+1))){
            tmp ++ ;
            for (int j = 0 ; j < A[0].size(); j++)
                h_acc += A[tmp][j];
            if (h_acc > (chop / (H+1)))
                return false;
            else if (h_acc < (chop / (H+1)) && tmp == A.size())
                return false;
        }
        hline.pb(tmp);
    }
    tmp = -1;
    for (int v = 0; v < V; v++)
    {
        vector<int> v_acc(hline.size()+1, 0);
        bool test = false;
        while (!test){
            tmp ++ ;

            for(int i = 0; i <= hline[0]; i++){
                v_acc[0] += A[i][tmp];
            }
            for(int line = 1; line < hline.size(); line++){

                int st = hline[line-1] + 1, ed = hline[line];

                for (int i = st; i <= ed; i++){

                    v_acc[line] += A[i][tmp];
                }
            }

            for(int i = hline[hline.size()-1] + 1; i < A.size(); i++)
                v_acc[hline.size()] += A[i][tmp];

            test = true;
            for (int i = 0; i < v_acc.size(); i++){
                if (v_acc[i] != val) {
                    test = false;
                    break;
                }
            }

            if (!test && tmp == A[0].size())
                return false;

        }
        vline.pb(tmp);
    }



    return true;
}
int main(){

    int T;
    int R,C,H,V;

    cin >> T;
    for(int t = 0 ; t < T; t++){
        cin >> R >> C >> H >> V;
        vector<vector<bool> > A;

        int cnt = 0;
        for (int i = 0; i< R ; i++){
            vector<bool> tmp;
            for (int j = 0 ; j < C; j++){
                char chr;
                cin >> chr;
                if (chr == '.')
                    tmp.pb(0);
                else{
                    tmp.pb(1);
                    cnt ++;
                }
            }
            A.pb(tmp);
        }
        cout << "Case #" << t+1 << ": ";
        if (!solve(A,H,V,cnt)) cout << "IM";
        cout <<"POSSIBLE"<< endl;
    }
    return 0;
}
