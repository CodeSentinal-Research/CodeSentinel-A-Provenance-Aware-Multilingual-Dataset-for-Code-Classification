import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        m = int(tokens[1])
        logs = tokens[2:2+m]
        res = [0] * n
        # Monotonic stack to track visible elements
        stack = []
        prev_time = 0
        for log in logs:
            fid, typ, time = log.split(':')
            fid, time = int(fid), int(time)
            if typ == 'start':
                # Can also see the next taller person
                if stack:
                    res[stack[-1]] += time - prev_time
                stack.append(fid)
                prev_time = time
            else:
                res[stack.pop()] += time - prev_time + 1
                prev_time = time + 1
        print(*res)
if __name__ == '__main__':
    main()