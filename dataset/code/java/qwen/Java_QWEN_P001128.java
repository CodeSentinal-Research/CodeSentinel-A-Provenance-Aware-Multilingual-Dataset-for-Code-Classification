import java.util.*;
public class Main {
    static int[] parent;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        
        Map<String, Integer> emailToId = new HashMap<>();
        Map<Integer, String> idToName = new HashMap<>();
        Map<Integer, Set<String>> idToEmails = new HashMap<>();
        int idCounter = 0;
        
        for (int i = 0; i < n; i++) {
            String name = sc.next();
            int k = sc.nextInt();
            Set<String> emails = new HashSet<>();
            for (int j = 0; j < k; j++) {
                String email = sc.next();
                emails.add(email);
                if (emailToId.containsKey(email)) {
                    union(i, emailToId.get(email));
                } else {
                    emailToId.put(email, i);
                }
            }
            idToName.put(i, name);
            idToEmails.put(i, emails);
        }
        
        Map<Integer, Set<String>> merged = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int root = find(i);
            merged.computeIfAbsent(root, k -> new TreeSet<>()).addAll(idToEmails.get(i));
        }
        
        List<List<String>> res = new ArrayList<>();
        for (Map.Entry<Integer, Set<String>> entry : merged.entrySet()) {
            List<String> account = new ArrayList<>();
            account.add(idToName.get(entry.getKey()));
            account.addAll(entry.getValue());
            res.add(account);
        }
        
        for (List<String> acc : res) {
            for (String s : acc) System.out.print(s + " ");
            System.out.println();
        }
    }
    
    static int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    
    static void union(int i, int j) {
        parent[find(i)] = find(j);
    }
}
