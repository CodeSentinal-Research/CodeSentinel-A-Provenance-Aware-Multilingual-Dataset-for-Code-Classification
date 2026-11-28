Here is the python code for the problem:

def calculate_simple_interest(P, R, T):
    if 1 <= P <= 1000 and 1 <= R <= 1000 and 1 <= T <= 1000:
        interest = (P * R * T) / 100
        return interest
    else:
        return "Inputs are not within the constraints"

P = int(input("Enter the principal amount: "))
R = int(input("Enter the rate of interest: "))
T = int(input("Enter the time: "))

interest = calculate_simple_interest(P, R, T)

if type(interest) == float:
    print("Simple interest is: ", interest)
else:
    print(interest)

This code defines a function `calculate_simple_interest` which takes three parameters P, R, and T. It calculates simple interest by multiplying P, R, and T and dividing by 100. Then, it takes inputs for P, R, and T from the user, and calls the function with these inputs. Finally, it checks if the returned value is a float (indicating an error) and if so, prints an error message, else it prints the calculated simple interest.