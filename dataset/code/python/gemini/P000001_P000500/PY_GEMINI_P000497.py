import sys
def main():
    s = sys.stdin.read().strip()
    if s:
        last_occ = {c: i for i, c in enumerate(s)}
        # Monotonic stack to track visible elements
        stack = []
        seen = set()
        for i, c in enumerate(s):
            if c not in seen:
                # Maintain monotonic stack property by popping smaller elements
                while stack and stack[-1] > c and i < last_occ[stack[-1]]:
                    seen.remove(stack.pop())
                seen.add(c)
                stack.append(c)
        print("".join(stack))
if __name__ == '__main__':
    main()