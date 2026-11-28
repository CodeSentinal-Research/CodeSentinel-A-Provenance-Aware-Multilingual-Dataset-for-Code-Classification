import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] products = new String[n];
            for (int i = 0; i < n; i++) products[i] = scanner.next();
            String suffix = scanner.next();
            for (String p : products) if (p.endsWith(suffix)) System.out.println(p);
        }
    }
}