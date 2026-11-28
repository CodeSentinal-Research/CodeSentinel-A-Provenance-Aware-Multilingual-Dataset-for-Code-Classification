import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] list1 = new String[n];
        for(int i=0; i<n; i++) list1[i] = sc.next();
        
        int m = sc.nextInt();
        String[] list2 = new String[m];
        for(int i=0; i<m; i++) list2[i] = sc.next();
        
        Map<String, Integer> map = new HashMap<>();
        for(int i=0; i<n; i++) map.put(list1[i], i);
        
        int minSum = Integer.MAX_VALUE;
        List<String> res = new ArrayList<>();
        
        for(int i=0; i<m; i++) {
            if(map.containsKey(list2[i])) {
                int sum = i + map.get(list2[i]);
                if(sum < minSum) {
                    minSum = sum;
                    res.clear();
                    res.add(list2[i]);
                } else if(sum == minSum) {
                    res.add(list2[i]);
                }
            }
        }
        
        Collections.sort(res);
        for(String s : res) System.out.println(s);
    }
}
