def digit_frequency(n: int):
    freq = [0] * 10
    for d in str(abs(n)):
        freq[int(d)] += 1
    return freq

if __name__ == '__main__':
    n = int(input())
    print(" ".join(map(str, digit_frequency(n))))