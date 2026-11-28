from collections import Counter

def frequency_sort(s: str):
    counter = Counter(s)

    sorted_s = sorted(counter.items(), key=lambda x: (-x[1], x[0]))

    result = ''.join([char * freq for char, freq in sorted_s])

    return result


def main():
    s = input()

    print(frequency_sort(s))


if __name__ == "__main__":
    main()