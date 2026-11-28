import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] inDegree = new int[n];
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                inDegree[v]++;
            }
            int count = 0;
            for (int d : inDegree) {
                if (d == 0) count++;
            }
            System.out.println(count);
        }
        sc.close();
    }
}