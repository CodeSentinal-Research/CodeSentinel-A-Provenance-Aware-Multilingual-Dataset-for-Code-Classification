Here is the Python code with the main function and input handling:

def search_member(member_records, membership_id):
    for member in member_records:
        if member['membership_id'] == membership_id:
            return member
    return "Member Not Found"

def main():
    member_records = [
        {'membership_id': 1, 'name': 'John', 'email': 'john@example.com'},
        {'membership_id': 2, 'name': 'Jane', 'email': 'jane@example.com'},
        {'membership_id': 3, 'name': 'Doe', 'email': 'doe@example.com'}
    ]
    membership_id = int(input("Enter the membership ID: "))
    result = search_member(member_records, membership_id)
    if isinstance(result, dict):
        print("Member Details: ", result)
    else:
        print(result)

if __name__ == "__main__":
    main()

In this code, the `search_member` function iterates through each member in the `member_records` list, checking if the `membership_id` of the current member is equal to the input `membership_id`. If it is, the function returns the member's details. If the function iterates through all members and can't find a match, it returns the string "Member Not Found".

The `main` function first asks for the user's input for the membership ID. It then calls the `search_member` function with the user's input and prints the result. If the result is a dictionary, it prints the member's details; otherwise, it prints the result.