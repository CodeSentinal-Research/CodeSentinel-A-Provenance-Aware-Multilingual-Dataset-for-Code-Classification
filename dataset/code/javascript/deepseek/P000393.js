Sure, here is a simple JavaScript solution for your problem:

function searchContacts(contacts, prefix) {
  return contacts.filter(contact => contact.name.startsWith(prefix));
}

// Example usage
const contacts = [
  { name: 'John Doe' },
  { name: 'Jane Doe' },
  { name: 'Jim Doe' },
  { name: 'Jack Doe' },
  { name: 'Jill Doe' }
];

const result = searchContacts(contacts, 'Ja');
console.log(result);

In this code, we define a function `searchContacts` that takes a list of contacts and a prefix as arguments. The function uses the `filter` method to create a new array with all contacts whose name starts with the prefix. The result is then logged to the console.