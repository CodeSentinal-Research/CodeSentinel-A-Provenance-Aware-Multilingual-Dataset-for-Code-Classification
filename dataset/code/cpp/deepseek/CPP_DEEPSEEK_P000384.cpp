#include <iostream>
#include <unordered_map>

struct Invoice {
    int number;
    string details;
};

unordered_map<int, Invoice> invoices;

void addInvoice(int number, string details) {
    Invoice invoice;
    invoice.number = number;
    invoice.details = details;
    invoices[number] = invoice;
}

void searchInvoice(int number) {
    if(invoices.find(number) != invoices.end()) {
        cout << "Invoice Number: " << number << ", Details: " << invoices[number].details << endl;
    } else {
        cout << "Invoice Not Found" << endl;
    }
}

int main() {
    addInvoice(1, "Invoice 1 Details");
    addInvoice(2, "Invoice 2 Details");
    addInvoice(3, "Invoice 3 Details");

    searchInvoice(1);
    searchInvoice(4);

    return 0;
}