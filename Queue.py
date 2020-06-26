"""
PROJECT 4 - QUEUES
Name: WELSHTOR
"""


class CircularQueue:
    """
    Circular Queue Class
    """

    # DO NOT MODIFY THESE METHODS
    def __init__(self, capacity=4):
        """
        DO NOT MODIFY.
        Initialize the queue with an initial capacity
        :param capacity: the initial capacity of the queue
        """
        self.capacity = capacity
        self.size = 0
        self.data = [None] * capacity
        self.head = 0
        self.tail = 0

    def __eq__(self, other):
        """
        DO NOT MODIFY.
        Defines equality for two queues
        :return: true if two queues are equal, false otherwise
        """
        if self.capacity != other.capacity:
            return False
        for i in range(self.capacity):
            if self.data[i] != other.data[i]:
                return False
        return self.head == other.head and self.tail == other.tail and self.size == other.size

    def __str__(self):
        """
        DO NOT MODIFY.
        String representation of the queue
        :return: the queue as a string
        """
        if self.is_empty():
            return "Empty queue"
        result = ""
        str_list = [str(self.data[(self.head + i) % self.capacity]) for i in range(self.size)]
        return "Queue: " + (", ").join(str_list)

    # -----------MODIFY BELOW--------------
    def __len__(self):
        """
        Length of Queue
        :return: Size of the queue
        """
        print("Len: ", self.size)
        return self.size

    def is_empty(self):
        """

        :return: True if empty or False Otherwise
        """
        if self.__len__() == 0:
            print("is empty: true")
            return True
        else:
            print("is empty: false")
            return False

    def head_element(self):
        """

        :return: The fist element of the queue
        """
        print("Head: ", self.data[self.head])
        return self.data[self.head]

    def tail_element(self):
        """

        :return: the last element of the queue
        """
        print("Tail: ", self.data[self.tail])
        return self.data[self.tail - 1]

    def enqueue(self, val):
        """

        :param val: element to be added to the back of the queue
        :return: None
        """
        # place value in last element of the queue

        self.data[self.tail] = val
        self.tail += 1
        self.size += 1
        self.tail %= self.capacity  # perform tail mod capacity to remain circular

        if self.size == self.capacity:
            self.grow()

    def dequeue(self):
        """
        Removes an element from the front of the queue
        :return: None
        """
        if self.is_empty():
            return None
        front_e_remove = self.data[self.head]
        self.data[self.head] = None

        self.size -= 1
        self.head += 1
        self.head %= self.capacity  # perform head mod capacity to remain circular

        if 0 < self.size <= self.capacity * (
                1 / 4) and self.capacity // 2 > 3:  # check that size is 1/4 of the capacity or less and that capacity // 2 isn't less than 4
            self.shrink()

        print("After Dequeue \n Size: ", self.size)
        print("Head: ", self.data[self.head])
        # print("Tail: ", self.data[self.tail])
        print("Capacity: ", self.capacity)

        return front_e_remove

    def tail_dequeue(self):
        """
        remove an element from teh back of the queue
        :return: None
        """
        if self.is_empty():
            return None

        last_e_remove = self.data[(self.head + self.size - 1) % self.capacity]
        # this adds the index of the head to the size of the list minus 1 because the tail is always at this position
        # then perform
        self.data[(self.head + self.size - 1) % self.capacity] = None  #
        self.tail = (self.head + self.size - 1) % self.capacity
        self.size -= 1

        if 0 < self.size <= self.capacity * (
                1 / 4) and self.capacity // 2 > 3:  # check that size is 1/4 of the capacity or less and that capacity // 2 isn't less than 4
            self.shrink()

        print("After Tail Dequeue \nSize: ", self.size)
        print("Head: ", self.data[self.head])
        print("Tail: ", self.data[self.tail])
        print("Capacity: ", self.capacity)

        return last_e_remove

    def grow(self):
        """
        Doubles the capacity of the queue immediately when capacity is reached
        :return: None
        """
        new_queue = CircularQueue(self.capacity * 2)
        for elem in range(0, self.size):
            new_queue.data[elem] = self.data[elem]

        self.data = new_queue.data
        self.head = 0
        self.capacity = new_queue.capacity
        self.tail = self.size

    def shrink(self):
        """
        Halves the Capacity of the queue immediately if the size is 1/4 or less of capacity
        :return: None
        """
        # if self.capacity >= 4:
        # old = self.data
        # self.data = [None] * (self.capacity//2)
        new_queue = CircularQueue(self.capacity // 2)
        head = self.head
        for elem in range(self.size):
            new_queue.data[elem] = self.data[(head + elem) % self.size]
            # self.data[elem] = old[head]
        #   head = (1+head) % self.size

        self.head = 0
        self.data = new_queue.data
        self.capacity = new_queue.capacity
        self.tail = self.size
        print("Shrink: Capacity: ", self.capacity)


def greatest_val(w, values):
    """

    :param w: size of the queue
    :param values: values in the elements of the queue
    :return: List of all greatest values at the end of the function
    """

    initial_queue = CircularQueue()
    list_greatest_v = []
    for elem in range(0, len(values)):
        initial_queue.enqueue(values[elem])  # place elements in an initial queue

        if initial_queue.__len__() == 1:
            pass

        if initial_queue.__len__() == w:
            if initial_queue.head_element() < initial_queue.tail_element():
                max = initial_queue.tail_element()
                list_greatest_v.append(max)
                initial_queue.dequeue()
            else:
                max = initial_queue.head_element()
                list_greatest_v.append(max)
                initial_queue.tail_dequeue()

    return list_greatest_v


"""
queue = CircularQueue()

queue.data = [None,None,None,1,2,None,None,None]
queue.capacity = 8
queue.head = queue.data[3]
queue.tail = queue.data[2]
queue.size = 8


assert queue.data == [None,None,None,1,2,None,None,None]
assert queue.size == 8
assert queue.capacity == 8
assert queue.head == 1
assert queue.tail == None

queue.size =  queue.capacity //2
queue.tail_dequeue()
queue.tail_dequeue()


print(queue.data)
#queue.shrink()
assert queue.data == [1,2,None,None]
assert queue.size == 2
assert queue.capacity == 4
assert queue.head == 0
assert queue.tail == 2
"""

values = [1, 2, 3, 4]
w = 2

arr = (greatest_val(w, values))

assert arr == [2, 3, 4]

w = 3
arr = (greatest_val(w, values))
assert arr == [3, 4]
