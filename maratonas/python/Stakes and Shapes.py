n = int(input())
for _ in range(n):
     x, y, z = map(int, input().split())
     if y >= z:
          print("R" * (x + y  + z) )
     elif x >= y:
          print("P" * (x + y  + z) )
     else:
          print("S" * (x + y  + z) )