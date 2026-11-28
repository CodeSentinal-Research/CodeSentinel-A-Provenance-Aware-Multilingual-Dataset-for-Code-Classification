import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        
        Map<Integer, Integer> freq = new HashMap<>();
        Map<Integer, Stack<Integer>> group = new HashMap<>();
        int maxFreq = 0;
        
        for(int i=0; i<q; i++) {
            String op = sc.next();
            if(op.equals("push")) {
                int val = sc.nextInt();
                int f = freq.getOrDefault(val, 0) + 1;
                freq.put(val, f);
                maxFreq = Math.max(maxFreq, f);
                group.computeIfAbsent(f, k -> new Stack<>()).push(val);
            } else if(op.equals("pop")) {
                int val = group.get(maxFreq).pop();
                freq.put(val, freq.get(val) - 1);
                if(group.get(maxFreq).isEmpty()) maxFreq--;
                System.out.println(val);
            }
        }
    }
}
