# problem title : Design Browser Tabs Manager
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        tabs = []
        cur_idx = 0
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "open":
                url = tokens[idx+1]
                tabs.append(url)
                cur_idx = len(tabs) - 1
                idx += 2
            elif cmd == "close":
                i = int(tokens[idx+1])
                tabs.pop(i)
                if cur_idx >= len(tabs): cur_idx = max(0, len(tabs) - 1)
                idx += 2
            elif cmd == "switch":
                i = int(tokens[idx+1])
                cur_idx = i
                idx += 2
            elif cmd == "moveLeft":
                i = int(tokens[idx+1])
                if i > 0:
                    tabs[i], tabs[i-1] = tabs[i-1], tabs[i]
                    if cur_idx == i: cur_idx = i - 1
                    elif cur_idx == i - 1: cur_idx = i
                idx += 2
            elif cmd == "moveRight":
                i = int(tokens[idx+1])
                if i < len(tabs) - 1:
                    tabs[i], tabs[i+1] = tabs[i+1], tabs[i]
                    if cur_idx == i: cur_idx = i + 1
                    elif cur_idx == i + 1: cur_idx = i
                idx += 2
            elif cmd == "current":
                print(tabs[cur_idx] if tabs else "")
                idx += 1
if __name__ == '__main__':
    main()
