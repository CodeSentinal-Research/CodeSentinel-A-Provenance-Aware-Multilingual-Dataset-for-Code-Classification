
n=int(input());words=[input() for _ in range(n)];idx=min(range(n),key=lambda i:len(words[i]));print(idx)
