n = int(input())
for _ in range(n):
    l = int(input())
    array = list(map(int, input().split()))
    
    # 1  7
    i = 0
    if(sum(array) == len(array)):
        print(-1)
    else:
        while (len(array) != 1):
            print(array)
            if(i > len(array)):
                i = 0
            if(array[i] >= 2):
                if i == 0:
                    array[i + 1] += array[i] - 1
                    array.pop(i)
                elif :
                    array[i - 1] += 1
                    array.pop(i)
                else:
                    print(array[i])
                    array[i + 1] += array[i] - 1
                    array[i - 1] += 1
                    array.pop(i)
            i+= 1
        print(array)
