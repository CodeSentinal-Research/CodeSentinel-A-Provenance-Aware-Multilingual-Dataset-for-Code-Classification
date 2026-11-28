Here is the Python code:

def compare_versions(v1, v2):
    v1 = [int(i) for i in v1.split('.')]
    v2 = [int(i) for i in v2.split('.')]
    while v1 and v1[0] == 0:
        v1.pop(0)
    while v2 and v2[0] == 0:
        v2.pop(0)
    while len(v1) > len(v2):
        v1.append(0)
    while len(v2) > len(v1):
        v2.append(0)
    for i in range(len(v1)):
        if v1[i] > v2[i]:
            return 1
        elif v1[i] < v2[i]:
            return -1
    return 0

def main():
    v1 = input().split()[1]
    v2 = input().split()[1]
    print(compare_versions(v1, v2))

if __name__ == "__main__":
    main()

This code first takes two version numbers as inputs and then passes them to the `compare_versions` function. The `compare_versions` function splits the version numbers into lists of integers, removes any leading zeros, and then compares the numbers in parallel. If the first number of one version is greater, it returns 1. If the second number is greater, it returns -1. If both numbers are equal, it returns 0. If the lengths of the lists are not equal, it appends zeros to the shorter list until they are equal in length.