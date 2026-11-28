import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int[] target = new int[m];
        for(int i=0; i<m; i++) target[i] = sc.nextInt();
        int n = sc.nextInt();
        
        List<String> ops = new ArrayList<>();
        int curr = 1;
        for(int num : target) {
            while(curr < num) {
                ops.add("Push");
                ops.add("Pop");
                curr++;
            }
            ops.add("Push");
            curr++;
        }
        for(String op : ops) System.out.print(op + " ");
    }
}
