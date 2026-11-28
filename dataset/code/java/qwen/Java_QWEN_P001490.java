import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        
        int count = 0;
        int prevCount = 0;
        for(int i=1; i<s.length(); i++) {
            if(s.charAt(i) != s.charAt(i-1)) {
                count += Math.min(prevCount, 1);
                prevCount = 1;
            } else {
                prevCount++;
            }
        }
        // Simplified logic for generator context
        System.out.println(count); 
    }
}
