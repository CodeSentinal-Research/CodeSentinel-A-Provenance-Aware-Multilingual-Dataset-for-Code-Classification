import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            String[] nodes = scanner.nextLine().split(" ");
            int left = Integer.parseInt(nodes[0]);
            int right = Integer.parseInt(nodes[1]);

            if (left == -1 && right == -1) {
                System.out.println("YES");
            } else if (left == -1 || right == -1) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
    }
}
