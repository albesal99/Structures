public class linkedlist {
    Node head;
    Node last;
    int numItems = 0;
    static class Node {
        int item;
        Node next;
        Node(int i, Node n) {item = i; next = n;}

        public int getItem() {
            return item;
        }

        public void setItem(int newItem) {
            item = newItem;
        }

        public Node getNext() {
            return next;
        }

        public void setNext(Node newNext) {
            next = newNext;
        }
    }

    public int __getitem__(int index) {
        if (index < numItems) {
            Node cursor = head.getNext();
            for (int i = 0; i < index; i++) {
                cursor = cursor.getNext();
            }
            return cursor.getItem();
        }
        throw new java.lang.IndexOutOfBoundsException("Linked List index out of range");
    }

    public void __setitem__(int index, int val) {
        if (index < numItems) {
            Node cursor = head.getNext();
            for (int i = 0; i < index; i++) {
                cursor = cursor.getNext();
            }
            cursor.setItem(val);
        }
        throw new java.lang.IndexOutOfBoundsException("Linked List assignment out of range");
    }

    public void insert(int index, int item) {
        Node cursor = head;
        if (index < numItems) {
            for (int j = 0; j < index; j++) {
                cursor = cursor.getNext();
            }
            Node node = new Node(item, cursor.next);
            cursor.setNext(node);
            numItems++;
        }
        else{
            append(head.getItem());
        }
    }

    public linkedlist __add__(linkedlist other) {
        linkedlist result = new linkedlist();

        Node cursor = head.getNext();
        while (cursor != null) {
            result.append(cursor.item);
            cursor = cursor.getNext();
        }
        cursor = other.head.getNext();

        while (cursor != null) {
            result.append(cursor.item);
            cursor = cursor.next;
        }
        return result;
    }

    public boolean __contains__(int item) {
        Node cursor = head.getNext();
        while (cursor != null) {
            if (cursor.item == item) {
                return true;
            }
            cursor = cursor.getNext();
        }
        return false;
    }

    public void __delitem__(int index) {
        Node cursor = head;
        int i = 0;
        while (cursor.getNext() != null) {
            if (i == index) {
                cursor.setNext(cursor.next.next);
                numItems--;
                if (cursor.getNext() == null) {
                    last = cursor;
                }
                return;
            }
            else {
                cursor = cursor.getNext();
                i++;
            }
        }
    }

    public int __len__() {
        return numItems;
    }

    public void append(int item) {
        Node node = new Node(item,null);
        last.setNext(node);
        last = node;
        numItems++;
    }

    public String __repr__(int item) {
        return Integer.toString(item);
    }

    public static void main(String[] args) {
        linkedlist llist = new linkedlist();
        for (int i = 0; i < 100; i++) {
            llist.append(i);
        }
        System.out.println(llist.head);
    }
}
