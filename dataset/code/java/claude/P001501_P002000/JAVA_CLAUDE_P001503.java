import java.util.Scanner;
public class Solution {
    public int[] swap(int a, int b) { return new int[]{b, a}; }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] r = new Solution().swap(sc.nextInt(), sc.nextInt());
        System.out.println(r[0] + " " + r[1]);
    }
}
