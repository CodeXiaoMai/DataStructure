package collection;

public interface Collection<E> {

    boolean add(E value);

    boolean remove(Object value);

    int size();

    boolean isEmpty();

    boolean isNotEmpty();

    boolean contains(Object value);

    void clear();
}
