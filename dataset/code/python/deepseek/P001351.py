from itertools import combinations

def combinations_iterator(string, k):
    string = sorted(string)
    for i in range(k, len(string)+1):
        for combination in combinations(string, i):
            print(''.join(combination))

def main():
    string = input("Enter a string: ")
    k = int(input("Enter k: "))
    
    if k > len(string) or k < 1:
        print("Invalid input! K must be between 1 and the length of the string.")
        return
    
    combinations_iterator(string, k)

if __name__ == "__main__":
    main()