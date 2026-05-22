/* -------------------------------------------------------
 * 1. SOMA DOS ELEMENTOS
 * Retorna a soma de todos os elementos do array.
 * ------------------------------------------------------- */
int soma(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + soma(arr, n - 1);
}
 
/* -------------------------------------------------------
 * 2. MAIOR ELEMENTO
 * Retorna o maior valor encontrado no array.
 * ------------------------------------------------------- */
int maior(int arr[], int n) {
    if (n == 1) return arr[0];
    int m = maior(arr, n - 1);
    return arr[n - 1] > m ? arr[n - 1] : m;
}
 
/* -------------------------------------------------------
 * 3. MENOR ELEMENTO
 * Retorna o menor valor encontrado no array.
 * ------------------------------------------------------- */
int menor(int arr[], int n) {
    if (n == 1) return arr[0];
    int m = menor(arr, n - 1);
    return arr[n - 1] < m ? arr[n - 1] : m;
}
 
/* -------------------------------------------------------
 * 4. BUSCA LINEAR
 * Retorna o índice do elemento se encontrado, -1 caso contrário.
 * ------------------------------------------------------- */
int busca(int arr[], int n, int alvo) {
    if (n == 0) return -1;
    if (arr[n - 1] == alvo) return n - 1;
    return busca(arr, n - 1, alvo);
}
 
/* -------------------------------------------------------
 * 5. BUSCA BINÁRIA (array ordenado)
 * Retorna o índice do elemento se encontrado, -1 caso contrário.
 * ------------------------------------------------------- */
int busca_binaria(int arr[], int inicio, int fim, int alvo) {
    if (inicio > fim) return -1;
    int meio = (inicio + fim) / 2;
    if (arr[meio] == alvo) return meio;
    if (alvo < arr[meio])
        return busca_binaria(arr, inicio, meio - 1, alvo);
    return busca_binaria(arr, meio + 1, fim, alvo);
}
 
/* -------------------------------------------------------
 * 6. INVERSÃO DO ARRAY (in-place)
 * Inverte os elementos do array sem usar array auxiliar.
 * ------------------------------------------------------- */
void inverter(int arr[], int inicio, int fim) {
    if (inicio >= fim) return;
    int tmp   = arr[inicio];
    arr[inicio] = arr[fim];
    arr[fim]  = tmp;
    inverter(arr, inicio + 1, fim - 1);
}
 
/* -------------------------------------------------------
 * 7. VERIFICAR SE ESTÁ ORDENADO (crescente)
 * Retorna 1 se ordenado, 0 caso contrário.
 * ------------------------------------------------------- */
int ordenado(int arr[], int n) {
    if (n <= 1) return 1;
    if (arr[n - 2] > arr[n - 1]) return 0;
    return ordenado(arr, n - 1);
}
 
/* -------------------------------------------------------
 * 8. CONTAR OCORRÊNCIAS
 * Conta quantas vezes 'alvo' aparece no array.
 * ------------------------------------------------------- */
int contar(int arr[], int n, int alvo) {
    if (n == 0) return 0;
    int conta = (arr[n - 1] == alvo) ? 1 : 0;
    return conta + contar(arr, n - 1, alvo);
}
 
/* -------------------------------------------------------
 * 9. COPIAR ARRAY
 * Copia os elementos de 'origem' para 'destino'.
 * ------------------------------------------------------- */
void copiar(int origem[], int destino[], int n) {
    if (n == 0) return;
    destino[n - 1] = origem[n - 1];
    copiar(origem, destino, n - 1);
}
 
/* -------------------------------------------------------
 * 10. IMPRIMIR ARRAY
 * Imprime todos os elementos do array.
 * ------------------------------------------------------- */
void imprimir(int arr[], int n) {
    if (n == 0) {
        printf("\n");
        return;
    }
    printf("%d ", arr[0]);
    imprimir(arr + 1, n - 1);
}
 
/* -------------------------------------------------------
 * 14. SUBSTITUIR ELEMENTO
 * Substitui todas as ocorrências de 'velho' por 'novo'.
 * ------------------------------------------------------- */
void substituir(int arr[], int n, int velho, int novo) {
    if (n == 0) return;
    if (arr[n - 1] == velho) {
        arr[n - 1] = novo;
    }
    substituir(arr, n - 1, velho, novo);
}

/* -------------------------------------------------------
 * 15. COMPARAR ARRAYS
 * Retorna 1 se forem exatamente iguais, 0 caso contrário.
 * ------------------------------------------------------- */
int comparar(int arr1[], int arr2[], int n) {
    if (n == 0) return 1;
    if (arr1[n - 1] != arr2[n - 1]) return 0;
    return comparar(arr1, arr2, n - 1);
}

/* -------------------------------------------------------
 * 12. VERIFICAR PALÍNDROMO
 * Retorna 1 se o array for um palíndromo, 0 caso contrário.
 * ------------------------------------------------------- */
int palindromo(int arr[], int inicio, int fim) {
    if (inicio >= fim) return 1;
    if (arr[inicio] != arr[fim]) return 0;
    return palindromo(arr, inicio + 1, fim - 1);
}

/* -------------------------------------------------------
 * 11. IMPRIMIR ARRAY REVERSO
 * Imprime os elementos do array de trás para frente.
 * ------------------------------------------------------- */
void imprimir_reverso(int arr[], int n) {
    if (n == 0) {
        printf("\n");
        return;
    }
    printf("%d ", arr[n - 1]);
    imprimir_reverso(arr, n - 1);
}

/* -------------------------------------------------------
 * 16. BUBBLE SORT (Versão Recursiva)
 * Ordena o array empurrando o maior elemento para o final.
 * ------------------------------------------------------- */
void bubble_sort(int arr[], int n) {
    // Caso base: array de tamanho 1 ou 0 já está ordenado
    if (n <= 1) return;

    // Passagem única: move o maior elemento da rodada para a última posição
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Chamada recursiva ignorando o último elemento (que já é o maior)
    bubble_sort(arr, n - 1);
}


/* -------------------------------------------------------
 * FUNÇÃO AUXILIAR: MERGE
 * Mescla duas sub-listas ordenadas de volta no array original.
 * ------------------------------------------------------- */
void merge(int arr[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int esq[n1], dir[n2]; // Arrays temporários (VLA - Variable Length Array)

    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++) esq[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++) dir[j] = arr[meio + 1 + j];

    // Mescla os arrays temporários de volta no array original
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (esq[i] <= dir[j]) {
            arr[k++] = esq[i++];
        } else {
            arr[k++] = dir[j++];
        }
    }

    // Copia os elementos restantes, se houver
    while (i < n1) arr[k++] = esq[i++];
    while (j < n2) arr[k++] = dir[j++];
}

/* -------------------------------------------------------
 * 17. MERGE SORT
 * Ordena dividindo o array na metade e mesclando (O(n log n)).
 * ------------------------------------------------------- */
void merge_sort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        // Evita overflow de (inicio + fim) / 2
        int meio = inicio + (fim - inicio) / 2;

        // Ordena a primeira e a segunda metade
        merge_sort(arr, inicio, meio);
        merge_sort(arr, meio + 1, fim);

        // Mescla as metades ordenadas
        merge(arr, inicio, meio, fim);
    }
}


/* -------------------------------------------------------
 * FUNÇÃO AUXILIAR: PARTICIONAR
 * Escolhe o pivô (último elemento) e coloca os menores à
 * esquerda e os maiores à direita dele.
 * ------------------------------------------------------- */
int particionar(int arr[], int inicio, int fim) {
    int pivo = arr[fim];
    int i = inicio - 1; // Índice do menor elemento

    for (int j = inicio; j < fim; j++) {
        // Se o elemento atual for menor que o pivô
        if (arr[j] < pivo) {
            i++;
            // Troca arr[i] e arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Coloca o pivô na posição correta (i + 1)
    int temp = arr[i + 1];
    arr[i + 1] = arr[fim];
    arr[fim] = temp;

    return i + 1; // Retorna o índice do pivô
}

/* -------------------------------------------------------
 * 18. QUICK SORT
 * Ordena usando o conceito de particionamento (O(n log n)).
 * ------------------------------------------------------- */
void quick_sort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        // Índice de particionamento, arr[p] já está na posição certa
        int pivo_idx = particionar(arr, inicio, fim);

        // Ordena recursivamente antes e depois da partição
        quick_sort(arr, inicio, pivo_idx - 1);
        quick_sort(arr, pivo_idx + 1, fim);
    }
}
