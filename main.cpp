#include "binatyTree.cpp"
#include <random>

// реализация бинарного дерево
// бинарного поиска в глубину(прямой обход/префиксный, центрированный/инфиксный, обратный/постфиксный)
// бинарного поиска в ширину
//

int main()
{
    using namespace BT;
    std::cout << std::boolalpha;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 20);

    BinaryTree<int> *tree;
    std::cout << "Is empty binary tree?: " << tree->isEmpty() << std::endl;
    std::cout << "create root 56\n";
    tree = new BinaryTree(56);
    std::cout << "Is empty binary tree?: " << tree->isEmpty() << std::endl;

    for (int i = 0; i < 10; ++i)
        tree->insert(dist(gen));

    tree->printPreOrder();
    tree->printInOrder();
    tree->printPostOrder();
    // value for find in tree
    auto f_val = 55, fv2 = 46, fv3 = 56;
    std::cout << "Is value " << f_val << " has in binary tree? " << tree->findPreOrder(f_val) << std::endl;
    std::cout << "Is value " << fv2 << " has in binary tree? " << tree->findSymmetric(fv2) << std::endl;
    std::cout << "Is value " << fv3 << " has in binary tree? " << tree->findReverse(fv3) << std::endl;
    //
    /////tree2
    std::cout << "constructor copy tree2=tree\n";
    BinaryTree<int> *tree2 = tree;
    //
    tree2->printPreOrder();
    std::cout << "Is compare?: " << tree2->compare_tree(tree) << std::endl;
    printf("Insert 1 in tree2\n");
    tree2->insert(1);
    std::cout << "Is compare?: " << tree2->compare_tree(tree) << std::endl;
    // tree3
    std::cout << "constructor copy= tree2=tree\n";
    BinaryTree<int> *tree3;
    tree3 = tree2;
    tree3->printPreOrder();
    std::cout << "Is compare?: " << tree3->compare_tree(tree2) << std::endl;

    tree->clear();

    std::cout << "Is empty binary tree?: " << tree->isEmpty() << std::endl;

    return 0;
}