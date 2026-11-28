import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int r = scanner.nextInt(), c = scanner.nextInt();
            int maxV = Integer.MIN_VALUE;
            for (int i = 0; i < r * c; i++) {
                int v = scanner.nextInt();
                if (v > maxV) maxV = v;
            }
            System.out.println(maxV);
        }
    }
}