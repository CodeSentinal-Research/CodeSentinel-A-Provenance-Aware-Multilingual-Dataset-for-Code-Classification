import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int w = sc.nextInt();
        int h = sc.nextInt();
        int n = sc.nextInt();
        
        List<Integer> xCoords = new ArrayList<>();
        List<Integer> yCoords = new ArrayList<>();
        
        xCoords.add(0);
        xCoords.add(w);
        yCoords.add(0);
        yCoords.add(h);
        
        for(int i=0; i<n; i++) {
            xCoords.add(sc.nextInt());
            yCoords.add(sc.nextInt());
        }
        
        Collections.sort(xCoords);
        Collections.sort(yCoords);
        
        int maxGapX = 0;
        for(int i=1; i<xCoords.size(); i++) {
            maxGapX = Math.max(maxGapX, xCoords.get(i) - xCoords.get(i-1));
        }
        
        int maxGapY = 0;
        for(int i=1; i<yCoords.size(); i++) {
            maxGapY = Math.max(maxGapY, yCoords.get(i) - yCoords.get(i-1));
        }
        
        System.out.println((long)maxGapX * maxGapY);
    }
}
