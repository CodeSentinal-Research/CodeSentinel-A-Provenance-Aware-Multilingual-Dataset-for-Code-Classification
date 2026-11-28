def search_contact(contacts, name):
    for contact in contacts:
        if contact['name'] == name:
            return contact
    return "Contact Not Found"

def main():
    contacts = [{'name': 'John Doe', 'phone': '1234567890'}, {'name': 'Jane Doe', 'phone': '0987654321'}]
    name = input("Enter the name to search: ")
    result = search_contact(contacts, name)
    if isinstance(result, str):
        print(result)
    else:
        print("Contact Name: ", result['name'])
        print("Phone Number: ", result['phone'])

if __name__ == "__main__":
    main()