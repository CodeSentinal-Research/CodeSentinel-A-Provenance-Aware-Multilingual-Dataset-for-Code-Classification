import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(minSubArraySum(arr));
    }

    private static int minSubArraySum(int[] arr) {
        int minSoFar = Integer.MAX_VALUE;
        int minEndingHere = 0;

        for (int i : arr) {
            minEndingHere += i;
            if (minSoFar > minEndingHere) {
                minSoFar = minEndingHere;
            }
            minEndingHere = Math.min(minEndingHere, 0);
        }

        return minSoFar;
    }
}
