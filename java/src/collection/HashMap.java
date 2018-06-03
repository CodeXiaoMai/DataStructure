package collection;

import java.io.Serializable;
import java.util.Objects;

/**
 * HashMap 和 HashTable 大致相似，
 * HashMap 是不支持同步的，允许 key 和 value 的值为 null；
 * HashTable 是同步的，不允许 key 和 value 为 null。
 */
public class HashMap<K, V> implements Map<K, V>, Serializable {

    private static final long serialVersionUID = 362498820763181265L;

    // 默认初始化容量，必须是 2 的指数倍
    static final int DEFAULT_INITIAL_CAPACITY = 1 << 4;

    // 最大容量，因此容量必须介于 2 到 1 << 30 之间
    static final int MAXIMUM_CAPACITY = 1 << 30;

    // 默认负载因子
    static final float DEFAULT_LOAD_FACTOR = 0.75f;

    // 被 transient 修饰的字段不会参与序列化
    transient Node<K, V>[] table;

    transient Set<Map.Entry<K, V>> entrySet;

    transient int size;

    // 下一次调整容量的阀值
    int threshold;

    // 哈希表的负载因子
    final float loadFactor;

    public HashMap(int initialCapacity, float loadFactor) {
        if (initialCapacity < 0) {
            throw new IllegalArgumentException("Illegal initial capacity: " +
                    initialCapacity);
        }
        if (initialCapacity > MAXIMUM_CAPACITY) {
            initialCapacity = MAXIMUM_CAPACITY;
        }
        if (loadFactor < 0 || Float.isNaN(loadFactor)) {
            throw new IllegalArgumentException("Illegal load factor: " +
                    loadFactor);
        }
        this.loadFactor = loadFactor;
        this.threshold = tableSizeFor(initialCapacity);
    }

    /**
     * 指定一个数 n，返回一个数 m，满足 m >= n，且 m 是 2 的幂次方
     * 如果 initialCapacity 就是一个 2 的幂次方的数，经过5次无符号右移后再加 1，得到的数就是 initialCapacity 的两倍，所以要先将它减 1。
     *
     * @param initialCapacity
     * @return
     */
    private int tableSizeFor(int initialCapacity) {
        int n = initialCapacity - 1;
        n |= n >>> 1;
        n |= n >>> 2;
        n |= n >>> 4;
        n |= n >>> 8;
        n |= n >>> 16;
        if (n < 0) {
            n = 1;
        } else if (n >= MAXIMUM_CAPACITY) {
            n = MAXIMUM_CAPACITY;
        } else {
            n += 1;
        }
        return n;
    }

    @Override
    public int size() {
        return 0;
    }

    @Override
    public boolean isEmpty() {
        return false;
    }

    @Override
    public boolean isNotEmpty() {
        return false;
    }

    @Override
    public boolean containsKey(Object key) {
        return false;
    }

    @Override
    public boolean containsValue(Object value) {
        return false;
    }

    @Override
    public V get(Object key) {
        return null;
    }

    @Override
    public V put(K key, V value) {
        return null;
    }



    @Override
    public V remove(Object key) {
        return null;
    }

    @Override
    public void putAll(Map<? extends K, ? extends V> value) {

    }

    @Override
    public void clear() {

    }

    @Override
    public Set<K> keySet() {
        return null;
    }

    @Override
    public Collection<V> values() {
        return null;
    }

    static class Node<K, V> implements Map.Entry<K, V> {
        final int hash;
        final K key;
        V value;
        Node<K, V> next;

        public Node(int hash, K key, V value, Node<K, V> next) {
            this.hash = hash;
            this.key = key;
            this.value = value;
            this.next = next;
        }

        @Override
        public K getKey() {
            return key;
        }

        @Override
        public V getValue() {
            return value;
        }

        @Override
        public V setValue(V value) {
            V oldValue = this.value;
            this.value = value;
            return oldValue;
        }

        @Override
        public String toString() {
            return key + "=" + value;
        }

        @Override
        public final int hashCode() {
            return Objects.hashCode(key) ^ Objects.hashCode(value);
        }

        @SuppressWarnings("unchecked")
        @Override
        public boolean equals(Object obj) {
            if (obj == this) {
                return true;
            }
            if (obj instanceof Map.Entry) {
                Entry<K, V> entry = (Map.Entry<K, V>) obj;
                if (Objects.equals(entry.getKey(), key) &&
                        Objects.equals(entry.getValue(), value)) {
                    return true;
                }
            }
            return false;
        }
    }
}
