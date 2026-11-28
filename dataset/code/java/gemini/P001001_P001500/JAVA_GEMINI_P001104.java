import java.util.*;

public class Solution {
    static class Node {
        public int val;
        public List<Node> neighbors;
        public Node(int _val) {
            val = _val;
            neighbors = new ArrayList<Node>();
        }
    }

    private Map<Node, Node> visited = new HashMap<>();

    public Node cloneGraph(Node node) {
        if (node == null) return null;
        if (visited.containsKey(node)) return visited.get(node);

        Node clone = new Node(node.val);
        visited.put(node, clone);
        for (Node nbr : node.neighbors) {
            clone.neighbors.add(cloneGraph(nbr));
        }
        return clone;
    }
}