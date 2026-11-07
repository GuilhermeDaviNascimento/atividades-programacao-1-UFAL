n = int(input())

for i in range(n):
    array = list(map(int, input().split()))
    sandwich = 0
    if array[0] <= array[1]:
        print(-1)
    else:
        print(min(array[1], array[0]-array[1]))´´