#include <bits/stdc++.h>
using namespace std;

int main () 
{

    int n;
    cin >> n;

    
    for (size_t i = 0; i < n; i++)
    {
        vector<int> fila = {};
        int n1, n2;
        cin >> n1 >> n2;

        string temp;
        cin >> temp;

        cout << temp;
        

        for (size_t i = 0; i < temp.size(); i++)
        {
            fila.push_back(atoi(temp[i]));
        }

        for (size_t i = 0; i < fila.size(); i++)
        {
            cout << fila[i] << " , ";
        }
        
        
        
    }

}