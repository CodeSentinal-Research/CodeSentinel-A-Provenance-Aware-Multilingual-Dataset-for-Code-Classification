
n=int(input());words=[input() for _ in range(n)];idx=max(range(n),key=lambda i:len(words[i]));print(idx)
