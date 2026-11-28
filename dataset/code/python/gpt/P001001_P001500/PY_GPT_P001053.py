# problem title : Priority Queue Simulation
# Solve the stated task using standard input and standard output.
import heapq

def simulate_pq(operations):
    pq = []
    res = []
    for op in operations:
        parts = op.split()
        if parts[0] == "INSERT":
            heapq.heappush(pq, int(parts[1]))
        elif parts[0] == "EXTRACT_MIN":
            if pq:
                res.append(str(heapq.heappop(pq)))
            else:
                res.append("EMPTY")
        elif parts[0] == "PEEK":
            if pq:
                res.append(str(pq[0]))
            else:
                res.append("EMPTY")
    return res

if __name__ == '__main__':
    import sys
    lines = sys.stdin.read().splitlines()
    if lines:
        q = int(lines[0])
        ops = lines[1:q+1]
        out = simulate_pq(ops)
        for line in out:
            print(line)
