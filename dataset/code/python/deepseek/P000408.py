Here is a Python solution for the given problem. This solution uses list comprehension and the split() function to separate the email addresses from the domain.

def search_emails_by_domain(records, domain):
    return [email for email in records if domain in email]

def main():
    domain = input("Enter domain: ")
    records = input("Enter email records (separated by commas): ").split(',')

    emails = search_emails_by_domain(records, domain)

    for email in emails:
        print(email)

if __name__ == "__main__":
    main()

You can run the program and provide input in the following way:

Enter domain: example.com
Enter email records (separated by commas): john@example.com, john@anotherexample.com, john@yetanotherexample.com

This will search for emails that have 'example.com' in them and print them out.