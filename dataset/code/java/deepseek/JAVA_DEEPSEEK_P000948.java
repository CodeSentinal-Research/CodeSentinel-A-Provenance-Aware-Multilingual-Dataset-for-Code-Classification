import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int x = scanner.nextInt();
        int y = scanner.nextInt();

        if ((x + y) % 2 == 0) {
            System.out.println("First");
       } else {
            System.out.println("Second");
        }
    }
}
