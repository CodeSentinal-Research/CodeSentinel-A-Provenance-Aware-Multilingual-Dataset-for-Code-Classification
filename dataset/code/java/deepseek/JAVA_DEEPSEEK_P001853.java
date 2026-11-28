import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String[] nodes = scanner.nextLine().split(" ");
        boolean hasTwoChildren = false;
        for (int i = 1; i < n; i++) {
            if (nodes[i-1].compareTo(nodes[i]) > 0) {
                if (hasTwoChildren) {
                    System.out.println("NO");
                    return;
                }
            } else {
                hasTwoChildren = true;
            }
       }
        if (hasTwoChildren) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }
    }
}
