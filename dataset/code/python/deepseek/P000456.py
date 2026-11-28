def minEatingSpeed(piles, H):
    max_speed = max(piles)

    min_speed = max_speed

    while min_speed < max_speed:
        mid_speed = (min_speed + max_speed) // 2
        total_hours = sum([p // mid_speed if p % mid_speed else p // mid_speed for p in piles]) + H

        if total_hours > H:
            min_speed = mid_speed + 1
        else:
            max_speed = mid_speed

    return min_speed

def main():
    N, H = map(int, input().split())
    piles = list(map(int, input().split()))
    print(minEatingSpeed(piles, H))

if __name__ == "__main__":
    main()