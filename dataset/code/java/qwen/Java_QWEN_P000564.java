import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String begin = sc.next();
        String end = sc.next();
        int n = sc.nextInt();
        Set<String> dict = new HashSet<>();
        for(int i=0; i<n; i++) dict.add(sc.next());
        
        List<List<String>> res = new ArrayList<>();
        if(!dict.contains(end)) {
             System.out.println("[]"); return;
        }
        
        Map<String, List<String>> neighbors = new HashMap<>();
        Set<String> visited = new HashSet<>();
        visited.add(begin);
        Queue<String> queue = new LinkedList<>();
        queue.offer(begin);
        boolean found = false;
        
        while(!queue.isEmpty() && !found) {
            Set<String> levelVisited = new HashSet<>();
            int size = queue.size();
            for(int k=0; k<size; k++) {
                String curr = queue.poll();
                char[] chars = curr.toCharArray();
                for(int i=0; i<chars.length; i++) {
                    char old = chars[i];
                    for(char c='a'; c<='z'; c++) {
                        chars[i] = c;
                        String next = new String(chars);
                        if(next.equals(end)) found = true;
                        if(dict.contains(next) && !visited.contains(next)) {
                            levelVisited.add(next);
                            neighbors.computeIfAbsent(curr, x -> new ArrayList<>()).add(next);
                            queue.offer(next);
                        }
                    }
                    chars[i] = old;
                }
            }
            visited.addAll(levelVisited);
        }
        
        if(!found) { System.out.println("[]"); return; }
        
        List<String> path = new ArrayList<>();
        path.add(begin);
        dfs(begin, end, neighbors, path, res);
        System.out.println(res);
    }
    static void dfs(String curr, String end, Map<String, List<String>> neighbors, List<String> path, List<List<String>> res) {
        if(curr.equals(end)) {
            res.add(new ArrayList<>(path));
            return;
        }
        if(neighbors.containsKey(curr)) {
            for(String next : neighbors.get(curr)) {
                path.add(next);
                dfs(next, end, neighbors, path, res);
                path.remove(path.size() - 1);
            }
        }
    }
}
