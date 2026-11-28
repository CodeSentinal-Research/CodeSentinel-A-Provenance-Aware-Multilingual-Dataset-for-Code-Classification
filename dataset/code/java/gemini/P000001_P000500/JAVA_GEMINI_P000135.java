import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
            int low = 0, mid = 0, high = n - 1;
            while (mid <= high) {
                if (arr[mid] == 0) {
                    int t = arr[low]; arr[low] = arr[mid]; arr[mid] = t;
                    low++; mid++;
                } else if (arr[mid] == 1) {
                    mid++;
                } else {
                    int t = arr[mid]; arr[mid] = arr[high]; arr[high] = t;
                    high--;
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                if (i > 0) sb.append(' ');
                sb.append(arr[i]);
            }
            System.out.println(sb.toString());
        }
    }
}