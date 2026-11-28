Sure, here is a Python solution for the problem:

def successful_pairs(spells, potions, success):
    spells.sort()
    potions.sort()

    count = 0

    for spell in spells:
        left, right = 0, len(potions) - 1
        while left < right:
            mid = (left + right + 1) // 2
            if spell * potions[mid] >= success:
                left = mid
            else:
                right = mid - 1

        if spell * potions[left] < success:
            count += len(spells) - spells.index(spell)
        else:
            count += len(spells) - spells.index(spell) - 1

    return count

def main():
    N, M, Success = map(int, input().split())
    spells = list(map(int, input().split()))
    potions = list(map(int, input().split()))

    print(successful_pairs(spells, potions, Success))

if __name__ == "__main__":
    main()

This code firstly sorts the spells and potions. Then for each spell, it performs a binary search to find the smallest potion that is greater than or equal to the spell and the spell itself. If the spell fails to form a successful pair, it adds the count of spells to the total count.