import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = lines[0]
        char_set = set()
        left = max_len = 0
        # Expand window to the right
        for right, char in enumerate(s):
            # Shrink window from the left while duplicate exists
            while char in char_set:
                char_set.remove(s[left])
                left += 1
            char_set.add(char)
            max_len = max(max_len, right - left + 1)
        print(max_len)
if __name__ == '__main__':
    main()