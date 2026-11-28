import sys

def exclusive_time(n: int, logs):
    res = [0] * n
    stack = []
    prev_time = 0
    for log in logs:
        parts = log.split(':')
        fn_id, action, timestamp = int(parts[0]), parts[1], int(parts[2])
        if action == "start":
            if stack:
                res[stack[-1]] += timestamp - prev_time
            stack.append(fn_id)
            prev_time = timestamp
        else:
            res[stack.pop()] += timestamp - prev_time + 1
            prev_time = timestamp + 1
    return res

def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        logs = lines[1:]
        print(" ".join(map(str, exclusive_time(n, logs))))

if __name__ == '__main__':
    main()