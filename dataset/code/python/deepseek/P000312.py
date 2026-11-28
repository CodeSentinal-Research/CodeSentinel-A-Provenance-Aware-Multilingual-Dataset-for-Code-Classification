Here is the Python code for the problem:

def compareVersion(version1, version2):
    v1 = list(map(int, version1.split('.')))
    v2 = list(map(int, version2.split('.')))

    while v1 and v1[0] == 0:
        v1.pop(0)

    while v2 and v2[0] == 0:
        v2.pop(0)

    while len(v1) > len(v2):
        v2.append(0)

    while len(v2) > len(v1):
        v1.append(0)

    for i in range(len(v1)):
        if v1[i] > v2[i]:
            return 1
        elif v1[i] < v2[i]:
            return -1

    return 0

def main():
    version1 = input("Enter the first version number: ")
    version2 = input("Enter the second version number: ")
    result = compareVersion(version1, version2)

    if result == 1:
        print("Version 1 is greater than Version 2")
    elif result == -1:
        print("Version 1 is less than Version 2")
    else:
        print("Both versions are equal")

if __name__ == "__main__":
    main()

This Python program takes two version numbers as input from the user. It splits the version numbers by '.' and then compares each pair of integers. If the first pair is greater, it returns 1. If the first pair is smaller, it returns -1. If both pairs are equal, it continues to the next pair and compares them, and so on. If all pairs are compared, it returns 0, signifying that one version is greater than the other.