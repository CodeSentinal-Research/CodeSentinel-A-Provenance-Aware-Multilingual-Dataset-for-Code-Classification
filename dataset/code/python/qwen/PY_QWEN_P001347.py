import sys

def solve():
    w1 = sys.stdin.readline().strip()
    w2 = sys.stdin.readline().strip()
    w3 = sys.stdin.readline().strip()
    
    letters = set(w1 + w2 + w3)
    if len(letters) > 10:
        print("IMPOSSIBLE")
        return
        
    letter_list = list(letters)
    assignment = {}
    used_digits = set()
    
    def backtrack(index):
        if index == len(letter_list):
            n1 = int("".join(str(assignment[c]) for c in w1))
            n2 = int("".join(str(assignment[c]) for c in w2))
            n3 = int("".join(str(assignment[c]) for c in w3))
            if n1 + n2 == n3:
                return True
            return False
            
        char = letter_list[index]
        for d in range(10):
            if d not in used_digits:
                if d == 0 and (char == w1[0] or char == w2[0] or char == w3[0]):
                    continue
                assignment[char] = d
                used_digits.add(d)
                if backtrack(index + 1):
                    return True
                used_digits.remove(d)
        return False
        
    if backtrack(0):
        for char in sorted(assignment.keys()):
            print(f"{char}={assignment[char]}")
    else:
        print("IMPOSSIBLE")

if __name__ == "__main__":
    solve()

