import sys

def dna_to_rna(s):
    ss = ""

    for i in s:
        if i == "T":
            ss += "U"
        else:
            ss += i
    return ss

s = sys.stdin.readline().strip()

while s != "":
    print(dna_to_rna(s))
    s = sys.stdin.readline().strip();

