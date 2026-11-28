import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int rows = scanner.nextInt(), cols = scanner.nextInt();
            int r0 = scanner.nextInt(), c0 = scanner.nextInt();
            List<int[]> cells = new ArrayList<>();
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) cells.add(new int[]{r, c});
            }
            cells.sort((a, b) -> (Math.abs(a[0] - r0) + Math.abs(a[1] - c0)) - (Math.abs(b[0] - r0) + Math.abs(b[1] - c0)));
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < cells.size(); i++) {
                sb.append("[").append(cells.get(i)[0]).append(",").append(cells.get(i)[1]).append("]").append(i + 1 == cells.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}