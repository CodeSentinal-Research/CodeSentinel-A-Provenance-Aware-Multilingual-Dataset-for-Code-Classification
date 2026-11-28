# problem title : Moving Average from Data Stream
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        size = int(tokens[0])
        q = int(tokens[1])
        stream = list(map(int, tokens[2:2+q]))
        window = []
        window_sum = 0
        for val in stream:
            window.append(val)
            window_sum += val
            if len(window) > size:
                window_sum -= window.pop(0)
            print(f"{window_sum / len(window):.5f}")
if __name__ == '__main__':
    main()
