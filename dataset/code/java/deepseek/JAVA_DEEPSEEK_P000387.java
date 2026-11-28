import java.io.*;
import java.util.*;

public class Main {
    static class Transaction {
        int id;
        String details;

        Transaction(int id, String details) {
            this.id = id;
            this.details = details;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<Integer, Transaction> transactions = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            int id = Integer.parseInt(input[0]);
            String details = input[1];
            transactions.put(id, new Transaction(id, details));
        }
        int searchId = Integer.parseInt(br.readLine());
        if (transactions.containsKey(searchId)) {
            Transaction t = transactions.get(searchId);
            System.out.println(t.id + " " + t.details);
        } else {
            System.out.println("Transaction Not Found");
        }
    }
}
