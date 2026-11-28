import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String start = sc.next();
        String end = sc.next();
        int n = sc.nextInt();
        Set<String> bank = new HashSet<>();
        for(int i=0; i<n; i++) bank.add(sc.next());
        
        if(!bank.contains(end)) { System.out.println(-1); return; }
        
        Queue<String> queue = new LinkedList<>();
        queue.offer(start);
        bank.remove(start);
        int steps = 0;
        
        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int k=0; k<size; k++) {
                String curr = queue.poll();
                if(curr.equals(end)) { System.out.println(steps); return; }
                char[] chars = curr.toCharArray();
                for(int i=0; i<8; i++) {
                    char old = chars[i];
                    for(char c : new char[]{'A', 'C', 'G', 'T'}) {
                        chars[i] = c;
                        String next = new String(chars);
                        if(bank.contains(next)) {
                            bank.remove(next);
                            queue.offer(next);
                        }
                    }
                    chars[i] = old;
                }
            }
            steps++;
        }
        System.out.println(-1);
    }
}
