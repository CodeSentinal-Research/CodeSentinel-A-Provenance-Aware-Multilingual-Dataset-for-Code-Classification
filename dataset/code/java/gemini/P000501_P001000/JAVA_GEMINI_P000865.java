import java.util.Scanner;

public class Solution {
    public static int xorAll(int[] arr) {
        int ans = 0;
        for (int x : arr) ans ^= x;
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            System.out.println(xorAll(arr));
        }
        sc.close();
    }
}