import java.util.*;
public class Main {
    static Set<String> row1 = new HashSet<>(Arrays.asList("qwertyuiop".split("")));
    static Set<String> row2 = new HashSet<>(Arrays.asList("asdfghjkl".split("")));
    static Set<String> row3 = new HashSet<>(Arrays.asList("zxcvbnm".split("")));
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String> res = new ArrayList<>();
        
        for(int i=0; i<n; i++) {
            String word = sc.next();
            if(canType(word)) res.add(word);
        }
        
        Collections.sort(res);
        for(String w : res) System.out.println(w);
    }
    
    static boolean canType(String word) {
        String lower = word.toLowerCase();
        char first = lower.charAt(0);
        Set<String> targetRow = null;
        if(row1.contains(String.valueOf(first))) targetRow = row1;
        else if(row2.contains(String.valueOf(first))) targetRow = row2;
        else targetRow = row3;
        
        for(char c : lower.toCharArray()) {
            if(!targetRow.contains(String.valueOf(c))) return false;
        }
        return true;
    }
}
