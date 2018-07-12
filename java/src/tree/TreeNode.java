package tree;

public class TreeNode<T> {
    T data;// 数据域
    TreeNode<T> lChild; // 左孩子
    TreeNode<T> rChild; // 右孩子

    public TreeNode(T data, TreeNode<T> lChild, TreeNode<T> rChild) {
        this.data = data;
        this.lChild = lChild;
        this.rChild = rChild;
    }
}