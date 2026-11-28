import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        home = tokens[0]
        q = int(tokens[1])
        idx = 2
        history = [home]
        curr = 0
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "visit":
                url = tokens[idx+1]
                history = history[:curr+1]
                history.append(url)
                curr += 1
                idx += 2
            elif cmd == "back":
                steps = int(tokens[idx+1])
                curr = max(0, curr - steps)
                print(history[curr])
                idx += 2
            elif cmd == "forward":
                steps = int(tokens[idx+1])
                curr = min(len(history) - 1, curr + steps)
                print(history[curr])
                idx += 2
if __name__ == '__main__':
    main()