import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        windows = {} # winId: {"history": [url], "cur": 0}
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "newWindow":
                w_id = int(tokens[idx+1]) if tokens[idx+1].isdigit() else len(windows) + 1
                home = tokens[idx+2] if tokens[idx+1].isdigit() else tokens[idx+1]
                windows[w_id] = {"history": [home], "cur": 0}
                idx += 3 if tokens[idx+1].isdigit() else 2
            elif cmd == "visit":
                w_id = int(tokens[idx+1])
                url = tokens[idx+2]
                w = windows[w_id]
                w["history"] = w["history"][:w["cur"]+1] + [url]
                w["cur"] += 1
                idx += 3
            elif cmd == "back":
                w_id = int(tokens[idx+1])
                steps = int(tokens[idx+2])
                w = windows[w_id]
                w["cur"] = max(0, w["cur"] - steps)
                print(w["history"][w["cur"]])
                idx += 3
            elif cmd == "forward":
                w_id = int(tokens[idx+1])
                steps = int(tokens[idx+2])
                w = windows[w_id]
                w["cur"] = min(len(w["history"]) - 1, w["cur"] + steps)
                print(w["history"][w["cur"]])
                idx += 3
            elif cmd == "currentPage":
                w_id = int(tokens[idx+1])
                w = windows[w_id]
                print(w["history"][w["cur"]])
                idx += 2
            elif cmd == "closeWindow":
                w_id = int(tokens[idx+1])
                if w_id in windows: del windows[w_id]
                idx += 2
if __name__ == '__main__':
    main()