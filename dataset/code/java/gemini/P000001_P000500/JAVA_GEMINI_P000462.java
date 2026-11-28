import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] arr = new int[n - 1];
            for (int i = 0; i < n - 1; i++) arr[i] = scanner.nextInt();
            int diff = (arr[n - 2] - arr[0]) / (n - 1);
            for (int i = 0; i < n - 2; i++) {
                if (arr[i + 1] - arr[i] != diff) {
                    System.out.println(arr[i] + diff);
                    return;
                }
            }
            System.out.println(arr[n - 2] + diff);
        }
    }
}