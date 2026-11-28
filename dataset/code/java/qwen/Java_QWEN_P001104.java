import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) adj.add(new ArrayList<>());
        
        for (int i = 1; i <= n; i++) {
            String line = sc.nextLine().trim(); // consume newline
            if (line.isEmpty()) line = sc.nextLine().trim();
            String[] parts = line.split(" ");
            int k = Integer.parseInt(parts[0]);
            for (int j = 1; j <= k; j++) {
                adj.get(i).add(Integer.parseInt(parts[j]));
            }
        }
        
        Map<Integer, Node> map = new HashMap<>();
        for (int i = 1; i <= n; i++) map.put(i, new Node(i));
        
        for (int u = 1; u <= n; u++) {
            for (int v : adj.get(u)) {
                map.get(u).neighbors.add(map.get(v));
            }
        }
        
        Node clone = cloneGraph(map.get(1));
        printGraph(clone);
    }
    
    static Node cloneGraph(Node node) {
        if (node == null) return null;
        Map<Node, Node> map = new HashMap<>();
        Queue<Node> q = new LinkedList<>();
        q.offer(node);
        map.put(node, new Node(node.val));
        
        while (!q.isEmpty()) {
            Node curr = q.poll();
            for (Node neighbor : curr.neighbors) {
                if (!map.containsKey(neighbor)) {
                    map.put(neighbor, new Node(neighbor.val));
                    q.offer(neighbor);
                }
                map.get(curr).neighbors.add(map.get(neighbor));
            }
        }
        return map.get(node);
    }
    
    static void printGraph(Node node) {
        Set<Integer> visited = new HashSet<>();
        Queue<Node> q = new LinkedList<>();
        q.offer(node);
        visited.add(node.val);
        
        while (!q.isEmpty()) {
            Node curr = q.poll();
            System.out.print(curr.val + ": [");
            for (int i = 0; i < curr.neighbors.size(); i++) {
                System.out.print(curr.neighbors.get(i).val);
                if (i < curr.neighbors.size() - 1) System.out.print(", ");
            }
            System.out.println("]");
            
            for (Node neighbor : curr.neighbors) {
                if (!visited.contains(neighbor.val)) {
                    visited.add(neighbor.val);
                    q.offer(neighbor);
                }
            }
        }
    }
}
class Node {
    int val;
    List<Node> neighbors;
    Node(int val) {
        this.val = val;
        this.neighbors = new ArrayList<>();
    }
}
