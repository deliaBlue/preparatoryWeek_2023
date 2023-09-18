import sys

def reverse(s):

    rev_s = "" 
    n = len(s)

    for i in range(n):
        rev_s += s[n -i - 1]

    return rev_s

s = sys.stdin.readline().strip()

while s != "":
    print(reverse(s))
    s = sys.stdin.readline().strip()
