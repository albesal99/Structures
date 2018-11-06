class Node:
    def __init__(self, item, priority):
        self.item = item
        self.priority = priority
        self.next = None


class PriorityQueue:
    def __init__(self):
        self.head = None
        self.prev = None
        self.num_items = 0

    def is_empty(self):
        return self.num_items == 0

    def enqueue(self, item, priority):
        """Will crash if too many items with the same priority are enqueued"""
        current = self.head
        new_node = Node(item, priority)
        if self.is_empty():
            self.head = self.prev = new_node
            self.num_items += 1
        elif priority > self.head.priority:
            new_node.next = self.head
            self.head = new_node
            self.num_items += 1
        elif priority == self.head.priority:
            self.head.next = new_node
            self.num_items += 1
        else:
            while current.next is not None and current.next.priority > priority:
                current = current.next
            new_node.next = current.next
            current.next = new_node
            self.num_items += 1

    def front(self):
        if self.is_empty():
            raise IndexError("Queue is empty")
        return self.head.item

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Cannot dequeue from an empty queue")
        item = self.head.item
        self.head = self.head.next
        self.num_items -= 1
        return item

    def size(self):
        return self.num_items

    def __repr__(self):
        return self.list_representation(self.head)

    def list_representation(self, head):
        current = head
        list_representation = "["
        count = self.num_items
        while count != 0:
            item = str(current.item)
            priority = str(current.priority)
            queue_tuple = "(" + item + ", " + priority + ")"
            list_representation += queue_tuple
            if count > 1:
                list_representation += ", "
            current = current.next
            count -= 1
        list_representation += "]"
        return list_representation
