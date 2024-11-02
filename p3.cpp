/* This problem can be found at: https://neps.academy/exercise/331 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50000+10;

int n, m;
int grau[MAXN];

vector <int> grafo[MAXN];
vector <int> lista; // top sorting

priority_queue <int, vector <int>, greater <int>> fila;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        grau[b]++;
        grafo[a].push_back(b);
    }

    for (int i = 0; i < n; i++)
        if (grau[i] == 0)
            fila.push(i);
    
    while (!fila.empty()){
        int cur = fila.top();
        fila.pop();

        lista.push_back(cur);     

        for (int i = 0; i < grafo[cur].size(); i++){
            int v = grafo[cur][i];
            grau[v]--;

            if (grau[v] == 0)
                fila.push(v);
        }
    }

    if (lista.size() < n)
        cout << "*";
    else
        for (int i = 0; i < lista.size(); i++)
            cout << lista[i] << "\n";

    return 0;
}