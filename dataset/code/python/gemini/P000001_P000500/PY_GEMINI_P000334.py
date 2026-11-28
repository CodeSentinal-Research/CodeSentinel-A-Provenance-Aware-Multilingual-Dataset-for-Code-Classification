import sys

def shortest_way(source: str, target: str) -> int:
    i = 0
    count = 0
    src_set = set(source)
    while i < len(target):
        if target[i] not in src_set:
            return -1
        j = 0
        while j < len(source) and i < len(target):
            if source[j] == target[i]:
                i += 1
            j += 1
        count += 1
    return count

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print(shortest_way(lines[0], lines[1]))

if __name__ == '__main__':
    main()