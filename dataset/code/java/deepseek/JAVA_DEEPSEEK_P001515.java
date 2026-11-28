import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(countAlternatingSubarrays(arr));
    }

    public static long countAlternatingSubarrays(int[] arr) {
        long count = 0;
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                for (int j = i; j < n; j += 2) {
                    if (arr[j] == 1 && arr[j + 1] == 0) {
                        count++;
                    }
                }
            } else {
                for (int j = i; j < n; j += 2) {
                    if (arr[j] == 0 && arr[j + 1] == 1) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}
