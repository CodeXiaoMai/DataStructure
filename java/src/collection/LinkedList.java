package collection;

import org.jetbrains.annotations.NotNull;

public class LinkedList<E> implements List<E> {

    private int size = 0;

    private Node<E> first;

    private Node<E> last;

    public LinkedList() {
    }

    @Override
    public E get(int index) {
        rangeCheck(index);

        return node(index).element;
    }

    private Node<E> node(int index) {
        // 如果 index 小于中点索引，就从前向后查找，
        // 否则从后向前查找
        if (index < (size >> 1)) {
            Node<E> p = first;

            for (int i = 0; i < index; i++) {
                p = p.next;
            }

            return p;
        } else {
            Node<E> p = last;

            for (int i = size - 1; i > index; i--) {
                p = p.prev;
            }

            return p;
        }
    }

    private void rangeCheck(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
    }

    @Override
    public E set(int index, E element) {
        rangeCheck(index);

        Node<E> node = node(index);
        E oldValue = node.element;
        node.element = element;

        return oldValue;
    }

    @Override
    public boolean insert(int index, E element) {
        rangeCheckForInsert(index);

        if (index == size) {
            linkLast(element);
        } else {
            linkBefore(element, node(index));
        }
        return false;
    }

    private void linkBefore(E element, @NotNull Node<E> node) {
        final Node<E> prev = node.prev;
        final Node<E> newNode = new Node<>(prev, node, element);
        node.prev = newNode;
        if (prev == null) {
            first = newNode;
        } else {
            prev.next = newNode;
        }
        size++;
    }

    private void linkLast(E element) {
        final Node<E> l = last;
        final Node<E> node = new Node<>(l, null, element);
        last = node;

        if (l == null) {
            first = node;
        } else {
            l.next = node;
        }
        size++;
    }

    private void rangeCheckForInsert(int index) {
        if (index > size || index < 0) {
            throw new IndexOutOfBoundsException();
        }
    }

    @Override
    public E removeAt(int index) {
        rangeCheck(index);

        return unlink(node(index));
    }

    @Override
    public int indexOf(E object) {
        if (object == null) {
            Node<E> p = first;
            for (int i = 0; i < size; i++) {
                if (p.element == null) {
                    return i;
                }
                p = p.next;
            }
        } else {
            Node<E> p = first;
            for (int i = 0; i < size; i++) {
                if (object.equals(p.element)) {
                    return i;
                }
                p = p.next;
            }
        }

        return -1;
    }

    @Override
    public boolean add(E element) {
        linkLast(element);
        return true;
    }

    @Override
    public boolean remove(Object element) {
        Node<E> p = first;
        if (element == null) {
            for (; p != null; p = p.next) {
                if (p.element == null) {
                    unlink(p);
                    return true;
                }
            }
            return false;
        } else {
            for (; p != null; p = p.next) {
                if (element.equals(p.element)) {
                    unlink(p);
                    return true;
                }
            }
            return false;
        }
    }

    private E unlink(Node<E> node) {
        final Node<E> prev = node.prev;
        final Node<E> next = node.next;
        final E element = node.element;

        if (prev == null) {
            first = next;
        } else {
            prev.next = next;
            node.prev = null;
        }
        if (next == null) {
            last = prev;
        } else {
            next.prev = prev;
            node.next = null;
        }

        node.element = null;
        size--;
        return element;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public boolean isNotEmpty() {
        return size > 0;
    }

    @Override
    public boolean contains(E element) {
        return indexOf(element) >= 0;
    }

    @Override
    public void clear() {
        Node<E> node = first;
        while (node != null) {
            final Node<E> next = node.next;
            node.prev = null;
            node.element = null;
            node.next = null;
            node = next;
        }
        size = 0;
        first = null;
        last = null;
    }

    private static class Node<E> {
        Node<E> prev;
        Node<E> next;
        E element;

        private Node(Node<E> prev, Node<E> next, E element) {
            this.prev = prev;
            this.next = next;
            this.element = element;
        }
    }
}
