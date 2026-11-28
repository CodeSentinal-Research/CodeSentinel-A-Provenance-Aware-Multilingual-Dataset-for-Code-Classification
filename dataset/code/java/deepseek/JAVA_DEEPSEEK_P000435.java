import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int target = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
       }
        System.out.println(countOccurrences(arr, target));
    }

    public static int countOccurrences(int[] arr, int target) {
        int firstOccurrence = findFirstOccurrence(arr, target);
        if (firstOccurrence == -1) {
            return 0;
        }
        int lastOccurrence = findLastOccurrence(arr, target);
        return lastOccurrence - firstOccurrence + 1;
    }

    public static int findFirstOccurrence(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                if (mid > 0 && arr[mid - 1] == target) {
                    high = mid - 1;
                } else {
                    return mid;
                }
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    public static int findLastOccurrence(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                if (mid < arr.length - 1 && arr[mid + 1] == target) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
}
