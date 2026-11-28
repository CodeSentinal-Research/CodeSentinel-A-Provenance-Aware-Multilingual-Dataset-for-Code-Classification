import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < N; i++) {
            String[] tree1 = scanner.nextLine().split(" ");
            String[] tree2 = scanner.nextLine().split(" ");

            if (tree1.length != tree2.length) {
                System.out.println("NO");
                return;
            }

            for (int j = 0; j < tree1.length; j++) {
                if (!tree1[j].equals(tree2[j])) {
                    System.out.println("NO");
                    return;
                }
            }
        }

        System.out.println("YES");
    }
}
