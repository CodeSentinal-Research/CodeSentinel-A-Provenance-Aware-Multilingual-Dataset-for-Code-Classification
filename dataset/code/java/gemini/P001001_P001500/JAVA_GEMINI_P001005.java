import java.util.Scanner;

public class Solution {
    public static int countLeafNodes(int n) {
        return (n + 1) / 2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(countLeafNodes(n));
        }
        sc.close();
    }
}