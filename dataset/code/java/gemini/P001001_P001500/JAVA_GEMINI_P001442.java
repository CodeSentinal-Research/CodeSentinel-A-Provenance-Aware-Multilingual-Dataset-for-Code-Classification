import java.util.*;

public class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> map = new HashMap<>();

        for (String p : paths) {
            String[] parts = p.split(" ");
            String dirPath = parts[0];
            for (int i = 1; i < parts.length; i++) {
                int open = parts[i].indexOf('(');
                String fileName = parts[i].substring(0, open);
                String content = parts[i].substring(open + 1, parts[i].length() - 1);
                map.computeIfAbsent(content, k -> new ArrayList<>()).add(dirPath + "/" + fileName);
            }
        }

        List<List<String>> res = new ArrayList<>();
        for (List<String> list : map.values()) {
            if (list.size() > 1) res.add(list);
        }
        return res;
    }
}