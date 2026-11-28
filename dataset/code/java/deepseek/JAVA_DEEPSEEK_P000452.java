import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(findSingle(arr));
    }

    private static int findSingle(int[] arr) {
        int low = 0;
        int high = arr.length - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] != arr[mid ^ 1]) {
                high = mid;
            } else {
                low = mid + 2;
            }
       }
        return arr[low];
    }
}
