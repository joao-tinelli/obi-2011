/* This problem can be found at: https://neps.academy/br/exercise/271 */

#include <bits/stdc++.h>
using namespace std;

int t;
stack <char> pilha;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++){
        string exp;
        cin >> exp;

        bool ok = true;

        for (int j = 0; j < exp.size(); j++){            

            if (exp[j] == '(' || exp[j] == '[' || exp[j] == '{'){
                pilha.push(exp[j]);

            } else {
                if (pilha.size() == 0){
                    ok = false;

                }else{
                    if (exp[j] == ')' && pilha.top() == '('){
                        pilha.pop();

                    } else if (exp[j] == ']' && pilha.top() == '['){
                        pilha.pop();

                    } else if (exp[j] == '}' && pilha.top() == '{'){
                        pilha.pop();

                    } else {
                        ok = false;
                    }
                }                
            }
        }

        if (!pilha.empty())
            ok = false;

        if (ok)
            cout << "S" << "\n";
        else
            cout << "N" << "\n";

        while (!pilha.empty()){
            pilha.pop();
        }
    }

    return 0;
}