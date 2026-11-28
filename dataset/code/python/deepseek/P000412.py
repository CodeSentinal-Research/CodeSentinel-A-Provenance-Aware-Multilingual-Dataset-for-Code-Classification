Here's a Python code snippet that handles case-insensitive contact search:

def contact_search(contacts, search):
    search_name = search.lower()
    matching_contacts = [contact for contact in contacts if search_name in contact.lower()]
    return matching_contacts

contacts = ['John Doe', 'jane Doe', 'jim Doe', 'JOHN Smith', 'janey Smith', 'JOHNNY Smith']
search = 'john'
print(contact_search(contacts, search))

This function takes a list of contact names (in the form of strings) and a search name. It then converts both names to lowercase (so that the search is case-insensitive). It then returns a list of contacts that contain the search name.

In the test code, the function is tested with a list of contact names and a search name. The expected output is a list of contacts that contain the search name.