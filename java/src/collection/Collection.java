package collection;

public interface Collection<E> {

    boolean add(E element);

    boolean remove(E element);

    int size();

    boolean isEmpty();

    boolean isNotEmpty();

    boolean contains(E element);

    void clear();
}
