import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        System.out.println(findMedian(matrix));
    }

    private static int findMedian(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int totalElements = rows * cols;
        int targetIndex = totalElements / 2;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < rows; i++) {
            min = Math.min(min, matrix[i][0]);
            max = Math.max(max, matrix[i][cols - 1]);
        }
        while (min < max) {
            int mid = min + (max - min) / 2;
            int count = 0;
            for (int i = 0; i < rows; i++) {
                count += countElements(matrix[i], mid);
            }
            if (count <= targetIndex) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }
        return min;
    }

    private static int countElements(int[] array, int target) {
        int left = 0;
        int right = array.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (array[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
