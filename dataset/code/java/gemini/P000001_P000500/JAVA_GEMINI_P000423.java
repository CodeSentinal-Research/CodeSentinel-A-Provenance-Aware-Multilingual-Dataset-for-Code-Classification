import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] ids = new String[n];
            int[] days = new int[n];
            for (int i = 0; i < n; i++) { ids[i] = scanner.next(); days[i] = scanner.nextInt(); }
            int d = scanner.nextInt();
            for (int i = 0; i < n; i++) if (days[i] > d) System.out.println(ids[i]);
        }
    }
}