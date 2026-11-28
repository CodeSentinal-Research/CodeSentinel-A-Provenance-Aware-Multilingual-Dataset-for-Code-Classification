import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] array = new int[N];
        for (int i = 0; i < N; i++) {
            array[i] = scanner.nextInt();
        }
        int X = scanner.nextInt();
        scanner.close();

        int result = findFirstGreater(array, X);
        System.out.println(result);
    }

    private static int findFirstGreater(int[] array, int target) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] > target) {
                return i;
           }
        }
        return -1;
    }
}
