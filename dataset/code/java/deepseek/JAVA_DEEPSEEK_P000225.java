import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(minSwaps(arr));
    }

    static int minSwaps(int arr[]) {
        int n = arr.length;
        int ans = 0;
        boolean visited[] = new boolean[n];
        Arrays.fill(visited, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] || i == arr[i])
                continue;
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j];
                cycle_size++;
            }
            if (cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }
}