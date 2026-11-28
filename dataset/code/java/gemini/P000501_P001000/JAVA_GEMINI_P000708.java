import java.util.*;
public class Solution {
    static void hanoi(int n, char src, char dst, char aux) {
        if (n == 1) {
            System.out.println("Move disk 1 from " + src + " to " + dst);
            return;
        }
        hanoi(n - 1, src, aux, dst);
        System.out.println("Move disk " + n + " from " + src + " to " + dst);
        hanoi(n - 1, aux, dst, src);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            hanoi(n, 'A', 'C', 'B');
            System.out.println((1L << n) - 1);
        }
    }
}