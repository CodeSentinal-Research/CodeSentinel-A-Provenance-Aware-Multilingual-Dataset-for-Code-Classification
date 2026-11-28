import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String preorder = scanner.nextLine();
        System.out.println(isValid(preorder) ? "YES" : "NO");
    }

    private static boolean isValid(String preorder) {
        String[] nodes = preorder.split(" ");
        int count = 0;

        for (String node : nodes) {
            if (node.equals("X")) {
                count++;
                if (count > 2) {
                    return false;
                }
            } else {
                count = 0;
            }
        }

        return count == 2;
    }
}
