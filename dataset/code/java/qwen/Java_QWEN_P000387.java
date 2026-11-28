import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            String txId = sc.next();
            String amount = sc.next();
            map.put(txId, amount);
        }
        String searchTx = sc.next();
        if(map.containsKey(searchTx)) System.out.println(map.get(searchTx));
        else System.out.println("Transaction Not Found");
    }
}
