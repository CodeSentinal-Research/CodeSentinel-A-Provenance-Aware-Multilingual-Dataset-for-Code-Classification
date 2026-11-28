import java.util.Scanner;

public class Solution {
    public static int heapHeight(int n) {
        if (n <= 0) return 0;
        return (int) (Math.log(n) / Math.log(2));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(heapHeight(n));
        }
        sc.close();
    }
}