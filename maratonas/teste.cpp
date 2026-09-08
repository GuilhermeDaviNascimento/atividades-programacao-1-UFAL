#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<variant<int, string>> teste = {};
    teste.push_back(1);
    teste.push_back("teste");

    for (size_t i = 0; i < 2; i++)
    {
        visit([](auto valor) {
            cout << valor << "\n";
        }, teste[i]);
    }
    
}