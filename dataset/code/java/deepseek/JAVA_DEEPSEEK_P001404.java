import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        int[][] matrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextInt();
            }
            scanner.nextLine();
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            Map<Integer, Integer> rowMap = new HashMap<>();
            Map<Integer, Integer> colMap = new HashMap<>();
            for (int j = 0; j < n; j++) {
                rowMap.put(matrix[i][j], rowMap.getOrDefault(matrix[i][j], 0) + 1);
                colMap.put(matrix[j][i], colMap.getOrDefault(matrix[j][i], 0) + 1);
            }
            for (Map.Entry<Integer, Integer> entry : rowMap.entrySet()) {
                if (entry.getValue() > 1) {
                    count += entry.getValue() * (entry.getValue() - 1) / 2;
                }
            }
            for (Map.Entry<Integer, Integer> entry : colMap.entrySet()) {
                if (entry.getValue() > 1) {
                    count += entry.getValue() * (entry.getValue() - 1) / 2;
                }
            }
        }

        System.out.println(count);
    }
}
