import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] people = new int[n][2];
        for(int i=0; i<n; i++) {
            people[i][0] = sc.nextInt();
            people[i][1] = sc.nextInt();
        }
        
        Arrays.sort(people, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        
        List<int[]> res = new ArrayList<>();
        for(int[] p : people) {
            res.add(p[1], p);
        }
        
        for(int[] p : res) {
            System.out.print(p[0] + " " + p[1] + "
");
        }
    }
}
