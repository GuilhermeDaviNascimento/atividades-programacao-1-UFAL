l1 = [2, 4, 3]
l2 = [5, 6, 4]
l1.reverse()
l2.reverse()
s_l1 = ""
s_l2 = ""
for i in l1:
    s_l1 += str(i)
for i in l2:
    s_l2 += str(i)
sum = int(s_l1) + int(s_l2)
result = []
for i in str(sum):
    result.append(i)
return result
