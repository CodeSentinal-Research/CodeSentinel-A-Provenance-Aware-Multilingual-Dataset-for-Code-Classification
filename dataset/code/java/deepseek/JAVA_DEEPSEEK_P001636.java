import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] heights = new int[N];
        for (int i = 0; i < N; i++) {
            int left = scanner.nextInt();
            int right = scanner.nextInt();
            heights[i] = 1 + Math.max(heights[left], heights[right]);
        }
        for (int height : heights) {
            System.out.println(height);
        }
    }
}
