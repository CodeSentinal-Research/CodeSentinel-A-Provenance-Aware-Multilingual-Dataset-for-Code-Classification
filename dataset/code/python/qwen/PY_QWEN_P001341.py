import sys

def solve():
    n = int(sys.stdin.readline())
    results = []
    
    def get_hours(leds):
        h = sum(1 << i for i in range(4) if leds & (1 << i))
        m = sum(1 << i for i in range(4, 10) if leds & (1 << i))
        if h < 12 and m < 60:
            return f"{h}:{m:02d}"
        return None
        
    def backtrack(leds_on, start, remaining):
        if remaining == 0:
            time = get_hours(leds_on)
            if time:
                results.append(time)
            return
        for i in range(start, 10):
            backtrack(leds_on | (1 << i), i + 1, remaining - 1)
            
    backtrack(0, 0, n)
    print(*sorted(results))

if __name__ == "__main__":
    solve()

