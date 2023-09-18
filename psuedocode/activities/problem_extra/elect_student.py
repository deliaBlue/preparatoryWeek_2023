import sys

def elect_student(L):
    votes = 0
    winner = ""
    L.sort()

    for x in L:

        if winner == "":
            winner = x
            current_votes = 0
            current_student = x

        if current_student == x:
            current_votes += 1
        else:
            if current_votes > votes:
                winner = current_student
                votes = current_votes
        
            current_votes = 1
            current_student = x

    if current_votes > votes:
        return current_student

    return winner

L = []
s = sys.stdin.readline().strip()

while s != "":
    L.append(s)
    s = sys.stdin.readline().strip()


print(elect_student(L))
