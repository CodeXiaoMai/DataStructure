package collection;

public class ArrayStack<E> extends ArrayList<E> implements Stack<E> {

    @Override
    public boolean push(E element) {
        return add(element);
    }

    @Override
    public E pop() {
        return removeAt(size() - 1);
    }

    @Override
    public E peek() {
        if (size() == 0) {
            return null;
        }
        return get(size() - 1);
    }
}
