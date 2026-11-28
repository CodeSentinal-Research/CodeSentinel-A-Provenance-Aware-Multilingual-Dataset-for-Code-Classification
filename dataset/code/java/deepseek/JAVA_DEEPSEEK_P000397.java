import java.io.*;
import java.util.*;

class Order {
    int id;
    String status;

    Order(int id, String status) {
        this.id = id;
        this.status = status;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Order> orders = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] parts = br.readLine().split(" ");
            int id = Integer.parseInt(parts[0]);
            String status = parts[1];
            orders.add(new Order(id, status));
        }
        String targetStatus = br.readLine();
        for (Order order : orders) {
            if (order.status.equals(targetStatus)) {
                System.out.println(order.id);
            }
        }
    }
}
