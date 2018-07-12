package tree;

import java.util.Scanner;

/**
 * 二叉树
 */
public class BinaryTree {

    public static void main(String args[]) {
//        TreeNode<String> nodeK = new TreeNode<>("K", null, null);
//        TreeNode<String> nodeJ = new TreeNode<>("J", null, null);
//        TreeNode<String> nodeI = new TreeNode<>("I", null, null);
//        TreeNode<String> nodeH = new TreeNode<>("H", null, nodeK);
//        TreeNode<String> nodeG = new TreeNode<>("G", null, nodeJ);
//        TreeNode<String> nodeF = new TreeNode<>("F", nodeI, null);
//        TreeNode<String> nodeE = new TreeNode<>("E", null, null);
//        TreeNode<String> nodeD = new TreeNode<>("D", nodeH, null);
//        TreeNode<String> nodeC = new TreeNode<>("C", nodeF, nodeG);
//        TreeNode<String> nodeB = new TreeNode<>("B", nodeD, nodeE);
//        TreeNode<String> nodeA = new TreeNode<>("A", nodeB, nodeC);

        TreeNode<Object> binaryTree = createBinaryTree();
        postOrderTraverse(binaryTree);
    }

    /**
     * 创建二叉树
     *
     * @param <T>
     * @return
     */
    @SuppressWarnings("unchecked")
    private static <T> TreeNode<T> createBinaryTree() {
        TreeNode<T> root = null;
        Scanner scanner = new Scanner((System.in));
        System.out.println("data =\n");
        String data = scanner.next();
        if (!data.equals("null")) {
            root = new TreeNode<>((T) data, createBinaryTree(), createBinaryTree());
        }
        return root;
    }

    /**
     * 前序遍历
     */
    private static <T> void preOrderTraverse(TreeNode<T> root) {
        if (root == null) {
            return;
        }
        System.out.println(root.data);
        // 前序遍历左子树
        preOrderTraverse(root.lChild);
        // 前序遍历右子树
        preOrderTraverse(root.rChild);
    }

    /**
     * 中序遍历
     */
    private static <T> void inOrderTraverse(TreeNode<T> root) {
        if (root == null) {
            return;
        }
        // 中序遍历左子树
        inOrderTraverse(root.lChild);
        // 访问结点数据
        System.out.println(root.data);
        // 中序遍历右子树
        inOrderTraverse(root.rChild);
    }

    /**
     * 后序遍历
     */
    private static <T> void postOrderTraverse(TreeNode<T> root) {
        if (root == null) {
            return;
        }
        // 后序遍历左子树
        postOrderTraverse(root.lChild);
        // 后序遍历右子树
        postOrderTraverse(root.rChild);
        // 访问结点数据
        System.out.println(root.data);
    }
}