import java.util.Scanner;

public class Solution {
    public static int nodeLevel(int idx) {
        return (int) (Math.log(idx + 1) / Math.log(2));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int idx = sc.nextInt();
            System.out.println(nodeLevel(idx));
        }
        sc.close();
    }
}