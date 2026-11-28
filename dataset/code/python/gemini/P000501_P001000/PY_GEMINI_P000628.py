import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        text = []
        cursor = 0
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "addText":
                s = tokens[idx+1]
                text[cursor:cursor] = list(s)
                cursor += len(s)
                idx += 2
            elif cmd == "deleteText":
                k = int(tokens[idx+1])
                del_cnt = min(k, cursor)
                del text[cursor-del_cnt:cursor]
                cursor -= del_cnt
                print(del_cnt)
                idx += 2
            elif cmd == "cursorLeft":
                k = int(tokens[idx+1])
                cursor = max(0, cursor - k)
                l = max(0, cursor - 10)
                print("".join(text[l:cursor]))
                idx += 2
            elif cmd == "cursorRight":
                k = int(tokens[idx+1])
                cursor = min(len(text), cursor + k)
                l = max(0, cursor - 10)
                print("".join(text[l:cursor]))
                idx += 2
if __name__ == '__main__':
    main()