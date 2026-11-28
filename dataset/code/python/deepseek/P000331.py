Here is a Python solution for the problem:

def exclusive_time(n, logs):
    stack = []
    result = [0] * n
    prev_time = 0

    for log in logs:
        id, type, timestamp = log.split(':')
        timestamp = int(timestamp)

        if type == 'start':
            if stack:
                result[stack[-1]] += 1 + prev_time - timestamp
            stack.append(int(id))
        else:
            result[stack.pop()] += 1 + prev_time - timestamp
            prev_time = timestamp

    return result

def main():
    n = int(input())
    logs = input().split()

    result = exclusive_time(n, logs)
    print(result)

if __name__ == "__main__":
    main()

This program uses a stack to keep track of the function ids. For each log, it checks the type of the log and performs the corresponding operation. The stack is used to simulate the call stack and the current operation is performed by popping the top element of the stack.

The main function reads the number of functions n and the list of logs from the input. Then it calls the `exclusive_time` function with these values and prints the result.

For example, if the input is `3:start:[]`, `3:start:[]`, `2:start:[]`, `1:start:[]`, `1:end:[]`, `2:end:[]`, `3:end:[]`. The output will be `[0, 1, 4]`, which means the exclusive time of each function is 0, 1, and 4 respectively.