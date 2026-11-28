import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int maxVal = Integer.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                int v = scanner.nextInt();
                if (v > maxVal) maxVal = v;
            }
            System.out.println(maxVal);
        }
    }
}