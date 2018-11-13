

public class binary_search_tree {
    class TreeNode {
        private int key, data;
        private TreeNode left;
        private TreeNode right;
        public TreeNode(int key, int data) {
            this.key = key;
            this.data = 0;
            this.left = null;
            this.right = null;
        }
    }

    TreeNode root;

    binary_search_tree() {
        root = null;
    }

    public boolean is_empty() {
        return root == null;
    }

    public TreeNode search(TreeNode node, int key) {
        if (node == null || node.key == key)
            return node;
        else if (node.key < key)
            return search(node.right, key);
        return search(node.left, key);
    }

    public void insert(int key, int data){
        if (is_empty())
            root = new TreeNode(key, data);
        if (search(root, key))

    }
}
