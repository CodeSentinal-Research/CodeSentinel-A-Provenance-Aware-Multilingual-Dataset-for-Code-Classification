import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] ids = new String[n], exps = new String[n];
            for (int i = 0; i < n; i++) { ids[i] = scanner.next(); exps[i] = scanner.next(); }
            String currDate = scanner.next();
            for (int i = 0; i < n; i++) if (exps[i].compareTo(currDate) < 0) System.out.println(ids[i]);
        }
    }
}