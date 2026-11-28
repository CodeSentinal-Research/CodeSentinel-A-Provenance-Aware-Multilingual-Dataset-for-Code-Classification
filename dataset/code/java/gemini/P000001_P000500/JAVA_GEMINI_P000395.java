import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            for (int i = 0; i < n; i++) {
                String room = scanner.next();
                String status = scanner.next().toLowerCase();
                if (status.equals("available") || status.equals("true") || status.equals("1") || status.equals("yes") || status.equals("free")) {
                    System.out.println(room);
                }
            }
        }
    }
}