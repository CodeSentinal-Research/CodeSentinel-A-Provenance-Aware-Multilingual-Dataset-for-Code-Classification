import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int additionalRocks = sc.nextInt();
        int[] capacity = new int[n];
        int[] rocks = new int[n];
        for(int i=0; i<n; i++) capacity[i] = sc.nextInt();
        for(int i=0; i<n; i++) rocks[i] = sc.nextInt();
        
        int[] remaining = new int[n];
        for(int i=0; i<n; i++) remaining[i] = capacity[i] - rocks[i];
        Arrays.sort(remaining);
        
        int fullBags = 0;
        for(int r : remaining) {
            if(additionalRocks >= r) {
                additionalRocks -= r;
                fullBags++;
            } else {
                break;
            }
        }
        System.out.println(fullBags);
    }
}
