import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int minVal = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                if (i < k) minVal = Math.min(minVal, x);
            }
            System.out.println(minVal);
        }
        sc.close();
    }
}