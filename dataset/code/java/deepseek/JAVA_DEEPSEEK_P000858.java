import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(Integer.toBinaryString(n).length() - Integer.toBinaryString(n).replaceFirst("1", "").length());
    }
}
