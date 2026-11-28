def can_form_straight(cards, k):
    count = [0] * (max(cards) + 1)
    for num in cards:
        count[num] += 1

    left, right = 0, 0
    valid_cards = 0

    while right < len(cards):
        if count[cards[right]] > 0:
            valid_cards += 1
            count[cards[right]] -= 1
        if valid_cards == k:
            return 'YES'

        if valid_cards > k:
            while count[cards[left]] == 0:
                left += 1
            count[cards[left]] += 1
            valid_cards -= 1
        right += 1

    return 'NO'


def main():
    n, k = map(int, input().split())
    cards = list(map(int, input().split()))
    print(can_form_straight(cards, k))


if __name__ == "__main__":
    main()