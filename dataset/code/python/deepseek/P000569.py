def reverse_queue(n, queue):
    queue_list = list(queue)

    queue_list.reverse()

    reversed_queue = [queue_list[i] for i in range(len(queue_list))]

    return reversed_queue


n = int(input())
queue = list(map(int, input().split()))

print(reverse_queue(n, queue))