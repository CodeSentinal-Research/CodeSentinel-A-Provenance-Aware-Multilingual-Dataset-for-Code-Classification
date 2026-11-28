import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int collisions = 0;
        boolean hasLeft = false;
        for(char c : s.toCharArray()) {
            if(c == 'R') hasLeft = true; // Actually R moves right, L moves left. 
            // If we see R, it might collide with future Ls.
            // If we see L, it might collide with previous Rs.
        }
        // Simplified logic:
        // Count R's that eventually hit an L or S.
        // Count L's that eventually hit an R or S.
        // Standard solution:
        int rCount = 0;
        for(char c : s.toCharArray()) {
            if(c == 'R') rCount++;
            else if(c == 'L') {
                if(rCount > 0) {
                    collisions += rCount + 1; // All Rs hit this L, and this L hits them
                    rCount = 0;
                } else {
                    collisions++; // Hits stationary or end
                }
            } else if(c == 'S') {
                collisions += rCount;
                rCount = 0;
            }
        }
        System.out.println(collisions);
    }
}
