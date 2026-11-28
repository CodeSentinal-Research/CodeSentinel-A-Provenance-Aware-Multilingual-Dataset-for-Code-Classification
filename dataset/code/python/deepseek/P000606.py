Here is the Python code for the LRU cache:

from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        else:
            self.cache.move_to_end(key)
            return self.cache[key]

    def put(self, key: int, value: int) -> None:
        self.cache[key] = value
        self.cache.move_to_end(key)
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)

def process_queries(capacity: int, q: int, queries: list) -> list:
    cache = LRUCache(capacity)
    result = []
    for _ in range(q):
        query = queries[_]
        if 'put' in query:
            key, value = map(int, query.split(' ')[1:])
            cache.put(key, value)
        else:
            key = int(query.split(' ')[1])
            result.append(cache.get(key))
    return result

The main function is used to handle the user input and call the `process_queries` function:

if __name__ == "__main__":
    capacity, q = map(int, input().split(' '))
    queries = [input() for _ in range(q)]
    result = process_queries(capacity, q, queries)
    print(' '.join(map(str, result)))

You can test this code with the following command:

$ python filename.py
$ capacity 3
$ put 1 1
$ put 2 2
$ put 3 3
$ get 1
$ get 2
$ get 3

Please replace "filename.py" with the actual name of your python file. This code will print the result of every get() operation.