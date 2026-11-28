import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int scored = scanner.nextInt();
        int total = scanner.nextInt();
        double percentage = (double) scored / total * 100;
        System.out.printf("%.2f", percentage);
    }
}
