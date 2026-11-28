import java.util.Scanner;

public class Solution {
    public static int lastInternalNode(int n) {
        if (n <= 1) return -1;
        return n / 2 - 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(lastInternalNode(n));
        }
        sc.close();
    }
}