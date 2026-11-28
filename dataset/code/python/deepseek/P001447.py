def are_similar(sentence1, sentence2, pairs):
    if sentence1 == sentence2:
        return "YES"

    word_map = {}
    for pair in pairs:
        w1, w2 = pair
        if w1 not in word_map:
            word_map[w1] = w2
        if w2 not in word_map:
            word_map[w2] = w1

    for word in sentence1.split():
        if word not in word_map:
            return "NO"

    return "YES"

def main():
    sentence1 = input().strip()
    sentence2 = input().strip()
    pairs_count = int(input().strip())
    pairs = []
    for _ in range(pairs_count):
        pair = input().strip().split()
        pairs.append((pair[0], pair[1]))

    result = are_similar(sentence1, sentence2, pairs)
    print(result)

if __name__ == "__main__":
    main()