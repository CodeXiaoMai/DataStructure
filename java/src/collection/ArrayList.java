package collection;

public class ArrayList<E> implements List<E> {

    private int size;

    private static final int DEFAULT_SIZE = 10;

    private Object[] elementData = {};

    public ArrayList() {
        elementData = new Object[DEFAULT_SIZE];
    }

    public ArrayList(int capacity) {
        if (capacity > 0) {
            elementData = new Object[capacity];
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
    public E set(int index, E element) {
        rangeCheck(index);

        E elementData = elementData(index);
        this.elementData[index] = element;
        return elementData;
    }

    @Override
    public boolean insert(int index, E element) {
        rangeCheck(index);

        System.arraycopy(elementData, index, elementData, index + 1, size - index);

        elementData[index] = element;
        size++;
        return true;
    }

    @Override
    public E remove(int index) {
        rangeCheck(index);

        E oldValue = elementData(index);

        fastRemove(index);
        return oldValue;
    }

    @Override
    public int indexOf(E element) {
        // 因为判断非基本类型的变量是否相等使用 equals() 方法，而 element 又可能为 null,
        // 所以需要对 element 进行判断
        if (element == null) {
            for (int i = 0; i < size; i++) {
                if (elementData[i] == null) {
                    return i;
                }
            }
        } else {
            for (int i = 0; i < size; i++) {
                if (element.equals(elementData[i])) {
                    return i;
                }
            }
        }
        return -1;
    }

    @Override
    public boolean add(E element) {
        elementData[size++] = element;
        return true;
    }

    @Override
    public boolean remove(E element) {
        if (element == null) {
            for (int i = 0; i < size; i++) {
                if (elementData[i] == null) {
                    fastRemove(i);
                    return true;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (elementData[i].equals(element)) {
                fastRemove(i);
                return true;
            }
        }
        return false;
    }

    private void fastRemove(int index) {
        int numMoved = size - index - 1;
        if (numMoved > 0) {
            System.arraycopy(elementData, index + 1, elementData, index, numMoved);
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
    public boolean contains(E element) {
        return indexOf(element) >= 0;
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
