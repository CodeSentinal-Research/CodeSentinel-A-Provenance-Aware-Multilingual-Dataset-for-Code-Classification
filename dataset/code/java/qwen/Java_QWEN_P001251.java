import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        Box[] boxes = new Box[n];
        for(int i=0; i<n; i++) {
            boxes[i] = new Box(sc.nextInt(), sc.nextInt());
        }
        
        Arrays.sort(boxes, (a, b) -> b.units - a.units);
        
        long totalUnits = 0;
        for(Box box : boxes) {
            if(t == 0) break;
            int take = Math.min(t, box.count);
            totalUnits += (long)take * box.units;
            t -= take;
        }
        System.out.println(totalUnits);
    }
}
class Box {
    int count, units;
    Box(int c, int u) { count = c; units = u; }
}
