Here is the JavaScript code for searching an invoice by invoice number:

function searchInvoice(invoices, invoiceNumber) {
  for (let i = 0; i < invoices.length; i++) {
    if (invoices[i].invoiceNumber === invoiceNumber) {
      return invoices[i];
    }
  }
  return 'Invoice Not Found';
}

In this code, we iterate through each invoice in the invoices array. If the invoiceNumber of the current invoice matches the provided invoiceNumber, we return that invoice. If no match is found after checking all invoices, we return "Invoice Not Found".