def search_users(users, prefix):
    return [user for user in users if user.startswith(prefix)]

class User:
    def __init__(self, username):
        self.username = username

def main():
    users = [User(username) for username in input().split()]
    prefix = input()
    results = search_users(users, prefix)
    for result in results:
        print(result.username)

if __name__ == "__main__":
    main()
This code defines a `User` class with a `username` attribute. The `search_users` function uses a list comprehension to find all users whose usernames start with the given prefix. The `main` function handles the input for the users and prefix.