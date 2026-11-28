def reorganize_string(s):
    freq = {}
    for char in s:
        if char in freq:
            freq[char] += 1
        else:
            freq[char] = 1

    max_freq = max(freq.values())
    max_freq_chars = [k for k, v in freq.items() if v == max_freq]
    num_max_freq_chars = len(max_freq_chars)
    if max_freq > 1 or (num_max_freq_chars > 1 and max_freq_chars[0] != max_freq_chars[1]):
        return "IMPOSSIBLE"

    result = ""
    while len(result) < len(s):
        for char in sorted(freq.keys()):
            if freq[char] > 0:
                result += char
                freq[char] -= 1
                break
    return result

print(reorganize_string("aab"))  
print(reorganize_string("aaab"))  
print(reorganize_string("aabb"))  
print(reorganize_string("aaa"))