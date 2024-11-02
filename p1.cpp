/* This problem can be found at: https://neps.academy/exercise/537 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1e3+10;

int n;
int pos[MAXN][MAXN];

ll linha[MAXN];
ll coluna[MAXN];

ll diagonal_p;
ll diagonal_s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> pos[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            linha[i] += pos[i][j];
            coluna[i] += pos[j][i];
        }
    }

    for (int i = 0; i < n; i++){
        diagonal_p += pos[i][i];
        diagonal_s += pos[i][n-i-1];
    }

    for (int i = 0; i < n; i++){
        if (linha[i] != coluna[i] || linha[i] != diagonal_p || linha[i] != diagonal_s || diagonal_p != diagonal_s){
            cout << "0";
            return 0;
        }   
    }

    cout << diagonal_p;
}