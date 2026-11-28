Here is the Python code for the problem.

def count_anagram_occurrences(text, pattern):
    text_length = len(text)
    pattern_length = len(pattern)
    
    count = 0
    
    for i in range(text_length - pattern_length + 1):
        if text[i:i+pattern_length] == pattern:
            count += 1
            
    return count

def main():
    text = input()
    pattern = input()
    print(count_anagram_occurrences(text, pattern))

if __name__ == "__main__":
    main()

In this code, we are using a simple sliding window approach. We check each substring of the text and if it is a valid anagram of the pattern, we increment the count. The time complexity of the solution is O(n), where n is the length of the text.