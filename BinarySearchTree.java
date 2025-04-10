public class BinarySearchTree {
    
    // Node definition
    static class Node {
        int key;
        Node left, right;

        public Node(int item) {
            key = item;
            left = right = null;
        }
    }

    // Root node of the tree
    Node root;

    // Constructor
    BinarySearchTree() {
        root = null;
    }

    // Insert key in the BST
    void insert(int key) {
        root = insertRec(root, key);
    }

    // Recursive insert function
    Node insertRec(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }

        if (key < root.key)
            root.left = insertRec(root.left, key);
        else if (key > root.key)
            root.right = insertRec(root.right, key);

        return root;
    }

    // Inorder traversal
    void inorder() {
        inorderRec(root);
    }

    void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.key + " ");
            inorderRec(root.right);
        }
    }

    // Search for a key
    boolean search(int key) {
        return searchRec(root, key);
    }

    boolean searchRec(Node root, int key) {
        if (root == null) return false;
        if (root.key == key) return true;

        if (key < root.key)
            return searchRec(root.left, key);
        else
            return searchRec(root.right, key);
    }

    // Main method to test it
    public static void main(String[] args) {
        BinarySearchTree tree = new BinarySearchTree();

        int[] values = {50, 30, 70, 20, 40, 60, 80};
        for (int val : values) {
            tree.insert(val);
        }

        System.out.println("Inorder traversal (sorted):");
        tree.inorder();

        int searchKey = 60;
        System.out.println("\n\nSearch for " + searchKey + ": " + (tree.search(searchKey) ? "Found" : "Not Found"));
    }
}
