import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int target = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
            int first = -1, last = -1;
            for (int i = 0; i < n; i++) {
                if (arr[i] == target) {
                    if (first == -1) first = i;
                    last = i;
                }
            }
            System.out.println(first + " " + last);
        }
    }
}