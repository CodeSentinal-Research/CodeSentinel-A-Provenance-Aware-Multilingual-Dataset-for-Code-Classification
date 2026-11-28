Here's a Python code solution for the problem. We use a dictionary to count the number of occurrences of each email address and then print out the emails with a count greater than 1.

def find_duplicate_emails(records):
    email_counts = {}
    for email in records:
        if email in email_counts:
            email_counts[email] += 1
        else:
            email_counts[email] = 1

    duplicates = [email for email, count in email_counts.items() if count > 1]
    return duplicates


def main():
    records = ["example1@email.com", "example2@email.com", "example2@email.com", "example3@email.com"]
    duplicates = find_duplicate_emails(records)
    for duplicate in duplicates:
        print(duplicate)


if __name__ == "__main__":
    main()

In this code, the `find_duplicate_emails` function creates a dictionary to count the occurrences of each email address in the list. Then it creates a list of all email addresses that appear more than once by looking at the dictionary. The `main` function sets up some test records and prints out the duplicated email addresses.