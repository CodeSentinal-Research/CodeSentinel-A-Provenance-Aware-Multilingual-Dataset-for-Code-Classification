import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numRows = sc.nextInt();
        
        List<List<Integer>> triangle = new ArrayList<>();
        for(int i=0; i<numRows; i++) {
            List<Integer> row = new ArrayList<>();
            for(int j=0; j<=i; j++) {
                if(j==0 || j==i) row.add(1);
                else row.add(triangle.get(i-1).get(j-1) + triangle.get(i-1).get(j));
            }
            triangle.add(row);
        }
        
        for(List<Integer> row : triangle) {
            for(int x : row) System.out.print(x + " ");
            System.out.println();
        }
    }
}
