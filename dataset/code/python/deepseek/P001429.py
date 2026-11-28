def count_tuples(n, numbers):
    count = 0
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                for l in range(k+1, n):
                    if numbers[i]*numbers[j] == numbers[k]*numbers[l]:
                        count += 1
    return count

def main():
    n = int(input())
    numbers = list(map(int, input().split()))
    print(count_tuples(n, numbers))

if __name__ == "__main__":
    main()