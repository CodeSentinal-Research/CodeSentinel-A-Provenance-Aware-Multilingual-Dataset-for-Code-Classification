import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
            int minIdx = 0;
            for (int i = 1; i < n; i++) {
                if (arr[i] < arr[minIdx]) minIdx = i;
            }
            System.out.println(minIdx);
        }
    }
}