import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    homepage = input_data[0]
    q = int(input_data[1])
    idx = 2
    history = [homepage]
    curr = 0
    for _ in range(q):
        op = input_data[idx]; idx += 1
        if op == "visit":
            url = input_data[idx]; idx += 1
            history = history[:curr+1]
            history.append(url)
            curr += 1
        elif op == "back":
            steps = int(input_data[idx]); idx += 1
            curr = max(0, curr - steps)
            print(history[curr])
        elif op == "forward":
            steps = int(input_data[idx]); idx += 1
            curr = min(len(history) - 1, curr + steps)
            print(history[curr])
solve()
