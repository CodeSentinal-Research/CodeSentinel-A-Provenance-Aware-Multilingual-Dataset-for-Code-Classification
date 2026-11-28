import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        
        Map<String, Set<String>> adj = new HashMap<>();
        
        int p = sc.nextInt();
        for(int i=0; i<p; i++) {
            String a = sc.next();
            String b = sc.next();
            adj.computeIfAbsent(a, k -> new HashSet<>()).add(b);
            adj.computeIfAbsent(b, k -> new HashSet<>()).add(a);
        }
        
        String[] words1 = s1.split(" ");
        String[] words2 = s2.split(" ");
        
        if(words1.length != words2.length) {
            System.out.println("NO");
            return;
        }
        
        for(int i=0; i<words1.length; i++) {
            if(!canReach(words1[i], words2[i], adj)) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
    
    static boolean canReach(String start, String end, Map<String, Set<String>> adj) {
        if(start.equals(end)) return true;
        Queue<String> q = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        q.offer(start);
        visited.add(start);
        
        while(!q.isEmpty()) {
            String curr = q.poll();
            if(curr.equals(end)) return true;
            if(adj.containsKey(curr)) {
                for(String next : adj.get(curr)) {
                    if(!visited.contains(next)) {
                        visited.add(next);
                        q.offer(next);
                    }
                }
            }
        }
        return false;
    }
}
