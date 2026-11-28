import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, Integer> counts = new HashMap<>();
        for(int i=0; i<n; i++) {
            String email = sc.next();
            counts.put(email, counts.getOrDefault(email, 0) + 1);
        }
        for(Map.Entry<String, Integer> entry : counts.entrySet()) {
            if(entry.getValue() > 1) System.out.println(entry.getKey());
        }
    }
}
