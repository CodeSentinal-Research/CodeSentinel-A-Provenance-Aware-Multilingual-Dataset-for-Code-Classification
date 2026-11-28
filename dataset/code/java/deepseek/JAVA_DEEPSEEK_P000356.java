import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        char C = scanner.next().charAt(0);
        int index = S.indexOf(C);
        System.out.println(index != -1 ? index : -1);
    }
}
