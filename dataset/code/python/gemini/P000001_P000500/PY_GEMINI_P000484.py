import sys
def decode_string(s):
    # Monotonic stack to track visible elements
    stack = []
    curr_num = 0
    curr_str = ''
    for c in s:
        if c.isdigit():
            curr_num = curr_num * 10 + int(c)
        elif c == '[':
            stack.append((curr_str, curr_num))
            curr_str = ''
            curr_num = 0
        elif c == ']':
            prev_str, num = stack.pop()
            curr_str = prev_str + curr_str * num
        else:
            curr_str += c
    return curr_str

def main():
    s = sys.stdin.read().strip()
    if s:
        print(decode_string(s))
if __name__ == '__main__':
    main()