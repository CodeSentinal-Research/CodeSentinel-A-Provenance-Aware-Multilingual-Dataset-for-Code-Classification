import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int val = sc.nextInt();
            int[] arr = new int[n + 1];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            arr[n] = val;
            int i = n;
            while (i > 0) {
                int p = (i - 1) / 2;
                if (arr[i] < arr[p]) {
                    int t = arr[i]; arr[i] = arr[p]; arr[p] = t;
                    i = p;
                } else {
                    break;
                }
            }
            for (int j = 0; j <= n; j++) {
                System.out.print(arr[j] + (j == n ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}