package collection;

public class LinkedQueue<E> implements Queue<E> {

    private Node<E> first;

    private Node<E> last;

    private int size;

    @Override
    public void add(E element) {
        final Node<E> l = last;
        final Node<E> newNode = new Node<>(last, null, element);
        if (l == null) {
            first = newNode;
        } else {
            l.next = newNode;
        }
        last = newNode;

        size++;
    }

    @Override
    public E remove() {
        final Node<E> f = first;
        if (f == null) {
            return null;
        } else {
            Node<E> next = f.next;
            E value = f.value;
            first = next;
            f.value = null;
            f.next = null;
            if (next != null) {
                next.prev = null;
            }
            size--;
            return value;
        }
    }

    @Override
    public int size() {
        return size;
    }

    static class Node<E> {
        Node<E> prev;
        Node<E> next;
        E value;

        private Node(Node<E> prev, Node<E> next, E value) {
            this.prev = prev;
            this.next = next;
            this.value = value;
        }
    }
}