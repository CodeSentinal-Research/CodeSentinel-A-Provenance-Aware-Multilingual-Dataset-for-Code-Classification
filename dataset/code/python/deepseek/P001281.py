Here is the Python code for your problem:

def min_removal(num, k):
    num = num.lstrip('0')
    if len(num) <= k:
        return '0' * k
    num = sorted(num, reverse=True)
    num = num[k:]
    return ''.join(num)

def main():
    num = input()
    k = int(input())
    print(min_removal(num, k))

if __name__ == "__main__":
    main()

In this code, we first remove leading zeroes from the number (if any). If the length of the number is less than or equal to k, we return '0's for k times. Then, we sort the number in descending order. After that, we remove k digits from the left and return the number after removing k digits. The ''.join() function is used to concatenate the list of characters into a string.