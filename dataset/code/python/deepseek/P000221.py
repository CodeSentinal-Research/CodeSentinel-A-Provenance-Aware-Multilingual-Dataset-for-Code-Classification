def find_longest_chain(pairs):
    sorted_pairs = sorted(pairs, key=lambda x: x[1])

    current_chain_length = 1
    max_chain_length = 1

    current_pair = sorted_pairs[0]
    next_pair = sorted_pairs[1]

    if next_pair[0] < current_pair[1]:
        current_chain_length += 1
        max_chain_length = max(max_chain_length, current_chain_length)

    for i in range(1, len(sorted_pairs)):
        current_pair = sorted_pairs[i]

        if next_pair[0] < current_pair[1]:
            current_chain_length += 1
            max_chain_length = max(max_chain_length, current_chain_length)
        else:
            current_chain_length = 2

    return max_chain_length


n = int(input())
pairs = []
for _ in range(n):
    a, b = map(int, input().split())
    pairs.append((a, b))

print(find_longest_chain(pairs))