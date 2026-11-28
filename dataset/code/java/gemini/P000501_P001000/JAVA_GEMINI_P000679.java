import java.util.*;
public class Solution {
    static void print1ToN(int n) {
        if (n <= 0) return;
        print1ToN(n - 1);
        System.out.print(n + " ");
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            print1ToN(n);
            System.out.println();
        }
    }
}