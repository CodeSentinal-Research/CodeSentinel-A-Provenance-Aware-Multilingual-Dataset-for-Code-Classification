import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String str = scanner.nextLine();
        char c = scanner.nextLine().charAt(0);

        int[] distances = new int[str.length()];
        int lastOccurrence = -1;

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == c) {
                lastOccurrence = i;
            }
            distances[i] = lastOccurrence == -1 ? Integer.MAX_VALUE : i - lastOccurrence;
        }

        for (int distance : distances) {
            System.out.println(distance);
        }
    }
}
