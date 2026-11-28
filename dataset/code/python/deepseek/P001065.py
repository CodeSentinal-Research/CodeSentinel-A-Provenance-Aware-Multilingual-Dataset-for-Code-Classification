def count_edges():
    N = int(input())
    total_edges = 0
    for _ in range(N):
        line = input().split()
        total_edges += len(line) - 1  
    print(total_edges // 2)  

if __name__ == '__main__':
    count_edges()