import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        boolean hasTwoChildren = true;
        for (int i = 0; i < n; i++) {
            String[] line = scanner.nextLine().split(" ");
            if (line.length > 2) {
                hasTwoChildren = false;
                break;
           }
        }
        System.out.println(hasTwoChildren ? "YES" : "NO");
    }
}
