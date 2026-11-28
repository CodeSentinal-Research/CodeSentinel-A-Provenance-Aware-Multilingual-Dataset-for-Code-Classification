import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();
        int C = scanner.nextInt();
        int[][] matrix = new int[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        System.out.println(maximalRectangle(matrix));
    }

    public static int maximalRectangle(int[][] matrix) {
        if (matrix.length == 0) {
            return 0;
        }
        int maxArea = 0;
        int[] height = new int[matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                height[j] = (matrix[i][j] == 0) ? 0 : height[j] + 1;
            }
            maxArea = Math.max(maxArea, largestRectangleArea(height));
            height = new int[matrix[0].length];
        }
        return maxArea;
    }

    public static int largestRectangleArea(int[] height) {
        int maxArea = 0;
        java.util.Stack<Integer> stack = new java.util.Stack<>();
        for (int i = 0; i <= height.length; i++) {
            int h = (i == height.length) ? 0 : height[i];
            while (!stack.isEmpty() && h < height[stack.peek()]) {
                int j = stack.pop();
                maxArea = Math.max(maxArea, height[j] * (i - stack.peek() - 1));
                h = height[j];
            }
            stack.push(i);
        }
        return maxArea;
    }
}
