#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second

using namespace std;
 
void solve(vector<int> s){
	vector<int> odd;
	vector<int> even;
	
	for (int i = 0;i < s.size(); i++){
		if (i % 2 == 0)
			even.pb(s[i]);
		else
			odd.pb(s[i]);
	}
	
	sort(even.begin(),even.end());
	sort(odd.begin(),odd.end());
	
	int tmp = -1;
	for (int i = 0;i < s.size(); i++){
	    if ( ((i%2 == 0) ? even[i/2] : odd[i/2]) < tmp){
		cout << i - 1 <<endl;
	    	return;
	    }
	    else
		tmp = (i%2 == 0) ? even[i/2] : odd[i/2];
	}
	cout << "OK" <<endl;
	return ;
}


int main(){
    int T, L;
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> L;
        vector<int> s(L);
        for (int j = 0; j < L; j++)
        	cin >> s[j];
        cout << "case #" << i + 1 << ": ";
        solve(s);
    }
    return 0;
}