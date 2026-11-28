import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            List<Integer> l1 = new ArrayList<>();
            for (int i = 0; i < n; i++) l1.add(scanner.nextInt());
            int m = scanner.nextInt();
            List<Integer> l2 = new ArrayList<>();
            for (int i = 0; i < m; i++) l2.add(scanner.nextInt());
            System.out.println(l1.equals(l2) ? "true" : "false");
        }
    }
}