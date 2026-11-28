import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] names = new String[n];
            String[] depts = new String[n];
            for (int i = 0; i < n; i++) {
                names[i] = scanner.next();
                depts[i] = scanner.next();
            }
            String targetDept = scanner.next();
            boolean found = false;
            for (int i = 0; i < n; i++) {
                if (depts[i].equals(targetDept)) {
                    System.out.println(names[i]);
                    found = true;
                }
            }
            if (!found) {
                System.out.println("No Records Found");
            }
        }
    }
}