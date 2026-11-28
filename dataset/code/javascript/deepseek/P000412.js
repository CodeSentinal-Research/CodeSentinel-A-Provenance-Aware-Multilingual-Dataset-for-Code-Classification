Sure, here is a simple way to solve the problem using JavaScript's in-built methods and data structures. This code will convert both the contact names and the search name to lower case before matching, which should make the comparison case insensitive.

function findContacts(contacts, searchName) {
    // Convert both the contact names and the search name to lower case
    const searchNameLowerCase = searchName.toLowerCase();

    // Filter out the contacts that match the search name
    const matchingContacts = contacts.filter(contact => {
        const contactNameLowerCase = contact.name.toLowerCase();
        return contactNameLowerCase === searchNameLowerCase;
    });

    return matchingContacts;
}

// Test the function
const contacts = [
    { name: 'John Doe', phone: '1234567890' },
    { name: 'Jane Doe', phone: '9876543210' },
    { name: 'john doe', phone: '1112223334' }
];

const searchName = 'john doe';
console.log(findContacts(contacts, searchName));

This code will output the contact records where the name is 'John Doe', ignoring the case differences.