import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int rCenter = sc.nextInt();
        int cCenter = sc.nextInt();
        
        List<int[]> cells = new ArrayList<>();
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                cells.add(new int[]{i, j});
            }
        }
        
        cells.sort((a, b) -> {
            int d1 = Math.abs(a[0] - rCenter) + Math.abs(a[1] - cCenter);
            int d2 = Math.abs(b[0] - rCenter) + Math.abs(b[1] - cCenter);
            return d1 - d2;
        });
        
        for(int[] cell : cells) {
            System.out.println("[" + cell[0] + "," + cell[1] + "]");
        }
    }
}
