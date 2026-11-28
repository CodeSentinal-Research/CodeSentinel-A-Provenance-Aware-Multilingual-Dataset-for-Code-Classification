import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), l = sc.nextInt(), r = sc.nextInt();
            long sum = 0;
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                if (i >= l && i <= r) sum += x;
            }
            System.out.println(sum);
        }
        sc.close();
    }
}