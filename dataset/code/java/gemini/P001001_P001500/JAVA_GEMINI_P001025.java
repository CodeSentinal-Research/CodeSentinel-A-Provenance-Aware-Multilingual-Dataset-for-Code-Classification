import java.util.Scanner;

public class Solution {
    public static int countInternalNodes(int n) {
        return n / 2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(countInternalNodes(n));
        }
        sc.close();
    }
}