import java.util.Scanner;

public class Solution {
    public static int countLeadingZeros(int n) {
        return Integer.numberOfLeadingZeros(n);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(countLeadingZeros(n));
        }
        sc.close();
    }
}