import java.util.*;
public class Main {
    static String num;
    static int k;
    static String maxNum;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        num = sc.next();
        k = sc.nextInt();
        maxNum = num;
        
        backtrack(num.toCharArray(), 0, k);
        System.out.println(maxNum);
    }
    
    static void backtrack(char[] chars, int idx, int swapsLeft) {
        if(swapsLeft == 0 || idx == chars.length) {
            String curr = new String(chars);
            if(curr.compareTo(maxNum) > 0) maxNum = curr;
            return;
        }
        
        // Find max digit from idx to end
        char maxDigit = chars[idx];
        for(int i=idx+1; i<chars.length; i++) {
            if(chars[i] > maxDigit) maxDigit = chars[i];
        }
        
        if(maxDigit != chars[idx]) {
            for(int i=idx+1; i<chars.length; i++) {
                if(chars[i] == maxDigit) {
                    swap(chars, idx, i);
                    backtrack(chars, idx+1, swapsLeft-1);
                    swap(chars, idx, i);
                }
            }
        } else {
            backtrack(chars, idx+1, swapsLeft);
        }
    }
    
    static void swap(char[] chars, int i, int j) {
        char t = chars[i]; chars[i] = chars[j]; chars[j] = t;
    }
}
