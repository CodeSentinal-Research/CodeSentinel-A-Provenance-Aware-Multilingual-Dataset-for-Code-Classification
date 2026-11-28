def merge_accounts():
    n = int(input().strip())
    accounts = []
    for i in range(n):
        name, *emails, email = input().strip().split()
        accounts.append((name, set(emails), email))
    accounts.sort()
    for name, emails, email in accounts:
        print(f'{name} <{email}>', ', '.join(sorted(emails)))

if __name__ == "__main__":
    merge_accounts()