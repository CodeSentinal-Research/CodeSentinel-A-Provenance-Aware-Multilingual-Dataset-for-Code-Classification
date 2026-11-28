def search_active_users(user_accounts):
    active_users = [user for user in user_accounts if user['active']]
    return active_users

def main():
    user_accounts = [{'name': 'John', 'active': True}, 
                     {'name': 'Doe', 'active': False}, 
                     {'name': 'Alice', 'active': True}]

    active_users = search_active_users(user_accounts)

    for user in active_users:
        print(user['name'])

if __name__ == "__main__":
    main()