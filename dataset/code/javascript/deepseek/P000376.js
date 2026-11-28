Here is a JavaScript solution for the problem. This solution assumes that the input is a list of customers and a mobile number. It iterates through the list of customers and checks if the mobile number matches the input mobile number. If it finds a match, it returns the customer details. If it doesn't find a match, it returns "Customer Not Found".

function searchCustomerByMobileNumber(customers, mobileNumber) {
    for (let i = 0; i < customers.length; i++) {
        if (customers[i].mobileNumber === mobileNumber) {
            return customers[i];
        }
    }
    return "Customer Not Found";
}

You can use this function in your code like so:

let customers = [
    { name: 'John', mobileNumber: '1234567890' },
    { name: 'Jane', mobileNumber: '9876543210' },
    // more customers...
];

let mobileNumber = '1234567890';

let result = searchCustomerByMobileNumber(customers, mobileNumber);

console.log(result);

In this code, the `searchCustomerByMobileNumber` function is called with the list of customers and a mobile number. The function then iterates through the list of customers and checks if the mobile number matches the input mobile number. If it finds a match, it returns the customer details. If it doesn't find a match, it returns "Customer Not Found". The result is then logged to the console.