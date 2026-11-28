def search_email(users, username):
    for user in users:
        if user['username'] == username:
            return user['email']
    return 'User Not Found'

def main():
    users = [
        {'username': 'John', 'email': 'john@example.com'},
        {'username': 'Jane', 'email': 'jane@example.com'},
        {'username': 'Mary', 'email': 'mary@example.com'}
    ]
    username = input('Enter username: ')
    print(search_email(users, username))

if __name__ == '__main__':
    main()
In this code, we have a function `search_email` that takes a list of user records and a username as input, and returns the email of the user who has the given username. If no user with the given username is found, it returns the string 'User Not Found'.

In the `main` function, we first define the list of users. Then we read the username from the user. Finally, we call `search_email` with the users list and the username, and print the result.

Please note that this is a very basic solution and it assumes that the input data is always valid. In a real-world application, you would need to add error handling for invalid inputs.