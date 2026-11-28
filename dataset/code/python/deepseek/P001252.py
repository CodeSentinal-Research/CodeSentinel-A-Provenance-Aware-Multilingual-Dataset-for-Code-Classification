def max_chain_length(n, pairs):
    sorted_pairs = sorted(pairs, key=lambda pair: pair[0])
    
    chain_length = 1
    
    current_chain_end = sorted_pairs[0][1]
    
    for i in range(1, n):
        if sorted_pairs[i][0] > current_chain_end:
            current_chain_end = sorted_pairs[i][1]
            chain_length += 1
    
    return chain_length

def main():
    n = int(input().strip())
    pairs = []
    for _ in range(n):
        pair = list(map(int, input().strip().split()))
        pairs.append(pair)
    print(max_chain_length(n, pairs))

if __name__ == "__main__":
    main()