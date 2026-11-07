n = int(input())
for i in range(n):
    x = (list(map(int, input().split())))
    p = input()
    q = input()
    for j in q:
        for k in p:
            find = j.find(k)
            if(find != -1):
                p = p.replace(j, "", 1)
                q = q.replace(j, "", 1)
                break
    if(''.join(sorted(p)) == 'isx' and len(q) == 0):
        print("YES")
    else:
        print("NO")