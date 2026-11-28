import java.util.*;

public class Main {
    class Node {
        int key;
        int value;
        int freq;
        int time;
        public Node(int key, int value) {
            this.key = key;
            this.value = value;
            freq = 1;
            time = counter++;
        }
    }

    int capacity;
    HashMap<Integer, Node> nodeMap = new HashMap<>();
    HashMap<Integer, LinkedHashSet<Node>> freqMap = new HashMap<>();
    int min;
    int counter = 0;

    public Main(int capacity) {
        this.capacity = capacity;
        freqMap.put(1, new LinkedHashSet<>());
    }

    public int get(int key) {
        if (!nodeMap.containsKey(key))
            return -1;
        Node node = nodeMap.get(key);
        freqMap.get(node.freq).remove(node);
        if (min == node.freq && freqMap.get(node.freq).isEmpty())
            min++;
        node.freq++;
        if (!freqMap.containsKey(node.freq))
            freqMap.put(node.freq, new LinkedHashSet<>());
        freqMap.get(node.freq).add(node);
        return node.value;
    }

    public void put(int key, int value) {
        if (capacity <= 0)
            return;
        if (nodeMap.containsKey(key)) {
            Node node = nodeMap.get(key);
            freqMap.get(node.freq).remove(node);
            if (min == node.freq && freqMap.get(node.freq).isEmpty())
                min++;
            node.value = value;
            node.freq = 1;
            node.time = counter++;
            freqMap.get(1).add(node);
        } else {
            if (nodeMap.size() == capacity) {
                Node deadNode = freqMap.get(min).iterator().next();
                freqMap.get(min).remove(deadNode);
                nodeMap.remove(deadNode.key);
            }
            Node newNode = new Node(key, value);
            nodeMap.put(key, newNode);
            freqMap.get(1).add(newNode);
            min = 1;
        }
    }
}
