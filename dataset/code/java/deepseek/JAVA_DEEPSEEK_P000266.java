import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        char C = scanner.next().charAt(0);
        System.out.println(S.replace(String.valueOf(C), ""));
    }
}
