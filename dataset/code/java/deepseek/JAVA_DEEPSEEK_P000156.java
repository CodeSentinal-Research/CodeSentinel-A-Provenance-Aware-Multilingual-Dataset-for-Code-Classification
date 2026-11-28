import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int maxConsecutiveZeros = maxConsecutiveZeros(arr);
        System.out.println(maxConsecutiveZeros);
    }

    private static int maxConsecutiveZeros(int[] arr) {
        int maxZeros = 0;
        int currentZeros = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0) {
                currentZeros++;
                maxZeros = Math.max(maxZeros, currentZeros);
            } else {
                currentZeros = 0;
            }
        }
        return maxZeros;
    }
}
