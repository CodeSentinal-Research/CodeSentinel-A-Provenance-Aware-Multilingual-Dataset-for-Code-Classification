def num_equiv_domino_pairs(N, dominoes):
    count_dict = {}
    for domino in dominoes:
        min_num = min(domino)
        max_num = max(domino)
        key = (min_num, max_num)
        count_dict[key] = count_dict.get(key, 0) + 1

    return sum(count * (count - 1) // 2 for count in count_dict.values())

def main():
    N = int(input().strip())
    dominoes = [tuple(map(int, input().strip().split())) for _ in range(N)]
    print(num_equiv_domino_pairs(N, dominoes))

if __name__ == "__main__":
    main()