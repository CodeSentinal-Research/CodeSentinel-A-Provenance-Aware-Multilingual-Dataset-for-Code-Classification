import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        List<List<Integer>> routes = new ArrayList<>();
        Set<Integer> stopsSet = new HashSet<>();
        for(int i=0; i<r; i++) {
            int k = sc.nextInt();
            List<Integer> route = new ArrayList<>();
            for(int j=0; j<k; j++) {
                int stop = sc.nextInt();
                route.add(stop);
                stopsSet.add(stop);
            }
            routes.add(route);
        }
        int source = sc.nextInt();
        int target = sc.nextInt();
        if(source == target) { System.out.println(0); return; }
        
        Map<Integer, List<Integer>> stopToRoutes = new HashMap<>();
        for(int i=0; i<r; i++) {
            for(int stop : routes.get(i)) {
                stopToRoutes.computeIfAbsent(stop, k -> new ArrayList<>()).add(i);
            }
        }
        
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visitedStops = new HashSet<>();
        Set<Integer> visitedRoutes = new HashSet<>();
        queue.offer(source);
        visitedStops.add(source);
        int buses = 0;
        
        while(!queue.isEmpty()) {
            int size = queue.size();
            buses++;
            for(int k=0; k<size; k++) {
                int stop = queue.poll();
                for(int routeIdx : stopToRoutes.getOrDefault(stop, new ArrayList<>())) {
                    if(visitedRoutes.contains(routeIdx)) continue;
                    visitedRoutes.add(routeIdx);
                    for(int nextStop : routes.get(routeIdx)) {
                        if(nextStop == target) { System.out.println(buses); return; }
                        if(!visitedStops.contains(nextStop)) {
                            visitedStops.add(nextStop);
                            queue.offer(nextStop);
                        }
                    }
                }
            }
        }
        System.out.println(-1);
    }
}
