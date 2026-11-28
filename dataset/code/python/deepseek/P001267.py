def furthest_building(N, B, L, buildings):
    max_height = 0
    can_reach = [0]*N
    for i in range(N):
        if buildings[i] > max_height:
            max_height = buildings[i]
            can_reach[i] = 1
        else:
            for j in range(1, L+1):
                if i-j >= 0 and buildings[i] > buildings[i-j] and can_reach[i-j] == 1:
                    can_reach[i] = 1
                    break
            else:
                can_reach[i] = 0
    return can_reach.index(1)

def main():
    N, B, L = map(int, input().split())
    buildings = list(map(int, input().split()))
    print(furthest_building(N, B, L, buildings))

if __name__ == "__main__":
    main()