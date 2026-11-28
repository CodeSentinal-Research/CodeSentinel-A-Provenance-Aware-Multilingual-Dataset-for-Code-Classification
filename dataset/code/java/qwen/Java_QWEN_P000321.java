import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] words = new String[n];
        for(int i=0; i<n; i++) words[i] = sc.next();
        
        Set<String> row1 = new HashSet<>(Arrays.asList("qwertyuiop".split("")));
        Set<String> row2 = new HashSet<>(Arrays.asList("asdfghjkl".split("")));
        Set<String> row3 = new HashSet<>(Arrays.asList("zxcvbnm".split("")));
        
        for (String w : words) {
            String lower = w.toLowerCase();
            Set<String> targetRow = null;
            char first = lower.charAt(0);
            if ("qwertyuiop".indexOf(first) != -1) targetRow = row1;
            else if ("asdfghjkl".indexOf(first) != -1) targetRow = row2;
            else targetRow = row3;
            
            boolean valid = true;
            for (char ch : lower.toCharArray()) {
                if (!targetRow.contains(String.valueOf(ch))) {
                    valid = false; break;
                }
            }
            if (valid) System.out.print(w + " ");
        }
    }
}
