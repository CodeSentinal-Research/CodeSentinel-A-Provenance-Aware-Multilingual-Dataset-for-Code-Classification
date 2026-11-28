def search_contacts_by_prefix(contacts, prefix):
    return [contact for contact in contacts if contact.startswith(prefix)]

class Contact:
    def __init__(self, name):
        self.name = name

def main():
    contacts = [Contact('John Doe'), Contact('Jane Smith'), Contact('Jim Brown'), Contact('Jack Black')]
    prefix = 'J'
    result = search_contacts_by_prefix(contacts, prefix)
    for contact in result:
        print(contact.name)

if __name__ == "__main__":
    main()