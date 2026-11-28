import java.util.Scanner;

public class Solution {
    public static int findMinInMaxHeap(int[] arr) {
        int n = arr.length;
        int leafStart = n / 2;
        int minVal = arr[leafStart];
        for (int i = leafStart + 1; i < n; i++) {
            if (arr[i] < minVal) minVal = arr[i];
        }
        return minVal;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            System.out.println(findMinInMaxHeap(arr));
        }
        sc.close();
    }
}