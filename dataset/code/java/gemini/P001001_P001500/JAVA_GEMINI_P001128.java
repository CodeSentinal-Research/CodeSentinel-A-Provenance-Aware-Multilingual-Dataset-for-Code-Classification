import java.util.*;

public class Solution {
    private String find(Map<String, String> parent, String s) {
        if (parent.get(s).equals(s)) return s;
        parent.put(s, find(parent, parent.get(s)));
        return parent.get(s);
    }

    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, String> parent = new HashMap<>();
        Map<String, String> emailToName = new HashMap<>();

        for (List<String> acc : accounts) {
            String name = acc.get(0);
            String firstEmail = acc.get(1);
            for (int i = 1; i < acc.size(); i++) {
                String email = acc.get(i);
                parent.putIfAbsent(email, email);
                emailToName.put(email, name);
                String r1 = find(parent, firstEmail), r2 = find(parent, email);
                if (!r1.equals(r2)) parent.put(r1, r2);
            }
        }

        Map<String, List<String>> unions = new HashMap<>();
        for (String email : parent.keySet()) {
            String root = find(parent, email);
            unions.computeIfAbsent(root, k -> new ArrayList<>()).add(email);
        }

        List<List<String>> res = new ArrayList<>();
        for (String root : unions.keySet()) {
            List<String> emails = unions.get(root);
            Collections.sort(emails);
            emails.add(0, emailToName.get(root));
            res.add(emails);
        }
        return res;
    }
}