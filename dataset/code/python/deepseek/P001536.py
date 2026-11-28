Here is the Python code for the problem:

def minWindow(s, t):
    if not t or not s:
        return ""

    dict_t = collections.Counter(t)

    start, end = 0, 0
    counter, required = collections.Counter(), len(dict_t)

    min_len = float('inf'), None, None

    while end < len(s):
        if s[end] in dict_t:
            counter[s[end]] += 1
            if counter[s[end]] == dict_t[s[end]]:
                required -= 1
        while start <= end and required == 0:
            if end - start + 1 < min_len:
                min_len = end - start + 1
                min_str = s[start:end+1]
            if s[start] in dict_t:
                counter[s[start]] -= 1
                if counter[s[start]] == dict_t[s[start]] - 1:
                    required += 1
            start += 1
        end += 1

    return min_str
In this code, we are using a sliding window approach. In each iteration, we try to include the character at the end of the window in our string. If it is not in T, we skip it. When a valid window is found (all characters in T are in the window), we try to minimize it by moving the start of the window to the right.