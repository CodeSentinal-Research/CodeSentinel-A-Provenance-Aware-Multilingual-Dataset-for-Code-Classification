import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numAccounts = scanner.nextInt();
        int inactivityPeriod = scanner.nextInt();
        Map<Integer, Integer> accountTransactions = new HashMap<>();
        for (int i = 0; i < numAccounts; i++) {
            int accountNum = scanner.nextInt();
            int transactionMonth = scanner.nextInt();
            accountTransactions.put(accountNum, transactionMonth);
        }
        List<Integer> inactiveAccounts = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : accountTransactions.entrySet()) {
            if (entry.getValue() < inactivityPeriod) {
                inactiveAccounts.add(entry.getKey());
           }
        }
        Collections.sort(inactiveAccounts);
        for (int account : inactiveAccounts) {
            System.out.println(account);
        }
    }
}
