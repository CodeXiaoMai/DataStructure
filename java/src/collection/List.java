package collection;

public interface List<E> extends Collection<E> {

    E get(int index);

    E set(int index, E value);

    boolean insert(int index, E value);

    E remove(int index);

    int indexOf(Object object);
}
