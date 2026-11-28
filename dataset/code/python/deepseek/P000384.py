Here is the python code that reads the invoice records from the invoices.txt file and finds an invoice using its invoice number:

def find_invoice(invoice_number):
    invoices = read_invoices()
    for invoice in invoices:
        if invoice['invoice_number'] == invoice_number:
            return invoice
    return "Invoice Not Found"

def read_invoices():
    with open('invoices.txt', 'r') as f:
        lines = f.readlines()
    invoices = []
    for line in lines:
        fields = line.split(',')
        invoice = {
            'invoice_number': fields[0].strip(),
            'customer_name': fields[1].strip(),
            'amount': float(fields[2].strip()),
            'date': fields[3].strip()
        }
        invoices.append(invoice)
    return invoices

def main():
    invoice_number = input("Enter the invoice number: ")
    invoice = find_invoice(invoice_number)
    print(invoice)

if __name__ == "__main__":
    main()

This code assumes that the invoices.txt file is in the same directory as the python script and has the following format:

invoice1,customer1,200.00,2022-01-01
invoice2,customer2,300.00,2022-02-01

The main function reads the invoice number from the user, calls the find_invoice function with the invoice number as an argument, and prints the invoice or "Invoice Not Found" if the invoice is not found.

Please note that the read_invoices function is a very basic implementation and does not handle errors in the input file. You may want to add error handling code for a production environment.