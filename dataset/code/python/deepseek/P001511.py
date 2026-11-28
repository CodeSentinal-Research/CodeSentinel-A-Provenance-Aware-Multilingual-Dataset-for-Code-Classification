def max_consecutive_answers(answer, k):
    count = [0] * len(answer)
    max_length = 0
    for i in range(len(answer)):
        if i > 0 and answer[i] != answer[i-1]:
            count[i] = count[i-1] + 1
        else:
            count[i] = 1
        max_length = max(max_length, count[i])
    return max_length if max_length <= k else -1

def main():
    answer = input().strip()
    k = int(input().strip())
    print(max_consecutive_answers(answer, k))

if __name__ == "__main__":
    main()