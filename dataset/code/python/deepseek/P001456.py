def find_repeated_dna_sequences(s):
    sequences = set()
    appeared = {}
    for i in range(len(s) - 9):
        sequence = s[i:i + 10]
        if sequence in appeared:
            if appeared[sequence] == 1:
                sequences.add(sequence)
            appeared[sequence] += 1
        else:
            appeared[sequence] = 1
    return sorted(list(sequences))

def main():
    s = input().strip()
    sequences = find_repeated_dna_sequences(s)
    for sequence in sequences:
        print(sequence)

if __name__ == "__main__":
    main()