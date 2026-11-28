import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String binaryString = scanner.next();
        System.out.println(Integer.parseInt(binaryString, 2));
    }
}
