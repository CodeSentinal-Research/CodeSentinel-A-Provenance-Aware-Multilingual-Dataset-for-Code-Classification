import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int[][] wall = new int[r][];
        for(int i=0; i<r; i++) {
            int k = sc.nextInt();
            wall[i] = new int[k];
            for(int j=0; j<k; j++) wall[i][j] = sc.nextInt();
        }
        
        Map<Integer, Integer> edgeCount = new HashMap<>();
        int maxEdges = 0;
        for(int[] row : wall) {
            int pos = 0;
            for(int i=0; i<row.length-1; i++) {
                pos += row[i];
                edgeCount.put(pos, edgeCount.getOrDefault(pos, 0) + 1);
                maxEdges = Math.max(maxEdges, edgeCount.get(pos));
            }
        }
        System.out.println(r - maxEdges);
    }
}
