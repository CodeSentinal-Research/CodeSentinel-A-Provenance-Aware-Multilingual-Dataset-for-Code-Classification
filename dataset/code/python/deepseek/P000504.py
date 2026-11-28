def exclusive_time(n, logs):
    stack = []
    result = [0] * n
    prev_time = 0
    for log in logs:
        id, flag, timestamp = log.split(':')
        id = int(id)
        timestamp = int(timestamp)
        result[id] += timestamp - prev_time if flag == 'start' else timestamp + 1 - prev_time
        while stack and stack[-1] <= timestamp:
            top_id = stack.pop()
            result[top_id] += timestamp - stack[-1] if stack[-1] == prev_time else timestamp + 1 - stack[-1]
            prev_time = stack[-1]
        if flag == 'start':
            stack.append(timestamp)
        prev_time = timestamp
    return result

You can use the following input to test this function:

print(exclusive_time(2, ["0:start:0","1:start:2","0:end:3","1:end:5"]))
print(exclusive_time(3, ["0:start:0","1:start:2","0:end:3","2:start:4","2:end:6","1:end:7","1:start:8","0:end:9"]))

This function works by iterating through the logs. When it encounters a 'start' log, it pushes the timestamp onto a stack. When it encounters an 'end' log, it pops the top function from the stack, calculates its exclusive time, and adds it to the result array.

The algorithm runs in O(n) time, where n is the number of logs. It uses O(n) space to store the stack.