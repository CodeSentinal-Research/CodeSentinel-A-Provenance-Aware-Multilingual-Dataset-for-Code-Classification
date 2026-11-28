import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int length = scanner.nextInt();
        int breadth = scanner.nextInt();
        int perimeter = 2 * (length + breadth);
        System.out.println(perimeter);
   scanner.close();
    }
}
