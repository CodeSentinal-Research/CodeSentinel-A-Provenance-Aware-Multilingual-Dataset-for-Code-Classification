import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int target = scanner.nextInt();
        int[] arr = new int[100000];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i + 1;
        }
        System.out.println(findTarget(arr, target));
    }

    public static int findTarget(int[] arr, int target) {
        int start = 0;
        int end = 1;
        while (target > arr[end]) {
            start = end;
            end *= 2;
       
            if (end > arr.length - 1) {
                end = arr.length - 1;
                break;
            }
        }
        return binarySearch(arr, target, start, end);
    }

    public static int binarySearch(int[] arr, int target, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == arr[mid]) {
                return mid;
            } else if (target < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
}
