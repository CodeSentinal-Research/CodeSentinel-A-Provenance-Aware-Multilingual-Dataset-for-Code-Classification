import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();
        String tasks = scanner.nextLine();
        int K = scanner.nextInt();
        scanner.close();

        Set<Character> uniqueTasks = new HashSet<>();
        for (char c : tasks.toCharArray()) {
            uniqueTasks.add(c);
        }

        int[] taskTimes = new int[uniqueTasks.size()];
        for (char c : uniqueTasks) {
            taskTimes[Character.toUpperCase(c) - 'A'] = 0;
        }

        PriorityQueue<Task> taskQueue = new PriorityQueue<>();
        for (char c : tasks.toCharArray()) {
            taskQueue.add(new Task(c, taskTimes[Character.toUpperCase(c) - 'A']));
        }

        while (!taskQueue.isEmpty()) {
            Task currentTask = taskQueue.poll();
            if (taskQueue.peek() != null && taskQueue.peek().time > currentTask.time + K) {
                taskQueue.peek().time = currentTask.time + K;
            } else {
                taskQueue.peek().time = currentTask.time + K + 1;
            }
            System.out.println(currentTask.time);
        }
    }

    static class Task implements Comparable<Task> {
        char task;
        int time;

        public Task(char task, int time) {
            this.task = task;
            this.time = time;
        }

        @Override
        public int compareTo(Task other) {
            return Integer.compare(this.time, other.time);
        }
    }
}
