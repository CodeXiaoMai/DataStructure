package collection;

import java.io.Serializable;
import java.util.Comparator;

/**
 * 将键映射到值的对象。map 不能包含重复的键；每个键最多可以映射到一个值。
 *
 * @param <K>
 * @param <V>
 */
public interface Map<K, V> {
    // 查询操作

    int size();

    boolean isEmpty();

    boolean isNotEmpty();

    boolean containsKey(Object key);

    boolean containsValue(Object value);

    V get(Object key);

    // 修改操作

    V put(K key, V value);

    V remove(Object key);

    // 批量操作

    void putAll(Map<? extends K, ? extends V> value);

    void clear();

    // 视图

    Set<K> keySet();

    Collection<V> values();

    interface Entry<K, V> {
        K getKey();

        V getValue();

        V setValue(V value);

        @Override
        boolean equals(Object o);

        /**
         * The hash code of a map entry
         * (e.getKey()==null   ? 0 : e.getKey().hashCode()) ^
         * (e.getValue()==null ? 0 : e.getValue().hashCode())
         *
         * @return
         */
        @Override
        int hashCode();

        public static <K extends Comparable<? super K>, V> Comparator<Entry<K, V>> comparingByKey() {
            return (Comparator<Entry<K, V>> & Serializable)
                    (c1, c2) -> c1.getKey().compareTo(c2.getKey());
        }
    }

    boolean equals(Object o);

    int hashCode();

    default V getOrDefault(K key, V defaultValue) {
        V v;
        return ((v = get(key)) != null) || containsKey(key) ?
                v :
                defaultValue;
    }
}
