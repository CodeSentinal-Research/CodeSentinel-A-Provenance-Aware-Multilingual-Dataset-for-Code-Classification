import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int S = scanner.nextInt();
        if (S < 3 || S > 12 || S % 2 != 0) {
            System.out.println(0);
        } else {
            System.out.println(1.0 / 3);
        }
    }
}
