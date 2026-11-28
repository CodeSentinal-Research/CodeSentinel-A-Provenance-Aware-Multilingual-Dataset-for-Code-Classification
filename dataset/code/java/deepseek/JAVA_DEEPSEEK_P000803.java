import java.util.HashMap;
import java.util.Map;

public class Main {
    public static int numSubmatrixSumTarget(int[][] matrix, int target) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        for (int i = 0; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
       
           int count = 0;
           Map<Integer, Integer> map = new HashMap<>();

           for (int j = 0; j < cols; j++) {
               map.clear();
               map.put(0, 1);
               int curSum = 0;
               for (int k = j; k < cols; k++) {
                   curSum += matrix[i][k];
                   if (map.containsKey(curSum - target)) {
                       count += map.get(curSum - target);
                   }
                   map.put(curSum, map.getOrDefault(curSum, 0) + 1);
               }
           }

           return count;
       }

       return 0;
   }

   public static void main(String[] args) {
       int[][] matrix = {{0,1,0,1,0},{0,0,1,0,1},{1,1,1,0,1},{0,1,0,0,0},{0,0,1,1,0}};
       int target = 2;
       System.out.println(numSubmatrixSumTarget(matrix, target));
   }
}
