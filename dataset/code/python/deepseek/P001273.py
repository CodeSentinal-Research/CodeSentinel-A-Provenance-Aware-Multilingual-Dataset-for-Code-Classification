def rearrange_barcodes(n, barcodes):
    freq = [0] * (n + 1)
    for barcode in barcodes:
        freq[barcode] += 1

    max_freq = max(freq)

    if max_freq == 1:
        return barcodes

    max_freq_indexes = [i for i in range(n) if freq[i] == max_freq]

    result = [0] * n
    index = 0
    for barcode in range(n):
        if freq[barcode] == 0:
            result[barcode] = barcodes[barcode]
        else:
            result[barcode] = max_freq_indexes[index % len(max_freq_indexes)]
            freq[max_freq_indexes[index % len(max_freq_indexes)]] -= 1
            index += 1

    return result

def main():
    n = int(input().strip())
    barcodes = list(map(int, input().strip().split()))
    result = rearrange_barcodes(n, barcodes)
    print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()