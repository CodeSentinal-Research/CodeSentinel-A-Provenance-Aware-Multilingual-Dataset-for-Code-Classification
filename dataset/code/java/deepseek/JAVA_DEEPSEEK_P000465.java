import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int diff = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
       }
       
        System.out.println(hasPairWithDifference(arr, diff) ? "Yes" : "No");
    }

    private static boolean hasPairWithDifference(int[] arr, int diff) {
        int i = 0;
        int j = 1;
        while (j < arr.length) {
            if (arr[j] - arr[i] == diff) {
                return true;
            }
            if (arr[j] - arr[i] < diff) {
                j++;
            } else {
                i++;
            }
        }
        return false;
    }
}
