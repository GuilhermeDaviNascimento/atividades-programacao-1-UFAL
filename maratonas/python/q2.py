n = list(map(int, input().split()))

cartelas = []

for i in range(n[0]):
    cartelas.append(list(map(int, input().split())))

num_sorteados = list(map(int, input().split()))

vencedor = []
for j in range(n[2]):
    for indice, i in enumerate(cartelas):
        if num_sorteados[j] in i:
            i.remove(num_sorteados[j])
            if len(i) == 0 :
                vencedor.append(indice + 1)
    if len(vencedor) > 0:
        for i in vencedor:
            print(i, end=" ")
        break

