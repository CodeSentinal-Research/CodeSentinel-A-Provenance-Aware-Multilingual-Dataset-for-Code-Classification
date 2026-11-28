from collections import deque

def removeInvalidParentheses(self, s):
    def isValid(s):
        count = 0
        for c in s:
            if c == '(':
                count += 1
            elif c == ')':
                count -= 1
                if count < 0:
                    return False
        return count == 0

    level = deque([s])
    seen = {s}
    while level:
        curr_len = len(level)
        for _ in range(curr_len):
            curr_str = level.popleft()
            if isValid(curr_str):
                print(curr_str)
                seen.add(curr_str)
            else:
                for i in range(len(curr_str)):
                    if curr_str[i] in '()':
                        temp = curr_str[:i] + curr_str[i+1:]
                        if temp not in seen:
                            level.append(temp)
                            seen.add(temp)