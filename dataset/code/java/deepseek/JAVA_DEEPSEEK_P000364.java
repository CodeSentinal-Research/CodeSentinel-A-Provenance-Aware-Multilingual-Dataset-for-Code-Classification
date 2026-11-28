import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            int query = scanner.nextInt();
            boolean found = false;
            for (int j = 0; j < n; j++) {
                if (array[j] == query) {
                    found = true;
                    break;
                }
            }
            System.out.println(found ? "Found" : "Not Found");
        }
    }
}
