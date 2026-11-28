import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        char maxChar = s.charAt(0);
        int maxCount = 1;
        int currCount = 1;
        
        for(int i=1; i<s.length(); i++) {
            if(s.charAt(i) == s.charAt(i-1)) {
                currCount++;
            } else {
                if(currCount > maxCount || (currCount == maxCount && s.charAt(i-1) < maxChar)) {
                    maxCount = currCount;
                    maxChar = s.charAt(i-1);
                }
                currCount = 1;
            }
        }
        if(currCount > maxCount || (currCount == maxCount && s.charAt(s.length()-1) < maxChar)) {
            maxCount = currCount;
            maxChar = s.charAt(s.length()-1);
        }
        
        System.out.println(maxChar + " " + maxCount);
    }
}
