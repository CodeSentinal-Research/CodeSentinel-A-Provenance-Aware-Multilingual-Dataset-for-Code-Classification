import java.util.Scanner;

public class Solution {
    public static Integer findSecondLargest(int[] arr) {
        if (arr == null || arr.length < 2) return null;
        long first = Long.MIN_VALUE, second = Long.MIN_VALUE;
        for (int x : arr) {
            if (x > first) {
                second = first;
                first = x;
            } else if (x > second && x != first) {
                second = x;
            }
        }
        return second == Long.MIN_VALUE ? null : (int) second;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            Integer res = findSecondLargest(arr);
            System.out.println(res != null ? res : "Does not exist");
        }
        sc.close();
    }
}