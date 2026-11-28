import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] names = new String[n], depts = new String[n], statuses = new String[n];
            for (int i = 0; i < n; i++) { names[i] = scanner.next(); depts[i] = scanner.next(); statuses[i] = scanner.next(); }
            String targetDept = scanner.next();
            for (int i = 0; i < n; i++) {
                String st = statuses[i].toLowerCase();
                if (depts[i].equals(targetDept) && (st.equals("active") || st.equals("true") || st.equals("1") || st.equals("yes"))) {
                    System.out.println(names[i]);
                }
            }
        }
    }
}