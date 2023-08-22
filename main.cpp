#include "binatyTree.cpp"
#include <random>
#include <set>

// реализация бинарного дерево
// бинарного поиска в глубину(прямой обход/префиксный, центрированный/инфиксный, обратный/постфиксный)
// бинарного поиска в ширину
//

struct Widget;

int main()
{
    using namespace BT;
    std::cout << std::boolalpha;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 50);

    // int
    {
        BinaryTree<int> *tree;
        std::cout << "Is empty binary tree?: " << tree->isEmpty() << std::endl;
        std::cout << "create root 56\n";
        tree = new BinaryTree(16);
        std::cout << "Is empty binary tree?: " << tree->isEmpty() << std::endl;

        std::cout << "Insert: ";
        for (int i = 0; i < 10; ++i)
            tree->insert(dist(gen));
        std::cout << std::endl;

        tree->printPreOrder();
        tree->printInOrder();
        tree->printPostOrder();
        // value for find in tree
        auto f_val = 55, fv2 = 46, fv3 = 56;
        std::cout << "Is value " << f_val << " has in binary tree? " << tree->findPreOrder(f_val) << std::endl;
        std::cout << "Is value " << fv2 << " has in binary tree? " << tree->findSymmetric(fv2) << std::endl;
        std::cout << "Is value " << fv3 << " has in binary tree? " << tree->findReverse(fv3) << std::endl;
        //
        std::cout << "getMin \t" << tree->getMin() << std::endl;
        std::cout << "getMax \t" << tree->getMax() << std::endl;

        //
        /////tree2
        std::cout << "constructor copy tree2=tree\n";
        BinaryTree<int> *tree2 = tree;
        //
        tree2->printPreOrder();
        std::cout << "Is compare?: " << tree2->compare_tree(tree) << std::endl;

        std::cout << "Insert: ";
        tree2->insert(1);
        std::cout << std::endl;

        std::cout << "Is compare?: " << tree2->compare_tree(tree) << std::endl;
        // tree3

        //
        std::cout << "constructor copy= tree2=tree\n";
        BinaryTree<int> *tree3;
        tree3 = tree2;
        tree3->printPreOrder();
        std::cout << "Is compare?: " << tree3->compare_tree(tree2) << std::endl;
        //
        BinaryTree<int> *tree4 = new BinaryTree{5, 67, 89, 0, 11, 56, 123, 78, 9, 0, 1, 1, 5};
        std::cout << std::endl;
        tree4->printPreOrder();

        //
        //
        tree->clear();

        std::cout << "Is empty binary tree?: " << tree->isEmpty() << std::endl;
    }
    //
    {
        std::set<char> mnoj{'H', 'T', 'O'};
        std::string s{"Hello"};

        //  BinaryTree<std::string> *tree = new BinaryTree(s);
        //   BinaryTree<std::set<char>> *tree2 = new BinaryTree(mnoj);
        BinaryTree<double> *tree3 = new BinaryTree(5.55);

        /*        BinaryTree<Widget> *tree4 = new BinaryTree(Widget());
                 Widget w1, w2, w3;
                 tree4->insert(std::forward<Widget>(w1));
                 tree4->insert(std::forward<Widget>(w2));
                 tree4->insert(std::forward<Widget>(w3));

                 tree4->printPreOrder();

           //  tree3->clear();
           //  tree4->clear();

           */
    }
    return 0;
}

struct Widget
{
    static int count;
    uint16_t age;
    std::string name;
    Widget() : age(0), name(nullptr) {}
    Widget(uint16_t _age, const std::string _name) : age(_age), name(_name) {}
};