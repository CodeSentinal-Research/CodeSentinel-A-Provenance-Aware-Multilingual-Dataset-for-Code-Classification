import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            int level = 0, start = 0;
            while (start < n) {
                int count = 1 << level;
                int end = Math.min(n, start + count);
                for (int i = start; i < end; i++) {
                    System.out.print(arr[i] + (i == end - 1 ? "" : " "));
                }
                System.out.println();
                start = end;
                level++;
            }
        }
        sc.close();
    }
}