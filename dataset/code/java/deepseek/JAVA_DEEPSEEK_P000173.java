import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int maxDiff = maxDifference(arr);
        System.out.println(maxDiff);
    }

    public static int maxDifference(int[] arr) {
        int maxDiff = -1;
        int minElement = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > minElement) {
                maxDiff = Math.max(maxDiff, arr[i] - minElement);
            } else {
                minElement = arr[i];
           }
        }

        return maxDiff;
    }
}
