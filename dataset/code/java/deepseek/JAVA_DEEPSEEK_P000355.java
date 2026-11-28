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

        boolean isPresent = false;
        for (int i = 0; i < N; i++) {
            if (array[i] == X) {
                isPresent = true;
                break;
            }
        }

        if (isPresent) {
            System.out.println("Present");
        } else {
            System.out.println("Missing");
        }
    }
}
