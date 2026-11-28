import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        d = int(lines[0])
        y = d // 365
        rem = d % 365
        w = rem // 7
        days = rem % 7
        print(f"{y} Years {w} Weeks {days} Days")
if __name__ == '__main__':
    main()