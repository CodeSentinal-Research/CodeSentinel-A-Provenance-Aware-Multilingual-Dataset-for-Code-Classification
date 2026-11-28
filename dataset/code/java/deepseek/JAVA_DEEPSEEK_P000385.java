import java.io.*;
import java.util.*;

public class Main {
    static class Order {
        int id;
        String details;

        Order(int id, String details) {
            this.id = id;
            this.details = details;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Order> orders = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] parts = br.readLine().split(" ");
            int id = Integer.parseInt(parts[0]);
            String details = parts[1];
            orders.add(new Order(id, details));
        }
        int searchId = Integer.parseInt(br.readLine());
        boolean found = false;
        for (Order order : orders) {
            if (order.id == searchId) {
                System.out.println(order.details);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Order Not Found");
        }
    }
}
