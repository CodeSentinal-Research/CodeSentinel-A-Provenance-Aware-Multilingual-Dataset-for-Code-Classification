import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        List<String> happy = new ArrayList<>();
        generateHappy(n, "", happy);
        
        if(k <= happy.size()) {
            System.out.println(happy.get(k-1));
        } else {
            System.out.println("");
        }
    }
    
    static void generateHappy(int n, String curr, List<String> happy) {
        if(curr.length() == n) {
            happy.add(curr);
            return;
        }
        for(char c : new char[]{'a', 'b', 'c'}) {
            if(curr.isEmpty() || curr.charAt(curr.length()-1) != c) {
                generateHappy(n, curr + c, happy);
            }
        }
    }
}
