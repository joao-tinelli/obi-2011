/* This problem can be found at: https://neps.academy/exercise/298 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500+10;
const int MAXM = 124750+10;

struct t_edge{
    int a, b, w;
};

bool comp (t_edge x, t_edge y){
    return x.w < y.w;
}

int n, m;
int mst_cost;

int pai[MAXN];
int siize[MAXN];

t_edge edge[MAXM];
t_edge mst[MAXN];

int find (int x){
    return (pai[x] == x ? x: pai[x] = find(pai[x]));
}

void merge (int i, int j){
    i = find(i), j = find(j);

    if (i == j)
        return;

    if (siize[i] > siize[j]){
        siize[i] += siize[j];
        pai[j] = i;

    }else{
        siize[j] += siize[i];
        pai[i] = j;
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        pai[i] = i;
        siize[i] = 0;
    }

    for (int i = 1; i <= m; i++)
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    
    sort (edge+1, edge+m+1, comp);

    int pos = 0;

    for (int i = 1; i <= m; i++){
        int a = find(edge[i].a);
        int b = find(edge[i].b);

        if (a != b){
            merge(a,b);
            mst[++pos] = edge[i];
            mst_cost += edge[i].w;
        }
    }

    cout << mst_cost;
    
    return 0;
}