def max_ice_cream_bars():
    n, coins = map(int, input().split())
    costs = list(map(int, input().split()))
    
    costs.sort()
    
    max_bars = 0
    for cost in costs:
        if coins >= cost:
            max_bars += 1
            coins -= cost
        else:
            break
    
    print(max_bars)

if __name__ == "__main__":
    max_ice_cream_bars()