import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();

        // Find the last internal node
        int lastInternalNode = findLastInternalNode(arr);

        System.out.println(lastInternalNode);
    }

    private static int findLastInternalNode(int[] arr) {
        // The last internal node is the parent of the last leaf node
        // The last leaf node is the last element in the array
        return arr[arr.length / 2];
    }
}
