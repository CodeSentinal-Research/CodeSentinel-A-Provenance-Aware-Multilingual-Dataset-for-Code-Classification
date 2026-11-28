import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            long inc = 0, exc = 0;
            for (int i = 0; i < n; i++) {
                long x = sc.nextLong();
                long newInc = exc + x;
                long newExc = Math.max(inc, exc);
                inc = newInc;
                exc = newExc;
            }
            System.out.println(Math.max(inc, exc));
        }
        sc.close();
    }
}