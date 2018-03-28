package collection;

public class ArrayList<E> implements List<E> {

    private int size;

    private static final int DEFAULT_SIZE = 10;

    private Object[] elementData = {};

    public ArrayList() {
        elementData = new Object[DEFAULT_SIZE];
    }

    public ArrayList(int cam) {
        if (cam > 0) {
            elementData = new Object[cam];
        } else {
            elementData = new Object[DEFAULT_SIZE];
        }
    }

    @Override
    public E get(int index) {
        rangeCheck(index);

        return elementData(index);
    }

    @Override
    public E set(int index, E value) {
        rangeCheck(index);

        E e = elementData(index);
        elementData[index] = value;
        return e;
    }

    @Override
    public boolean insert(int index, E value) {
        rangeCheck(index);

        for (int i = size; i > index; i--) {
            elementData[i] = elementData[i - 1];
        }
        elementData[index] = value;
        size++;
        return true;
    }

    @Override
    public E remove(int index) {
        rangeCheck(index);

        E oldValue = elementData(index);
        for (int i = index; i < size; i++) {
            elementData[i] = elementData[i + 1];
        }
        elementData[--size] = null;
        return oldValue;
    }

    @Override
    public int indexOf(Object object) {
        // 因为判断非基本类型的变量是否相等使用 equals() 方法，而 object 又可能为 null,
        // 所以需要对 object 进行判断
        if (object == null) {
            for (int i = 0; i < size; i++) {
                if (elementData[i] == null) {
                    return i;
                }
            }
        } else {
            for (int i = 0; i < size; i++) {
                if (object.equals(elementData[i])) {
                    return i;
                }
            }
        }
        return -1;
    }

    @Override
    public boolean add(E value) {
        elementData[size++] = value;
        return true;
    }

    @Override
    public boolean remove(Object value) {
        if (value == null) {
            for (int i = 0; i < size; i++) {
                if (elementData[i] == null) {
                    fastRemove(i);
                    return true;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (elementData[i] == value) {
                fastRemove(i);
                return true;
            }
        }
        return true;
    }

    private void fastRemove(int index) {
        for (int i = index; i < size; i++) {
            elementData[i] = elementData[i + 1];
        }
        elementData[--size] = null;
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
    public boolean contains(Object value) {
        return indexOf(value) >= 0;
    }

    @Override
    public void clear() {
        for (int i = 0; i < size; i++) {
            elementData[i] = null;
        }

        size = 0;
    }

    private void rangeCheck(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
    }

    @SuppressWarnings("unchecked")
    private E elementData(int index) {
        return (E) elementData[index];
    }
}
