Here is the Python code:

def maxScore(N, Power, tokens):
    tokens.sort(reverse=True)
    score = 0
    while N > 0 and Power > 0:
        if Power >= tokens[0]:
            Power -= tokens[0]
            score += tokens[0]
            N -= 1
        else:
            if N == 0 or tokens[N-1] > tokens[N]:
                break
            else:
                Power -= tokens[N]
                N -= 1
        if N == 0 or tokens[N-1] > tokens[N]:
            break
    return score

if __name__ == "__main__":
    N, Power = map(int, input().split())
    tokens = list(map(int, input().split()))
    print(maxScore(N, Power, tokens))

In this code, we first sort the tokens list in descending order. Then, we start a loop until we run out of tokens or no more power is left. For each token, if it's not too big for the power, we can spend it and add its value to the score. Otherwise, we need to use a bigger token or break the loop. If no more tokens or a bigger token is available, we break the loop. The final score is the sum of all tokens we can obtain.