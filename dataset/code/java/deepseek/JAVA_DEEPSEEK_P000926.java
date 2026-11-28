import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        String octal = Long.toOctalString(n);
        String hexadecimal = Long.toHexString(n);
        System.out.println(octal.toUpperCase() + " " + hexadecimal.toUpperCase());
    }
}
