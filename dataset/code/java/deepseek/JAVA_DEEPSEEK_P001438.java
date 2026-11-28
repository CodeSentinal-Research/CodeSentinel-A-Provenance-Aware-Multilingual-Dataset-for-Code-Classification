import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        if (canBePartitioned(arr)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static boolean canBePartitioned(int[] arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;
        int count = 0;
        for (int num : arr) {
            if (num == sum) {
                count++;
            }
        }
        return count >= 2;
    }
}
