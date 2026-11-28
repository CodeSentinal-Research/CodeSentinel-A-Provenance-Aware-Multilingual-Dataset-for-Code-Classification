import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();

        int maxWidth = 0;
        int currentWidth = 0;
        int maxLevel = 0;
        int currentLevel = 0;

        while (N-- > 0) {
            String line = scanner.nextLine();
            String[] nodes = line.split(" ");
            int nodeCount = nodes.length;

            if (nodeCount == 1) {
                // Leaf node
                currentWidth++;
            } else {
                // Internal node
                currentWidth = nodeCount;
            }

            if (currentWidth > maxWidth) {
                maxWidth = currentWidth;
                maxLevel = currentLevel;
            }

            currentLevel++;
        }

        System.out.println(maxWidth);
    }
}
