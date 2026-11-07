n = int(input())
for i in range(n):
        rodadas = list(map(int, input().split()))
        if rodadas[2] >= rodadas[1]:
            print("S" * sum(rodadas))
        elif rodadas[1] >= rodadas[2]:
            print("R" * sum(rodadas))
        else:
            print("P" * sum(rodadas))