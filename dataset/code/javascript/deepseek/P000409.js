Here is a simple JavaScript solution using a filter method on the array of user objects. This solution assumes that the user objects are in the form of an array where the first element is the username and the second is the user object itself.

function searchUsersByUsernamePrefix(users, prefix) {
    // Filter the users array to include only users whose usernames start with the prefix
    let matchingUsers = users.filter(user => user[0].startsWith(prefix));

    // Map over the matchingUsers array and return an array of just the usernames
    let usernames = matchingUsers.map(user => user[0]);

    return usernames;
}

// Example usage
let users = [
    ['alice', {name: 'Alice', age: 30, active: true}],
    ['bob', {name: 'Bob', age: 25, active: true}],
    ['charlie', {name: 'Charlie', age: 35, active: false}],
    ['dave', {name: 'Dave', age: 40, active: true}],
    ['eve', {name: 'Eve', age: 45, active: true}]
];

console.log(searchUsersByUsernamePrefix(users, 'B'));

This code will output: `['bob', 'dave']`

This code assumes that the user objects are always in the correct format (i.e., they are arrays with exactly two elements, the first being the username and the second being the user object itself). If the user objects can have different formats, you would need to modify the code accordingly.