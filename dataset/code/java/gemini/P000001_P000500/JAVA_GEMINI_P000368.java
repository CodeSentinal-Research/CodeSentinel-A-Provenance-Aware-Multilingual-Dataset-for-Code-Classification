import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] arr = new String[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.next();
            int maxIdx = 0;
            for (int i = 1; i < n; i++) {
                if (arr[i].length() > arr[maxIdx].length()) maxIdx = i;
            }
            System.out.println(maxIdx);
        }
    }
}