import java.util.Scanner;

public class Solution {
    public static int countFrequency(int[] arr, int target) {
        int count = 0;
        for (int x : arr) {
            if (x == target) count++;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int target = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            System.out.println(countFrequency(arr, target));
        }
        sc.close();
    }
}