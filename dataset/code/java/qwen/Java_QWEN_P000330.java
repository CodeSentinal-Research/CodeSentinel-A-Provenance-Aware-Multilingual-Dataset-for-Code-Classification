import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt();
        String[] dict = new String[n];
        for(int i=0; i<n; i++) dict[i] = sc.next();
        
        boolean[] bold = new boolean[s.length()];
        for (String word : dict) {
            int idx = s.indexOf(word);
            while (idx != -1) {
                for (int i = idx; i < idx + word.length(); i++) bold[i] = true;
                idx = s.indexOf(word, idx + 1);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (bold[i] && (i == 0 || !bold[i-1])) sb.append("<b>");
            sb.append(s.charAt(i));
            if (bold[i] && (i == s.length() - 1 || !bold[i+1])) sb.append("</b>");
        }
        System.out.println(sb.toString());
    }
}
