import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), l = sc.nextInt(), r = sc.nextInt();
            int count = 0;
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                if (i >= l && i <= r && x == 0) count++;
            }
            System.out.println(count);
        }
        sc.close();
    }
}