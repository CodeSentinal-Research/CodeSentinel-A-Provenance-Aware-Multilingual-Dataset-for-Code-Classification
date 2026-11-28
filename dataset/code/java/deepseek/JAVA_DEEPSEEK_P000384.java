import java.io.*;
import java.util.*;

public class Main {
    static class Invoice {
        String number;
        String details;

        Invoice(String number, String details) {
            this.number = number;
            this.details = details;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Invoice> invoices = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] parts = br.readLine().split(" ");
            invoices.add(new Invoice(parts[0], parts[1]));
        }
        String numberToFind = br.readLine();
        boolean found = false;
        for (Invoice invoice : invoices) {
            if (invoice.number.equals(numberToFind)) {
                System.out.println(invoice.details);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Invoice Not Found");
        }
    }
}
