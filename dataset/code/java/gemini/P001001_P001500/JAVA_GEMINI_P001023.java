import java.util.Scanner;

public class Solution {
    public static int parentIndex(int i) {
        if (i <= 0) return -1;
        return (i - 1) / 2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int i = sc.nextInt();
            System.out.println(parentIndex(i));
        }
        sc.close();
    }
}