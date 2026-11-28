Here is the Python code to solve the problem:

def partitionLabels(S):
    last = {c: i for i, c in enumerate(S)}
    j = anchor = 0
    partitions = []
    for i, c in enumerate(S):
        j = max(j, last[c])
        if i == j:
            partitions.append(i - anchor + 1)
            anchor = i + 1
    return partitions

def main():
    S = input().strip()
    partitions = partitionLabels(S)
    for p in partitions:
        print(p)

if __name__ == '__main__':
    main()

This code uses a dictionary to store the last occurrence of each character in the string. Then, it iterates over the string, updating the end index `j` when a character is encountered. When `j` is equal to the current index, it means that all characters before `j` have been covered in a partition, so it adds the partition length to the list and starts a new partition. The time complexity is O(n), where n is the length of the string.