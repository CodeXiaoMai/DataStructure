package collection;

public interface Queue<E> {

    void add(E element);

    E remove();

    int size();
}
