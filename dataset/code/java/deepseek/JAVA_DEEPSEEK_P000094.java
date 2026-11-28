import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        if (isHarshad(n)) {
            System.out.println("Harshad");
        } else {
            System.out.println("Not Harshad");
        }
    }

    private static boolean isHarshad(int n) {
        int sum = 0;
        int temp = n;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        return n % sum == 0;
    }
}
