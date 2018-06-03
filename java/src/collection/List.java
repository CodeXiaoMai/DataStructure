package collection;

/**
 * 一个有序的集合，就像序列一样。与 Set 不同，List 通常允许重复元素。
 * @param <E>
 */
public interface List<E> extends Collection<E> {

    E get(int index);

    E set(int index, E element);

    boolean insert(int index, E element);

    E removeAt(int index);

    int indexOf(E object);
}
