import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(longestMountain(arr));
    }

    public static int longestMountain(int[] arr) {
        int n = arr.length;
        int ans = 0, i = 0, j;
        while (i < n) {
            j = i;
            if (j + 2 < n && arr[j] < arr[j + 1] && arr[j + 1] > arr[j + 2]) {
                while (j + 2 < n && arr[j] < arr[j + 1] && arr[j + 1] > arr[j + 2]) {
                    j++;
                }
                if (j + 2 < n && arr[j] > arr[j + 1]) {
                    while (j + 2 < n && arr[j] > arr[j + 1]) {
                        j++;
                    }
                    ans = Math.max(ans, j - i + 1);
                }
            }
            i = j;
        }
        return ans;
    }
}
