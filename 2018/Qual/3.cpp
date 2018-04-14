#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second

using namespace std;


int select(bool (&A)[15][15]){
	
	int max = -1, ind = -1;
	
	for (int i = 1; i < 14; i++){
		for (int j = 1; j < 14 ; j++){
			int tmp = !A[i - 1][j] + !A[i][j] + !A[i + 1][j]
				+ !A[i - 1][j - 1] + !A[i][j - 1] + !A[i + 1][j - 1]
				+ !A[i - 1][j + 1] + !A[i][j + 1] + !A[i + 1][j + 1];

			if (tmp == 9) 
				return i*15 + j;
			else if (tmp > max){
				max = tmp;
				ind =  i*15 + j;
			}
		}
	}
	
	return ind;
}



int main() {
	int t, a;
	cin >> t;
	
	for (int i = 0; i<t ; i++){
		cin >> a;
		bool A[15][15] = {};
		while(true){
		int ind = select(A);
		cout << (ind/15) + 3 << " " << (ind%15) + 3<<endl;
		int row, col;
		cin >> row >> col;
		if(row == 0 && col == 0)break;
		else if (row == -1 && col == -1)break;
		A[row - 3][col - 3] = true;
		}
	}
	
	return 0;
}