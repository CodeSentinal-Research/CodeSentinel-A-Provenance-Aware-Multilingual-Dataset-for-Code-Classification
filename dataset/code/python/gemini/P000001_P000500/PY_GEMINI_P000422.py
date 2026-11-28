import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        students = []
        idx = 1
        for _ in range(n):
            students.append((tokens[idx], float(tokens[idx+1]), float(tokens[idx+2])))
            idx += 3
        min_gpa = float(tokens[idx])
        max_inc = float(tokens[idx+1])
        for name, gpa, inc in students:
            if gpa >= min_gpa and inc <= max_inc:
                print(name)
if __name__ == '__main__':
    main()