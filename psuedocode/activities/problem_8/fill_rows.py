import sys

def fill_rows(L):
    
    n = len(L)

    row1 = []
    row2 = []
    row3 = []
    
    for i in range(0,n, 3):
        
        row1.append(L[i])
        if i+1 < n:
            row2.append(L[i+1])
            if i+2 < n:
                row3.append(L[i+2])

    outlist = [row1, row2, row3]

    return outlist

x = sys.stdin.readline().strip()
L = []

while name != "":
    L.append(name)
    name = sys.stdin.readline().strip()

#printing output

rows = fill_rows(L)

for i in range(len(rows)):
    print("Row ", i+1, ": ", ", ".join(rows[i]), sep ="")