Here is a Python solution for the problem:

def bag_of_tokens(tokens, power):
    tokens.sort()
    score = 0
    while tokens and (power >= tokens[0] or score > 0):
        power -= tokens.pop(0)
        score += 1
    return score

def main():
    N, Power = map(int, input().split())
    tokens = list(map(int, input().split()))
    print(bag_of_tokens(tokens, Power))

if __name__ == "__main__":
    main()

In this solution, we first sort the tokens array in increasing order. Then, we use a while loop to loop through the sorted tokens array. In each iteration, we remove a token from the array (if possible), which reduces our power and increases our score. If we cannot remove any tokens from the array (i.e., if we have exhausted all tokens in the array and our power is still greater than the remaining token), we stop the loop. Finally, we return our score.