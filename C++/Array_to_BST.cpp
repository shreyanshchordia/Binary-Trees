#include <bits/stdc++.h>

using namespace std;

// Array to Balanced Binary Search Tree
// Convert an Array to a Balanced Binary Search Tree

template <typename T>
struct node {  // Single Node
    T data;
    node *left;
    node *right;

    explicit node(T val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T>
void print_spaced(const T &value) {
    cout << value << ' ';
}

template <typename T>
class tree {  // Binary Tree Class
    using node = ::node<T>;

   public:
    tree() {  // Contructor
    }
    tree(const tree &o) {
        o.preorder([this](const T &item) { this->add(item); });
    }
    tree(tree &&o) {
        swap(this->root, o.root);
        swap(this->size_, o.size_);
    }
    ~tree() {  // Destructor
        postorder(root, [](node *n) { delete n; });
    }

    tree &operator=(const tree &o) {
        tree temp(o);
        swap(*this, temp);
    }

    tree &operator=(tree &&o) {
        swap(this->root, o.root);
        swap(this->size_, o.size_);
        return *this;
    }

    void add(const T &val) {  // Add Element to BST
        node **it = &root;
        while (*it) {
            node *n = *it;
            if (val < n->data)
                it = &n->left;
            else if (n->data < val)
                it = &n->right;
            else         // n->data == val
                return;  // The element already exists
        }
        *it = new node(val);
        size_++;
    }

    template <typename Func>
    void inorder(Func f) const {  // Inorder Traversal
        inorder(root, [&](const node *n) { f(n->data); });
    }

    template <typename Func>
    void postorder(Func f) const {  // Postorder Traversal
        postorder(root, [&](const node *n) { f(n->data); });
    }

    template <typename Func>
    void preorder(Func f) const {  // Preorder Traversal
        preorder(root, [&](const node *n) { f(n->data); });
    }

    void print_inorder() const {
        inorder(print_spaced<int>);
        cout << "\n";
    }

    void print_preorder() const {
        preorder(print_spaced<int>);
        cout << "\n";
    }

    void print_postorder() const {
        postorder(print_spaced<int>);
        cout << "\n";
    }

   private:
    node *root = nullptr;
    size_t size_ = 0;

    template <typename NodeType, typename Func>
    static void inorder(NodeType *root, Func f) {  // Inorder Traversal
        if (root) {
            inorder(root->left, f);
            f(root);
            inorder(root->right, f);
        }
    }

    template <typename NodeType, typename Func>
    static void postorder(NodeType *root, Func f) {  // Postorder Traversal
        if (root) {
            postorder(root->left, f);
            postorder(root->right, f);
            f(root);
        }
    }

    template <typename NodeType, typename Func>
    static void preorder(NodeType *root, Func f) {  // Preorder Traversal
        if (root) {
            f(root);
            preorder(root->left, f);
            preorder(root->right, f);
        }
    }
};

template <typename T>
void build_tree(const vector<T> &a, int l, int r, tree<T> &t) {  // Build BST
    if (l == r) {
        t.add(a[l]);
        return;
    }
    if (l > r)
        return;
    int mid = (l + r) / 2;
    t.add(a[mid]);
    build_tree(a, l, mid - 1, t);
    build_tree(a, mid + 1, r, t);
    return;
}

int main() {
    int n;
    cout << "How many numbers will you insert?: ";
    cin >> n;  // Number of Elements in Array

    vector<int> a;
    cout << "Write the numbers: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);  // Array Input
    }

    sort(a.begin(), a.end());  // Sorting Array

    tree<int> t;
    build_tree(a, 0, n - 1, t);

    cout << "Preorder: ";
    t.print_preorder();
    cout << "Inorder: ";
    t.print_inorder();  // It will be Sorted
    cout << "Postorder: ";
    t.print_postorder();
}