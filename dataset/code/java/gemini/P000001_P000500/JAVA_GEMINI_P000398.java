import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] vehicles = new String[n];
            String[] manufs = new String[n];
            for (int i = 0; i < n; i++) {
                vehicles[i] = scanner.next();
                manufs[i] = scanner.next();
            }
            String target = scanner.next();
            for (int i = 0; i < n; i++) {
                if (manufs[i].equals(target)) {
                    System.out.println(vehicles[i]);
                }
            }
        }
    }
}