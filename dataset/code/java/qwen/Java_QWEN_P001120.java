import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, PriorityQueue<String>> graph = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            String from = sc.next();
            String to = sc.next();
            graph.computeIfAbsent(from, k -> new PriorityQueue<>()).offer(to);
        }
        
        List<String> itinerary = new ArrayList<>();
        dfs("JFK", graph, itinerary);
        Collections.reverse(itinerary);
        
        for (String s : itinerary) System.out.print(s + " ");
    }
    
    static void dfs(String airport, Map<String, PriorityQueue<String>> graph, List<String> itinerary) {
        PriorityQueue<String> dests = graph.get(airport);
        while (dests != null && !dests.isEmpty()) {
            dfs(dests.poll(), graph, itinerary);
        }
        itinerary.add(airport);
    }
}
