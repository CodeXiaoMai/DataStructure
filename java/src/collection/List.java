package collection;

public interface List<E> extends Collection<E> {

    E get(int index);

    E set(int index, E element);

    boolean insert(int index, E element);

    E removeAt(int index);

    int indexOf(E object);
}
