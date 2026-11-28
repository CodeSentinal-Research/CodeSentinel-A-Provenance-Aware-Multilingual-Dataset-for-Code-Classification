import java.util.*;

public class Main {
    public static List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> res = new ArrayList<>();
        Set<String> dict = new HashSet<>(wordList);
        if (!dict.contains(endWord)) return res;
        Map<String, List<String>> map = new HashMap<>();
        Map<String, Integer> dist = new HashMap<>();
        dict.add(beginWord);
        dict.remove(endWord);
        bfs(endWord, beginWord, dict, map, dist);
        dfs(beginWord, endWord, map, new ArrayList<>(), res);
        return res;
    }

    private static void bfs(String start, String end, Set<String> dict, Map<String, List<String>> map, Map<String, Integer> dist) {
        Queue<String> queue = new LinkedList<>();
        queue.offer(start);
        dist.put(start, 0);
        while (!queue.isEmpty()) {
            String cur = queue.poll();
            char[] chars = cur.toCharArray();
            for (int i = 0; i < chars.length; i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == chars[i]) continue;
                    chars[i] = c;
                    String next = new String(chars);
                    if (dict.contains(next)) {
                        if (!dist.containsKey(next)) {
                            queue.offer(next);
                            dist.put(next, dist.get(cur) + 1);
                            map.put(next, new ArrayList<>());
                        }
                        if (dist.get(cur) + 1 == dist.get(next)) {
                            map.get(next).add(cur);
                        }
                    }
                }
                chars[i] = cur.charAt(i);
            }
        }
    }

    private static void dfs(String cur, String end, Map<String, List<String>> map, List<String> path, List<List<String>> res) {
        path.add(cur);
        if (cur.equals(end)) {
            res.add(new ArrayList<>(path));
        } else {
            for (String next : map.get(cur)) {
                dfs(next, end, map, path, res);
            }
        }
        path.remove(path.size() - 1);
    }
}
