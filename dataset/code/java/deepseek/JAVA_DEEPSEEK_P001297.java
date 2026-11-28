import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];

        for (int i = 0; i < n; i++) {
            arr1[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            arr2[i] = scanner.nextInt();
        }

        System.out.println(maxSum(arr1, arr2));
    }

    private static int maxSum(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int[] sorted1 = sort(arr1);
        int[] sorted2 = sort(arr2);
        int maxSum = 0;

        for (int i = 0; i < n; i++) {
            maxSum += Math.max(sorted1[i], sorted2[i]);
        }

        return maxSum;
    }

    private static int[] sort(int[] arr) {
        int[] sorted = new int[arr.length];
        System.arraycopy(arr, 0, sorted, 0, arr.length);

        for (int i = 0; i < sorted.length; i++) {
            for (int j = i + 1; j < sorted.length; j++) {
                if (sorted[i] < sorted[j]) {
                    int temp = sorted[i];
                    sorted[i] = sorted[j];
                    sorted[j] = temp;
                }
            }
        }

        return sorted;
    }
}
