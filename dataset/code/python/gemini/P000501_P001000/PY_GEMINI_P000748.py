import sys
def dice_rolls(target, cur):
    if target == 0:
        print(*cur)
        return
    for i in range(1, 7):
        if i <= target:
            dice_rolls(target - i, cur + [i])
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        target = int(tokens[0])
        dice_rolls(target, [])
if __name__ == '__main__':
    main()