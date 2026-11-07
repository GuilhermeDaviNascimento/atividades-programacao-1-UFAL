n = int(input())
cont = 0
for i in range(n):
    if i > 2:
        cont+=1
    if cont > 8:
        cont = 1
    if i + 3 == n:
        print(cont)
