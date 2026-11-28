import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rowIndex = sc.nextInt();
        
        List<Integer> row = new ArrayList<>();
        row.add(1);
        for(int i=1; i<=rowIndex; i++) {
            for(int j=row.size()-1; j>0; j--) {
                row.set(j, row.get(j) + row.get(j-1));
            }
            row.add(1);
        }
        
        for(int x : row) System.out.print(x + " ");
    }
}
