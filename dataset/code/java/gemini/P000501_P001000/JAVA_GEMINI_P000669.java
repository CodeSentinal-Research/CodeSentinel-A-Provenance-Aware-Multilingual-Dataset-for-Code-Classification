import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            if (n == 0) { System.out.println(-1); return; }
            int minV = scanner.nextInt();
            for (int i = 1; i < n; i++) {
                int x = scanner.nextInt();
                if (x < minV) minV = x;
            }
            System.out.println(minV);
        } else {
            System.out.println(-1);
        }
    }
}