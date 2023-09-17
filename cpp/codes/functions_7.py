import sys

def integer_division(x):
    return x // 2

def decimal_division(x):
    return x / 2

x = sys.stdin.readline().strip()

print("The integer division is:", integer_division(int(x)))
print("The decimal division is:", decimal_division(int(x)))

