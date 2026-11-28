# problem title : Design Undo Redo Editor
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        history = [""]
        cur = 0
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "type":
                text = tokens[idx+1]
                history = history[:cur+1]
                history.append(history[-1] + text)
                cur += 1
                idx += 2
            elif cmd == "undo":
                if cur > 0: cur -= 1
                idx += 1
            elif cmd == "redo":
                if cur + 1 < len(history): cur += 1
                idx += 1
            elif cmd == "print":
                print(history[cur])
                idx += 1
if __name__ == '__main__':
    main()
