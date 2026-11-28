import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = int(lines[0])
        h = s // 3600
        rem = s % 3600
        m = rem // 60
        sec = rem % 60
        print(f"{h} Hours {m} Minutes {sec} Seconds")
if __name__ == '__main__':
    main()