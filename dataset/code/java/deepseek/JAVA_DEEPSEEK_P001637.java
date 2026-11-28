import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();

        int leafCount = 0;
        for (int i = 0; i < N; i++) {
            String line = scanner.nextLine();
            // Check if the line is empty, if so, skip to the next iteration
            if (line.isEmpty()) {
                continue;
            }
            // If the line is not empty, it's a node, so increment the leaf count
            leafCount++;
        }

        System.out.println(leafCount);
    }
}
