package collection;

public interface Stack<E> {

    boolean push(E element);

    E pop();

    /**
     * 查看栈顶元素，但不移除
     *
     * @return
     */
    E peek();
}