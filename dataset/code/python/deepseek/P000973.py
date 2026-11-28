def prob_dice_sum(S):
    total_outcomes = 6**2
    favorable_outcomes = 0

    for i in range(2, S+1):
        favorable_outcomes += i

    prob = favorable_outcomes / total_outcomes
    return prob


def main():
    S = int(input("Enter the sum of the dice: "))
    if 2 <= S <= 12:
        print("Probability: ", prob_dice_sum(S))
    else:
        print("Invalid input. Please enter a number between 2 and 12.")


if __name__ == "__main__":
    main()
This code calculates the probability of a sum of two dice rolls given a specific sum. The input handling is done in the main function. The main function gets the input sum S and validates it. If the input is not within the range 2 to 12, an error message is printed. Otherwise, the probability is calculated and printed.