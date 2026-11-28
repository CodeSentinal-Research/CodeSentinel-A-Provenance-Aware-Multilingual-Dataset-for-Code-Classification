import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                int c = 0;
                for (int j = i + 1; j < n; j++) if (arr[j] < arr[i]) c++;
                sb.append(c).append(i == n - 1 ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}