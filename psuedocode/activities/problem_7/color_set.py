import sys

def color_set(L):
    S = set() 

    for i in L:
        if i != "Blue":
            S.add(i)
    return sorted(S)


L = []
s = sys.stdin.readline().strip()

while s != "":
    L.append(s)
    s = sys.stdin.readline().strip()

for i in color_set(L):
    print(i)
