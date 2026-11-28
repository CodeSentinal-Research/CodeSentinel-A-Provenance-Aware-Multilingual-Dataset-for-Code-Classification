import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            for (int i = 0; i < n; i++) {
                String uname = scanner.next();
                String status = scanner.next().toLowerCase();
                if (status.equals("active") || status.equals("true") || status.equals("1") || status.equals("yes") || status.equals("enabled")) {
                    System.out.println(uname);
                }
            }
        }
    }
}