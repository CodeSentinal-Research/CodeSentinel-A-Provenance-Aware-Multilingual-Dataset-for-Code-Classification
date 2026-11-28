def alien_dictionary():
    N = int(input().strip())
    words = [input().strip() for _ in range(N)]
    chars = set(''.join(words))

    adj_list = {char: [] for char in chars}

    for word in words:
        for char in word:
            if char in adj_list and word.index(char) > adj_list[char].index(adj_list[char][0]) + 1:
                adj_list[char].insert(0, adj_list[char].pop(adj_list[char].index(adj_list[char][0])))
            else:
                adj_list[char].append(char)

    adj_list_rev = {char: [] for char in chars}

    for char in adj_list:
        for next_char in adj_list[char]:
            adj_list_rev[next_char].append(char)

    stack = [char for char in adj_list if not adj_list_rev[char]]
    order = []

    while stack:
        char = stack.pop()
        order.append(char)
        for next_char in adj_list[char]:
            if next_char in adj_list_rev and next_char not in order:
                stack.append(next_char)

    if len(order) == len(chars):
        print(''.join(order))
    else:
        print('IMPOSSIBLE')

alien_dictionary()