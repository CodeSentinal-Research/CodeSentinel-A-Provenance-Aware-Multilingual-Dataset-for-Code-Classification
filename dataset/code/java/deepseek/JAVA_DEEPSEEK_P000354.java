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
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (array[i] == X) {
                count++;
            }
       }
        System.out.println(count);
    }
}
