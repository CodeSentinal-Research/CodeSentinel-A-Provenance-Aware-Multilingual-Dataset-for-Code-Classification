import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int i = sc.nextInt();
            int n = sc.nextInt();
            int l = (2 * i + 1 < n) ? 2 * i + 1 : -1;
            int r = (2 * i + 2 < n) ? 2 * i + 2 : -1;
            System.out.println(l + " " + r);
        }
        sc.close();
    }
}