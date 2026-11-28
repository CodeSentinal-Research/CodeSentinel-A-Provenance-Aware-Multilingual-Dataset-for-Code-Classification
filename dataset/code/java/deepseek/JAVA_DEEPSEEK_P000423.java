import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int days = scanner.nextInt();
        Map<Integer, Integer> orders = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int customerId = scanner.nextInt();
            int orderDate = scanner.nextInt();
            orders.put(customerId, orderDate);
        }
        for (Map.Entry<Integer, Integer> entry : orders.entrySet()) {
            if (Math.abs(entry.getValue() - days) > 0) {
                System.out.println(entry.getKey());
           
            }
        }
    }
}
