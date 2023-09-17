import sys

def maximum(L):
    m = L[0]

    for i in range(1, len(L)):
        if m < L[i]:
            m = L[i]
    return m

x = sys.stdin.readline().strip()
L = []

while x != "":
    L.append(int(x))
    x = sys.stdin.readline().strip()

print(maximum(L))
