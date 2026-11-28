import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    cap = int(input_data[0])
    q = int(input_data[1])
    idx = 2
    queue = []
    for _ in range(q):
        op = input_data[idx]; idx += 1
        if op == "enqueue":
            val = int(input_data[idx]); idx += 1
            if len(queue) < cap: queue.append(val)
        elif op == "dequeue":
            print(queue.pop(0) if queue else -1)
        elif op == "front":
            print(queue[0] if queue else -1)
        elif op == "isEmpty":
            print("true" if not queue else "false")
solve()
