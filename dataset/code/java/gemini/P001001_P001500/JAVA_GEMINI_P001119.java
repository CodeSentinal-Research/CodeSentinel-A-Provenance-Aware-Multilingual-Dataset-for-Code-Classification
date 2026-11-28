import java.util.*;

public class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, Map<String, Double>> graph = new HashMap<>();
        for (int i = 0; i < equations.size(); i++) {
            String a = equations.get(i).get(0), b = equations.get(i).get(1);
            double val = values[i];
            graph.computeIfAbsent(a, k -> new HashMap<>()).put(b, val);
            graph.computeIfAbsent(b, k -> new HashMap<>()).put(a, 1.0 / val);
        }

        double[] res = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            String src = queries.get(i).get(0), dst = queries.get(i).get(1);
            if (!graph.containsKey(src) || !graph.containsKey(dst)) {
                res[i] = -1.0;
            } else if (src.equals(dst)) {
                res[i] = 1.0;
            } else {
                Queue<Object[]> q = new LinkedList<>();
                q.offer(new Object[]{src, 1.0});
                Set<String> visited = new HashSet<>();
                visited.add(src);
                double ans = -1.0;

                while (!q.isEmpty()) {
                    Object[] cur = q.poll();
                    String node = (String) cur[0];
                    double prod = (Double) cur[1];
                    if (node.equals(dst)) { ans = prod; break; }
                    for (Map.Entry<String, Double> entry : graph.get(node).entrySet()) {
                        if (visited.add(entry.getKey())) {
                            q.offer(new Object[]{entry.getKey(), prod * entry.getValue()});
                        }
                    }
                }
                res[i] = ans;
            }
        }
        return res;
    }
}