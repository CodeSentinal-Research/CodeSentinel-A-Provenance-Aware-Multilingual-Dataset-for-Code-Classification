import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.println(countLeafNodes(N));
    }

    private static int countLeafNodes(int N) {
        // The formula for the number of leaf nodes in a complete binary heap is (2^h) - 1, where h is the height of the heap.
        // In this case, we can calculate the height of the heap by finding the log2 of N + 1.
        int height = (int)Math.ceil(Math.log(N + 1) / Math.log(2));
        return (int)Math.pow(2, height) - 1;
    }
}
