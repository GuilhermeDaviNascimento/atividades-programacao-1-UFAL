n = int(input())
for _ in range(n):
    t = int(input())
    array = list(map(int, input().split()))
    abs_array = []
    negatives = 0
    
    for index in range(len(array) - 1):
        if array[index] < 0 and array[index + 1] < 0:
            array[index] = abs(array[index])
            array[index + 1] = abs(array[index + 1])
        
    for i in array:
        if i < 0:
            negatives+=1
        if(i != 0):
            abs_array.append(abs(i))
    abs_array.sort()
    
    if(t == 2 and 0 in array):
        print(abs(sum(abs_array)))
        break
        
    for i in range(negatives):
        abs_array[i] = -abs(abs_array[i])
    print(sum(abs_array))