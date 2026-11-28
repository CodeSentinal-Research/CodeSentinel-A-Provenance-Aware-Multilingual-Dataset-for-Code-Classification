import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String[] sequence1 = scanner.nextLine().split(" ");
        String[] sequence2 = scanner.nextLine().split(" ");

        boolean isSame = true;
        for (int i = 0; i < n; i++) {
            if (!sequence1[i].equals(sequence2[i])) {
                isSame = false;
                break;
            }
        }

        System.out.println(isSame ? "YES" : "NO");
    }
}
