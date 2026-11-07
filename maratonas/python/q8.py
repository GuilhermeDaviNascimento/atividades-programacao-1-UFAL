def compact(array):
        i = 0
        while i < len(array) - 1:
            if array[i] == array[i + 1]:
                array.pop(i)
            else:
                i+=1
        string = ""
        for i in array:
            string +=i
        return string

n = int(input())
for l in range(n):
        s = str(input())
        array = []
        array_list = list(s)
        array_list_copia = list(s)
        array.append(compact(array_list_copia))

        count = 1
        while count <= len(array_list) - 2:
            if array_list[count] == "1":
                array_list[count] = "0"
            elif array_list[count] == "0":
                    array_list[count] = "1"
            array.append(compact(array_list))
            array_list = list(s)
            count+=1
        newarray = list(set(array))
        
        print(len(newarray))