import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int threshold = scanner.nextInt();
        scanner.nextLine();

        Map<String, Integer> products = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String product = scanner.next();
            int stock = scanner.nextInt();
            products.put(product, stock);
        }

        for (Map.Entry<String, Integer> entry : products.entrySet()) {
            if (entry.getValue() < threshold) {
                System.out.println(entry.getKey());
            }
        }
    }
}
