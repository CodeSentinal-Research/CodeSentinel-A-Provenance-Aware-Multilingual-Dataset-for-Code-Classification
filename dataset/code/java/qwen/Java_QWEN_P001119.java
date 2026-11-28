import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int e = sc.nextInt();
        Map<String, Map<String, Double>> graph = new HashMap<>();
        
        for (int i = 0; i < e; i++) {
            String u = sc.next();
            String v = sc.next();
            double w = sc.nextDouble();
            graph.computeIfAbsent(u, k -> new HashMap<>()).put(v, w);
            graph.computeIfAbsent(v, k -> new HashMap<>()).put(u, 1.0 / w);
        }
        
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            String start = sc.next();
            String end = sc.next();
            if (!graph.containsKey(start) || !graph.containsKey(end)) {
                System.out.println("-1.0");
            } else if (start.equals(end)) {
                System.out.println("1.0");
            } else {
                System.out.println(bfs(graph, start, end));
            }
        }
    }
    
    static double bfs(Map<String, Map<String, Double>> graph, String start, String end) {
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(start, 1.0));
        Set<String> visited = new HashSet<>();
        visited.add(start);
        
        while (!q.isEmpty()) {
            Pair curr = q.poll();
            if (curr.node.equals(end)) return curr.weight;
            
            for (Map.Entry<String, Double> entry : graph.get(curr.node).entrySet()) {
                if (!visited.contains(entry.getKey())) {
                    visited.add(entry.getKey());
                    q.offer(new Pair(entry.getKey(), curr.weight * entry.getValue()));
                }
            }
        }
        return -1.0;
    }
}
class Pair {
    String node;
    double weight;
    Pair(String n, double w) {
        node = n;
        weight = w;
    }
}
