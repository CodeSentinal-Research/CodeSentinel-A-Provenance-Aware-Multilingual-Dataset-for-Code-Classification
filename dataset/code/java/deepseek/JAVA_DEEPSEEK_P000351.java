import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        int x = scanner.nextInt();
        boolean found = false;
        for (int num : array) {
            if (num == x) {
                found = true;
                break;
            }
        }
        System.out.println(found ? "Found" : "Not Found");
    }
}
