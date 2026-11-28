import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String beginWord = scanner.next();
            String endWord = scanner.next();
            int n = scanner.nextInt();
            Set<String> wordList = new HashSet<>();
            for (int i = 0; i < n; i++) wordList.add(scanner.next());
            if (!wordList.contains(endWord)) return;
            Map<String, List<List<String>>> layer = new HashMap<>();
            List<String> initPath = new ArrayList<>();
            initPath.add(beginWord);
            layer.put(beginWord, new ArrayList<>(Collections.singletonList(initPath)));
            while (!layer.isEmpty()) {
                if (layer.containsKey(endWord)) {
                    for (List<String> path : layer.get(endWord)) {
                        StringBuilder sb = new StringBuilder();
                        for (int j = 0; j < path.size(); j++) {
                            sb.append(path.get(j)).append(j + 1 == path.size() ? "" : " ");
                        }
                        System.out.println(sb.toString());
                    }
                    return;
                }
                Map<String, List<List<String>>> newLayer = new HashMap<>();
                for (Map.Entry<String, List<List<String>>> entry : layer.entrySet()) {
                    String word = entry.getKey();
                    char[] chs = word.toCharArray();
                    for (int i = 0; i < chs.length; i++) {
                        char orig = chs[i];
                        for (char c = 'a'; c <= 'z'; c++) {
                            chs[i] = c;
                            String nxt = new String(chs);
                            if (wordList.contains(nxt)) {
                                newLayer.computeIfAbsent(nxt, x -> new ArrayList<>());
                                for (List<String> p : entry.getValue()) {
                                    List<String> newP = new ArrayList<>(p);
                                    newP.add(nxt);
                                    newLayer.get(nxt).add(newP);
                                }
                            }
                        }
                        chs[i] = orig;
                    }
                }
                for (String w : newLayer.keySet()) wordList.remove(w);
                layer = newLayer;
            }
        }
    }
}