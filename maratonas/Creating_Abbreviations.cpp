#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        vector<string> palavras;
        vector<string> abreviacoes;
        vector<string> abreviacoes_para_achar;

        string result = "no";

        for (size_t j = 0; j < n1; j++)
        {
            string palavra;
            cin >> palavra;
            palavras.push_back(palavra);
        }

        for (size_t j = 0; j < n2; j++)
        {
            string abreviacao;
            cin >> abreviacao;
            abreviacoes.push_back(abreviacao);
        }

        for (size_t j = 0; j < palavras.size(); j++)
        {
            abreviacoes_para_achar.push_back(
                string(1, toupper(palavras[j][0]))
            );
        }

        sort(abreviacoes_para_achar.begin(), abreviacoes_para_achar.end());

        auto it = unique(
            abreviacoes_para_achar.begin(),
            abreviacoes_para_achar.end()
        );

        abreviacoes_para_achar.erase(
            it,
            abreviacoes_para_achar.end()
        );

        int tamanho = abreviacoes_para_achar.size();

        for (size_t j = 0; j < tamanho; j++)
        {
            for (size_t k = 0; k < tamanho; k++)
            {
                abreviacoes_para_achar.push_back(
                    abreviacoes_para_achar[j] +
                    abreviacoes_para_achar[k]
                );
            }
        }

        // Procura as abreviações
        for (size_t k = 0; k < abreviacoes.size(); k++)
        {
            for (size_t l = 0; l < abreviacoes_para_achar.size(); l++)
            {
                if (abreviacoes[k] == abreviacoes_para_achar[l])
                {
                    result = "yes";
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}