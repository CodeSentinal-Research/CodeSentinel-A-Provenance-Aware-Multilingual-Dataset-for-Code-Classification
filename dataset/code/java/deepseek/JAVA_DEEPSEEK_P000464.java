import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int target = scanner.nextInt();
        int[] array = new int[N];
        for (int i = 0; i < N; i++) {
            array[i] = scanner.nextInt();
       }
       
        int closest = findClosest(array, target);
        System.out.println(closest);
    }

    private static int findClosest(int[] array, int target) {
        return array[Arrays.binarySearch(array, target) >= 0 ? Arrays.binarySearch(array, target) : Math.abs(Arrays.binarySearch(array, target)) - 1];
    }
}
