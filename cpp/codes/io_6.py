import sys

x = sys.stdin.readline().strip()
y = sys.stdin.readline().strip()

print()

for i in range(int(y) + 1):
    m = int(x) * i
    print(x, "*", i, "=", m) 
