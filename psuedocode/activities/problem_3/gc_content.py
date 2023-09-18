import sys

def gc_content(s):
    
    gc = 0

    for i in range(len(s)):
    
        if s[i] in ("G", "C"):
            gc += 1
    gc /= len(s)
    
    return gc * 100

s = sys.stdin.readline().strip()

while s != "":
    print(f'{gc_content(s):.3g}%')
    s = sys.stdin.readline().strip()
