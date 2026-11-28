def read_input():
    rows, cols = map(int, input().split())
    matrix = []
    for _ in range(rows):
        row = list(map(int, input().split()))
        matrix.append(row)
    return rows, cols, matrix

def find_max_sum(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    max_sum = 0
    for left in range(cols):
        temp = [0] * rows
        for right in range(left, cols):
            for i in range(rows):
                temp[i] += matrix[i][right]
            curr_sum, max_sum = find_max_subarray(temp)
            max_sum = max(max_sum, curr_sum)
    return max_sum

def find_max_subarray(temp):
    curr_sum = max_sum = temp[0]
    max_start = max_end = min_start = min_end = 0
    for i in range(1, len(temp)):
        curr_sum += temp[i]
        if curr_sum < temp[i]:
            curr_sum = temp[i]
            max_start = min_end = i
        elif curr
!= max_sum:
            max_sum = curr_sum
            max_end = i
        else:
            if curr_sum == max_sum:
                if max_end - max_start > min_end - min_start:
                    max_start = min_start = max_end = min_end = i
    return max_sum, max_end - max_start + 1

def main():
    rows, cols, matrix = read_input()
    max_sum = find_max_sum(matrix)
    print(max_sum)

if __name__ == '__main__':
    main()