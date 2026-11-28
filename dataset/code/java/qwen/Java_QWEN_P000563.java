import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String begin = sc.next();
        String end = sc.next();
        int n = sc.nextInt();
        Set<String> dict = new HashSet<>();
        for(int i=0; i<n; i++) dict.add(sc.next());
        
        if(!dict.contains(end)) { System.out.println(0); return; }
        
        Queue<String> queue = new LinkedList<>();
        queue.offer(begin);
        dict.remove(begin);
        int steps = 1;
        
        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int k=0; k<size; k++) {
                String curr = queue.poll();
                char[] chars = curr.toCharArray();
                for(int i=0; i<chars.length; i++) {
                    char old = chars[i];
                    for(char c='a'; c<='z'; c++) {
                        chars[i] = c;
                        String next = new String(chars);
                        if(next.equals(end)) { System.out.println(steps + 1); return; }
                        if(dict.contains(next)) {
                            dict.remove(next);
                            queue.offer(next);
                        }
                    }
                    chars[i] = old;
                }
            }
            steps++;
        }
        System.out.println(0);
    }
}
