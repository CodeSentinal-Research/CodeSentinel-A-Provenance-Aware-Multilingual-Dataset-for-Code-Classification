import java.util.*;

public class Main {
    public static void main(String[] args) {
        int rows = 3;
        int cols = 4;
        int rCenter = 0;
        int cCenter = 0;

        List<List<Integer>> result = allCellsDistOrder(rows, cols, rCenter, cCenter);
        for (List<Integer> cell : result) {
            System.out.println("[" + cell.get(0) + ", " + cell.get(1) + "]");
        }
    }

    public static List<List<Integer>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        List<List<Integer>> res = new ArrayList<>();
        boolean[][] visited = new boolean[rows][cols];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{rCenter, cCenter});
        visited[rCenter][cCenter] = true;

        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            res.add(Arrays.asList(cell[0], cell[1]));

            if (cell[0] > 0 && !visited[cell[0] - 1][cell[1]]) {
                queue.add(new int[]{cell[0] - 1, cell[1]});
                visited[cell[0] - 1][cell[1]] = true;
            }
            if (cell[0] < rows - 1 && !visited[cell[0] + 1][cell[1]]) {
                queue.add(new int[]{cell[0] + 1, cell[1]});
                visited[cell[0] + 1][cell[1]] = true;
            }
            if (cell[1] > 0 && !visited[cell[0]][cell[1] - 1]) {
                queue.add(new int[]{cell[0], cell[1] - 1});
                visited[cell[0]][cell[1] - 1] = true;
            }
            if (cell[1] < cols - 1 && !visited[cell[0]][cell[1] + 1]) {
                queue.add(new int[]{cell[0], cell[1] + 1});
                visited[cell[0]][cell[1] + 1] = true;
            }
        }
        return res;
    }
}
