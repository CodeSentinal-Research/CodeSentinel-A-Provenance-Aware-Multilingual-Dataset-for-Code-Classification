def is_happy(n):
    slow, fast = n, n
    while True:
        slow = sum(int(i)**2 for i in str(slow))
        fast = sum(int(i)**2 for i in str(fast))
        fast = sum(int(i)**2 for i in str(fast))
        if slow == fast:
            return slow == 1
        if slow == 4:
            return False

def main():
    n = int(input())
    print("YES" if is_happy(n) else "NO")

if __name__ == "__main__":
    main()