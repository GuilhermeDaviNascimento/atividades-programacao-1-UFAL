s = "pwwkew"
letras = []
for i in s:
    if not i in letras:
        letras.append(i)
        print(i)

resposta = []

for i in letras:
    for j in s:
        if i == j:
            print(j)