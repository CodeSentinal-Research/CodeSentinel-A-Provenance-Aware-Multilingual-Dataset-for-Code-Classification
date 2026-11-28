Sure, here is the JavaScript solution for your problem:

function searchContact(contacts, name) {
    for (let i = 0; i < contacts.length; i++) {
        if (contacts[i].name === name) {
            return contacts[i];
        }
    }
    return "Contact Not Found";
}

// Example usage:

const contacts = [
    { name: "John", phone: "123-456-7890" },
    { name: "Jane", phone: "098-765-4321" },
    // more contacts...
];

console.log(searchContact(contacts, "John")); // { name: 'John', phone: '123-456-7890' }
console.log(searchContact(contacts, "Jane")); // { name: 'Jane', phone: '098-765-4321' }
console.log(searchContact(contacts, "Mike")); // "Contact Not Found"

In this code, we have a function called `searchContact` that takes in a list of contacts and a name. It iterates through each contact in the list, and if the current contact's name matches the input name, it returns the contact details. If no match is found, it returns "Contact Not Found". 

In the example usage part, we call this function with different names to test the functionality.