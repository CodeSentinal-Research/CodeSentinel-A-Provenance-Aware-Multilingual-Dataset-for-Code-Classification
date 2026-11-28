from flight import Flight

class Heap:
    
    def __init__(self, comparison_function, init_array):
        # Write your code here
        self.comparison_function = comparison_function
        self.heap = []
        # Initialise the heap using bottom up approach
        if len(init_array)>0 :
            self.heap = [None for i in range(len(init_array))]
            self.height = self.find_height(len(init_array))
            # The initialise heap function will initialise the heap based on comparison function using botttom up approach
            self.initialise_heap(init_array)

    def insert(self, value):
        
        # Write your code here
        self.heap.append(value)
        # Append the value in the heap
        child_index = self.size()-1
        # Get the index where it is added 
        parent_index = (child_index-1)//2
        # Calculate its parent's index
        # Bubble up it till it has lower weight then its parent
        while parent_index>=0 and self.comparison_function(self.heap[child_index],self.heap[parent_index]):
            self.heap[child_index],self.heap[parent_index] = self.heap[parent_index],self.heap[child_index]
            child_index = parent_index
            parent_index = (child_index-1)//2

    def extract(self):
        # Write your code here
        right_most_index = self.size()-1
        top_value = None
        # If heap is not empty then delete its top element by replacing it with right most child and delete the right most child
        if right_most_index>=0:
            top_value = self.heap[0]
            self.heap[0],self.heap[right_most_index] = self.heap[right_most_index],self.heap[0]
            self.heap.pop()
            # Rebalance the heap property means bubble down that element
            self.rebalance(0)
        return top_value
    
    def top(self):
        # Write your code here
        # Function returning top element of heap if it is non empty
        return self.heap[0] if self.size()>0 else None
    
    # You can add more functions if you want to

    def size(self):
        # function for size calculation of heap
        return len(self.heap)
    
    def find_height(self,size):
        # Function for height calcultion of heap
        height = 0
        while size!=0:
            height = height+1
            size = size//2
        return height-1
    
    def initialise_heap(self,init_array):
        # This function will initialise the heap using bottom up heap construction 
        height = self.height
        # Calulate the height and assign values to the leaf nodes
        for i in range(pow(2,height)-1,self.size()):
            self.heap[i] = init_array[i]
        height = height-1
        while height>=0:
            for i in range(pow(2,height)-1,pow(2,height+1)-1):
                # now plug element height wise and then bubble down them if possible
                self.heap[i] = init_array[i]
                self.rebalance(i)
            height = height-1

    def rebalance(self,index):
        # Rebalance the heap means bubble down the element if possible  
        if self.size()>2*index + 1:
                parent_index = index
                if self.size()>2*index+2:
                    child_index = 2*index + 1 if self.comparison_function(self.heap[2*index + 1],self.heap[2*index + 2]) else 2*index + 2
                else:
                    child_index = 2*index + 1
                while child_index<self.size() and self.comparison_function(self.heap[child_index],self.heap[parent_index]):
                    self.heap[child_index],self.heap[parent_index] = self.heap[parent_index],self.heap[child_index]
                    parent_index = child_index
                    if self.size()> 2*parent_index + 2:
                        child_index = (2*parent_index+1) if self.comparison_function(self.heap[2*parent_index + 1],self.heap[2*parent_index + 2]) else (2*parent_index +2)
                    else:
                        child_index = 2*parent_index+1


class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None

class Deque:
    def __init__(self):
        self.head = None  # Front of the deque
        self.tail = None  # Rear of the deque
        self.size = 0     # Number of elements in the deque

    def is_empty(self):
        return self.size == 0

    def add_rear(self, value):
        new_node = Node(value)
        if self.is_empty():
            # If empty, both head and tail point to new node
            self.head = self.tail = new_node
        else:
            # Link the new node at the rear
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        self.size += 1

    def remove_front(self):
        if self.is_empty():
            raise IndexError("remove_front from empty deque")
        
        value = self.head.value
        self.head = self.head.next
        
        if self.head is None:
            # Deque is now empty
            self.tail = None
        else:
            # Remove reference to old head
            self.head.prev = None
        self.size -= 1
        return value

    def __len__(self):
        return self.size


class Planner:
    def __init__(self, flights):
        self.flights = flights
        self.no_of_cities = 0
        for flight in flights:
            if self.no_of_cities<flight.start_city:
                self.no_of_cities = flight.start_city
            if self.no_of_cities<flight.end_city:
                self.no_of_cities = flight.end_city
        self.no_of_cities += 1
        # Create adjacency lists for quick flight lookup from each city
        self.adjacency_list = [[] for _ in range(self.no_of_cities)]
        for flight in flights:
            self.adjacency_list[flight.start_city].append(flight)
        for i in range(self.no_of_cities):
            self.adjacency_list[i].sort(key=lambda x: x.arrival_time)
    
    def is_flights_are_connected_and_have_20mins_time_difference(self, current_flight, adjacent_flight):
        return (current_flight.end_city == adjacent_flight.start_city and 
                adjacent_flight.departure_time >= current_flight.arrival_time + 20)

    def least_flights_ealiest_route(self, start_city, end_city, t1, t2):
        if start_city == end_city:
            return []
        queue_of_path = Deque()
        queue_of_path.add_rear((start_city, t1, [], 0))
        list_of_times_storing_best_arrival_time = [[float('inf') for _ in range(self.no_of_cities)] for _ in range(self.no_of_cities)]
        list_of_times_storing_best_arrival_time[start_city][0] = t1
        
        while queue_of_path.size > 0:
            curr_city, curr_time, path, num_flights = queue_of_path.remove_front()
            
            if curr_time > list_of_times_storing_best_arrival_time[curr_city][num_flights]:
                continue
                
            for flight in self.adjacency_list[curr_city]:
                if flight.arrival_time > t2:
                    continue
                    
                if not path:
                    if flight.departure_time < t1:
                        continue
                elif not self.is_flights_are_connected_and_have_20mins_time_difference(path[-1], flight):
                    continue
                    
                new_path = path + [flight]
                new_flights = num_flights + 1
                
                if flight.end_city == end_city:
                    return new_path
                if flight.arrival_time < list_of_times_storing_best_arrival_time[flight.end_city][new_flights]:
                    list_of_times_storing_best_arrival_time[flight.end_city][new_flights] = flight.arrival_time
                    queue_of_path.add_rear((flight.end_city, flight.arrival_time, 
                                new_path, new_flights))
        
        return []

    def cheapest_route(self, start_city, end_city, t1, t2):
        if start_city == end_city:
            return []

        def cost_comparison(a, b):
            return a[0] < b[0]

        heap_of_total_cost = Heap(cost_comparison, [])

        num_flights = self.no_of_cities
        till_now_best_cost_achieved = [[float('inf')] * num_flights for _ in range(self.no_of_cities)]
        till_now_best_cost_achieved[start_city][0] = 0

        heap_of_total_cost.insert((0, start_city, t1, []))

        while heap_of_total_cost.size() > 0:
            cost, curr_city, curr_time, path = heap_of_total_cost.extract()
            
            if curr_city == end_city:
                return path
            
            num_flights_to_curr = len(path)
            if cost > till_now_best_cost_achieved[curr_city][num_flights_to_curr]:
                continue

            for flight in self.adjacency_list[curr_city]:
                if flight.arrival_time > t2:
                    continue

                if not path:
                    if flight.departure_time < t1:
                        continue
                elif not self.is_flights_are_connected_and_have_20mins_time_difference(path[-1], flight):
                    continue

                new_cost = cost + flight.fare
                new_state = (flight.end_city, num_flights_to_curr + 1)

                if new_cost < till_now_best_cost_achieved[new_state[0]][new_state[1]]:
                    till_now_best_cost_achieved[new_state[0]][new_state[1]] = new_cost
                    new_path = path + [flight]
                    heap_of_total_cost.insert((new_cost, flight.end_city, 
                              flight.arrival_time, new_path))

        return []

    def least_flights_cheapest_route(self, start_city, end_city, t1, t2):
        if start_city == end_city:
            return []

        queue_of_path = Deque()
        queue_of_path.add_rear((start_city, t1, [], 0))

        num_flights = self.no_of_cities
        till_now_best_cost_achieved = [[float('inf')] * num_flights for _ in range(self.no_of_cities)]
        till_now_best_cost_achieved[start_city][0] = 0

        def cost_comparison(a, b):
            return a[0] < b[0]

        heap_of_total_cost = Heap(cost_comparison, [])

        while queue_of_path.size > 0:
            level_size = len(queue_of_path)

            for _ in range(level_size):
                curr_city, curr_time, path, num_flights_to_curr = queue_of_path.remove_front()

                for flight in self.adjacency_list[curr_city]:
                    if flight.arrival_time > t2:
                        continue

                    if not path:
                        if flight.departure_time < t1:
                            continue
                    elif not self.is_flights_are_connected_and_have_20mins_time_difference(path[-1], flight):
                        continue

                    new_path = path + [flight]
                    total_cost = sum(f.fare for f in new_path)

                    if flight.end_city == end_city:
                        heap_of_total_cost.insert((total_cost, flight.end_city, 
                                  flight.arrival_time, new_path))
                        continue

                    new_state = (flight.end_city, num_flights_to_curr + 1)
                    if total_cost < till_now_best_cost_achieved[new_state[0]][new_state[1]]:
                        till_now_best_cost_achieved[new_state[0]][new_state[1]] = total_cost
                        queue_of_path.add_rear((flight.end_city, flight.arrival_time, 
                                    new_path, num_flights_to_curr + 1))

            if heap_of_total_cost.size() > 0:
                return heap_of_total_cost.extract()[3]

        return []