import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        long count = 0;
        int[] lastSeen = new int[5];
        Arrays.fill(lastSeen, -1);
        
        for(int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            if(c=='a') lastSeen[0] = i;
            else if(c=='e') lastSeen[1] = i;
            else if(c=='i') lastSeen[2] = i;
            else if(c=='o') lastSeen[3] = i;
            else if(c=='u') lastSeen[4] = i;
            
            int minIdx = Integer.MAX_VALUE;
            for(int idx : lastSeen) {
                if(idx == -1) {
                    minIdx = -1;
                    break;
                }
                minIdx = Math.min(minIdx, idx);
            }
            
            if(minIdx != -1) count += (minIdx + 1);
        }
        System.out.println(count);
    }
}
