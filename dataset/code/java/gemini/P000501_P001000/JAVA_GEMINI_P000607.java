import java.util.*;
public class Solution {
    static class Node {
        int k, v, f;
        Node(int k, int v, int f) { this.k = k; this.v = v; this.f = f; }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int cap = scanner.nextInt(), q = scanner.nextInt();
            Map<Integer, Node> keyMap = new HashMap<>();
            Map<Integer, LinkedHashSet<Integer>> freqMap = new HashMap<>();
            int minFreq = 0;
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("put")) {
                    int k = scanner.nextInt(), v = scanner.nextInt();
                    if (cap == 0) continue;
                    if (keyMap.containsKey(k)) {
                        Node node = keyMap.get(k);
                        node.v = v;
                        int f = node.f;
                        freqMap.get(f).remove(k);
                        if (freqMap.get(f).isEmpty() && f == minFreq) minFreq++;
                        node.f++;
                        freqMap.computeIfAbsent(node.f, x -> new LinkedHashSet<>()).add(k);
                    } else {
                        if (keyMap.size() >= cap) {
                            int evictK = freqMap.get(minFreq).iterator().next();
                            freqMap.get(minFreq).remove(evictK);
                            keyMap.remove(evictK);
                        }
                        Node node = new Node(k, v, 1);
                        keyMap.put(k, node);
                        freqMap.computeIfAbsent(1, x -> new LinkedHashSet<>()).add(k);
                        minFreq = 1;
                    }
                } else if (cmd.equals("get")) {
                    int k = scanner.nextInt();
                    if (keyMap.containsKey(k)) {
                        Node node = keyMap.get(k);
                        int f = node.f;
                        freqMap.get(f).remove(k);
                        if (freqMap.get(f).isEmpty() && f == minFreq) minFreq++;
                        node.f++;
                        freqMap.computeIfAbsent(node.f, x -> new LinkedHashSet<>()).add(k);
                        System.out.println(node.v);
                    } else {
                        System.out.println(-1);
                    }
                }
            }
        }
    }
}