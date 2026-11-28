def findSubstring(s, words):
    if not s or not words:
        return []
    
    one_word_length = len(words[0])
    total_length = len(words) * one_word_length
    
    if len(s) < total_length:
        return []
    
    result = []
    for i in range(0, len(s) - total_length + 1):
        if s[i:i+one_word_length] == words[0] and s[i+one_word_length:i+2*one_word_length] == words[1] and s[i+2*one_word_length:i+3*one_word_length] == words[2] and s[i+3*one_word_length:i+4*one_word_length] == words[3] and s[i+4*one_word_length:i+5*one_word_length] == words[4]:
            result.append(i)
    
    return result


def main():
    s = input().strip()
    M = int(input().strip())
    words = input().strip().split()
    
    indices = findSubstring(s, words)
    if indices:
        print(' '.join(map(str, indices)))
    else:
        print('-1')


if __name__ == "__main__":
    main()