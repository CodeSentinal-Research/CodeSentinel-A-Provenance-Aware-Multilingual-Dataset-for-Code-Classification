import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] words = new String[n];
        for (int i = 0; i < n; i++) words[i] = sc.next();
        
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < 26; i++) adj.add(new ArrayList<>());
        int[] inDegree = new int[26];
        boolean[] exists = new boolean[26];
        
        for (int i = 0; i < n - 1; i++) {
            String w1 = words[i];
            String w2 = words[i + 1];
            int len = Math.min(w1.length(), w2.length());
            boolean found = false;
            for (int j = 0; j < len; j++) {
                if (w1.charAt(j) != w2.charAt(j)) {
                    int u = w1.charAt(j) - 'a';
                    int v = w2.charAt(j) - 'a';
                    adj.get(u).add(v);
                    inDegree[v]++;
                    found = true;
                    break;
                }
            }
            if (!found && w1.length() > w2.length()) {
                System.out.println("IMPOSSIBLE");
                return;
            }
        }
        
        for (String w : words) {
            for (char c : w.toCharArray()) exists[c - 'a'] = true;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < 26; i++) {
            if (exists[i] && inDegree[i] == 0) q.offer(i);
        }
        
        StringBuilder sb = new StringBuilder();
        while (!q.isEmpty()) {
            int u = q.poll();
            sb.append((char) (u + 'a'));
            for (int v : adj.get(u)) {
                inDegree[v]--;
                if (inDegree[v] == 0) q.offer(v);
            }
        }
        
        // Check if all existing chars are included
        for (int i = 0; i < 26; i++) {
            if (exists[i] && sb.indexOf(String.valueOf((char) (i + 'a'))) == -1) {
                System.out.println("IMPOSSIBLE");
                return;
            }
        }
        
        System.out.println(sb.toString());
    }
}
