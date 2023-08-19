#include <iostream>

namespace BT
{
    template <typename T>
    class BinaryTree
    {
    public:
        using tree_t = BinaryTree;
        using value_type = T;

    private:
        tree_t *left;
        tree_t *right;
        value_type data;

        // Prefix method (NLR) Pre-Order
        void printPrefix(tree_t *tree) const;
        // Infix method (LNR) In-order
        void printInfix(tree_t *tree) const;
        // Postfix method (LRN) Post-order
        void printPostfix(tree_t *tree) const;
        // clearing tree
        void free(tree_t *tree);
        // insert new value
        tree_t *_insert(tree_t *tree, value_type data);
        // Compare this==other
        bool _compare_tree(const tree_t *first, const tree_t *second) const;
        // find with Pre-Order method
        bool findPrefix(tree_t *tree, value_type data);
        // find with In-order method
        bool findInfix(tree_t *tree, value_type data);
        // find with Post-order method
        bool findPostfix(tree_t *tree, value_type data);

    public:
        BinaryTree() : data(nullptr), left(nullptr), right(nullptr) {}
        explicit BinaryTree(value_type root) : data(root), left(nullptr), right(nullptr) {}
        ~BinaryTree()
        {
            free(this);
        }
        void clear();
        //

        BinaryTree(const tree_t &tree)
            : data(tree.data), left(tree.left), right(tree.right)
        {
        }

        BinaryTree &operator=(const tree_t &tree)
        {
            if (this == &tree)
                return *this;

            data = tree.data;
            left = tree.left;
            right = tree.right;

            return *this;
        }

        // const move
        // const =move
        // const initializer_list

        // overloading?? value_type
        // move/forward
        // type_traits
        // allocator?
        // delete element

        bool isEmpty() const;
        //

        void insert(value_type data);

        // comapare tree
        bool compare_tree(const tree_t *other) const;
        // Depth First Search
        void printPreOrder();
        void printInOrder();
        void printPostOrder();
        //
        /* Depth First Search*/
        // find Prefix method (NLR) Pre-Order
        bool findPreOrder(value_type fdata);
        // find Infix method (LNR) In-order
        bool findSymmetric(value_type fdata);
        // find Postfix method (LRN) Post-order
        bool findReverse(value_type fdata);

        /* Breadth First Search*/
        bool wfind(value_type fdata);
    };

    // clearing tree
    template <typename T>
    void BinaryTree<T>::free(tree_t *tree)
    {
        if (tree != nullptr)
        {
            free(tree->left);
            free(tree->right);
            delete tree;
        }
    }
    template <typename T>
    void BinaryTree<T>::clear()
    {
        std::cout<<"Удаление дерева!\n";
        free(this);
    }

    template <typename T>
    typename BinaryTree<T>::tree_t *BinaryTree<T>::_insert(tree_t *tree, value_type data)
    {
        if (tree == nullptr)
            return new tree_t(data);

        data < tree->data ? (tree->left = _insert(tree->left, data))
                          : (tree->right = _insert(tree->right, data));

        return tree;
    }

    template <typename T>
    void BinaryTree<T>::insert(value_type data)
    {
        _insert(this, data);
    }

    template <typename T>
    bool BinaryTree<T>::_compare_tree(const tree_t *first, const tree_t *second) const
    {
        ///!!!!!! не реализовано
        return false;
    }

    template <typename T>
    bool BinaryTree<T>::compare_tree(const tree_t *other) const
    {
        return _compare_tree(this, other);
    }

    template <typename T>
    bool BinaryTree<T>::isEmpty() const
    {
        return (this == nullptr);
    }

    template <typename T>
    void BinaryTree<T>::printPrefix(tree_t *tree) const
    {
        if (tree == nullptr)
            return;
        else
        {
            std::cout << tree->data << " ";
            printPrefix(tree->left);
            printPrefix(tree->right);
        }
    }
    template <typename T>
    void BinaryTree<T>::printInfix(tree_t *tree) const
    {
        if (tree == nullptr)
            return;
        else
        {
            printInfix(tree->left);
            std::cout << tree->data << " ";
            printInfix(tree->right);
        }
    }
    template <typename T>
    void BinaryTree<T>::printPostfix(tree_t *tree) const
    {
        if (tree == nullptr)
            return;
        else
        {
            printPostfix(tree->left);
            printPostfix(tree->right);
            std::cout << tree->data << " ";
        }
    }
    template <typename T>
    void BinaryTree<T>::printPreOrder()
    {
        printPrefix(this);
        std::cout << std::endl;
    }
    template <typename T>
    void BinaryTree<T>::printInOrder()
    {
        printInfix(this);
        std::cout << std::endl;
    }
    template <typename T>
    void BinaryTree<T>::printPostOrder()
    {
        printPostfix(this);
        std::cout << std::endl;
    }

    template <typename T>
    bool BinaryTree<T>::findPrefix(tree_t *tree, value_type data)
    {
        if (tree == nullptr)
            return false;

        if (tree->data == data)
            return true;
        else if (data < tree->data)
            return findPrefix(tree->left, data);
        else if (data > tree->data)
            return findPrefix(tree->right, data);

        return false;
    }

    template <typename T>
    bool BinaryTree<T>::findInfix(tree_t *tree, value_type data)
    {
        if (tree == nullptr)
            return false;

        if (data < tree->data)
            return findPrefix(tree->left, data);
        else if (tree->data == data)
            return true;
        else if (data > tree->data)
            return findPrefix(tree->right, data);

        return false;
    }

    template <typename T>
    bool BinaryTree<T>::findPostfix(tree_t *tree, value_type data)
    {
        if (tree == nullptr)
            return false;

        if (data < tree->data)
            return findPrefix(tree->left, data);
        else if (data > tree->data)
            return findPrefix(tree->right, data);
        if (tree->data == data)
            return true;

        return false;
    }

    template <typename T>
    bool BinaryTree<T>::findPreOrder(value_type fdata)
    {
        return findPrefix(this, fdata);
    }
    template <typename T>
    bool BinaryTree<T>::findSymmetric(value_type fdata)
    {
        return findInfix(this, fdata);
    }
    template <typename T>
    bool BinaryTree<T>::findReverse(value_type fdata)
    {
        return findPostfix(this, fdata);
    }
}
