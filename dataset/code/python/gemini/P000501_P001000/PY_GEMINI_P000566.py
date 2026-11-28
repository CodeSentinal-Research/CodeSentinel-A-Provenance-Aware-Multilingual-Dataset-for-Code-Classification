import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        start_gene = tokens[0]
        end_gene = tokens[1]
        n = int(tokens[2])
        bank = set(tokens[3:3+n])
        if end_gene not in bank:
            print(-1)
            return
        q = deque([(start_gene, 0)])
        visited = {start_gene}
        while q:
            gene, step = q.popleft()
            if gene == end_gene:
                print(step)
                return
            for i in range(8):
                for c in "ACGT":
                    nxt = gene[:i] + c + gene[i+1:]
                    if nxt in bank and nxt not in visited:
                        visited.add(nxt)
                        q.append((nxt, step + 1))
        print(-1)
if __name__ == '__main__':
    main()