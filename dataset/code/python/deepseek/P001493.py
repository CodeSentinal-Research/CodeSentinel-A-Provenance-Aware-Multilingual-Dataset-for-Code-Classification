def shortest_distance(s, c):
    prev_pos = {ch: -1 for ch in s}
    min_dist = {ch: float('inf') for ch in s}
    min_dist[c] = 0

    for i, ch in enumerate(s):
        if ch == c:
            min_dist[ch] = min_dist[ch]
        else:
            min_dist[ch] = min_dist[ch] + 1

    for i, ch in enumerate(s[::-1]):
        if ch == c:
            min_dist[ch] = min_dist[ch]
        else:
            min_dist[ch] = min_dist[ch] + 1

    return min_dist

def main():
    s = input().strip()
    c = input().strip()[0]
    min_dist = shortest_distance(s, c)
    for ch in s:
        print(min_dist[ch], end=' ')

if __name__ == "__main__":
    main()