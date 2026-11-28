import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String binary = Integer.toBinaryString(n);
        System.out.println(binary);
    }
}
