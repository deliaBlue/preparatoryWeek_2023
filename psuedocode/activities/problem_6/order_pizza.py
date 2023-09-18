import sys

def order_pizza(L):
    D = {}

    for i in L:
        if i in D:
            D[i] += 1
        else:
            D[i] = 1
    return D

s = sys.stdin.readline().strip()
L = []

while s != "":

    L.append(s)
    s = sys.stdin.readline().strip()

D = order_pizza(L)

for key in sorted(D):
    print(f"{key}: {D[key]}")

