import sys

def find_coding_region(s):
    i = 0
    while i + 2 <= len(s):
        if s[i:i+3] == "ATG":
            j = i + 3
            while j + 2 <= len(s):
                if s[j: j+3] in {"TAA", "TAG", "TGA"}:
                    return s[i+3 : j]
                j += 3
        i += 1 
    return ""


s = sys.stdin.readline()

while s != "":
    print(find_coding_region(s))
    s = sys.stdin.readline()
