import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    low = int(input_data[0])
    high = int(input_data[1])
    
    results = []
    for length in range(2, 10):
        for start in range(1, 10):
            num = 0
            valid = True
            for i in range(length):
                digit = start + i
                if digit > 9:
                    valid = False
                    break
                num = num * 10 + digit
            if valid and low <= num <= high:
                results.append(num)
                
    print(*results)

if __name__ == "__main__":
    solve()

