import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<Integer, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            int orderId = sc.nextInt();
            String status = sc.next();
            map.put(orderId, status);
        }
        int searchOrder = sc.nextInt();
        if(map.containsKey(searchOrder)) System.out.println(map.get(searchOrder));
        else System.out.println("Order Not Found");
    }
}
