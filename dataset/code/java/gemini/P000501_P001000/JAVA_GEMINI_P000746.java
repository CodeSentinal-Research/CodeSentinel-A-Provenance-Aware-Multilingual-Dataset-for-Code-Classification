import java.util.*;
public class Solution {
    static int josephus(int n, int k) {
        if (n == 1) return 1;
        return (josephus(n - 1, k) + k - 1) % n + 1;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            System.out.println(josephus(scanner.nextInt(), scanner.nextInt()));
        }
    }
}