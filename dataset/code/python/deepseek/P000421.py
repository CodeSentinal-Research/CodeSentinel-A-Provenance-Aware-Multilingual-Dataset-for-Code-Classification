Here's the Python code that solves the problem:

from datetime import datetime

def search_expired_memberships(records, current_date):
    expired_memberships = []
    for membership in records:
        membership_date, membership_type = membership
        membership_date = datetime.strptime(membership_date, "%d-%m-%Y")
        if membership_date < current_date:
            expired_memberships.append(membership)
    return expired_memberships

def main():
    records = [(datetime(2022, 1, 1), 'basic'), (datetime(2020, 1, 1), 'premium')]
    current_date = datetime(2023, 1, 1)
    result = search_expired_memberships(records, current_date)
    print(result)

if __name__ == "__main__":
    main()

In this code, the `search_expired_memberships` function iterates over the list of memberships, checks the expiry date, and adds the expired memberships to the `expired_memberships` list. The `main` function sets up the input data and calls the `search_expired_memberships` function, then prints the result.