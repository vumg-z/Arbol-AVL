#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <string>

struct Node
{
    int registro;
    std::string nombre;
    std::string fechaNacimiento;
    int height;
    Node* left;
    Node* right;
};

class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void agregar(int registro, const std::string& nombre, const std::string& fechaNacimiento);
    void eliminar(int registro);
    void eliminarTodo();
    void mostrar();
    void orden();
    void preorden();
    void postorden();
    int contar();
    int calcularAltura();
    Node* buscar(int registro);

private:
    Node* root;

    Node* insert(Node* node, int registro, const std::string& nombre, const std::string& fechaNacimiento);
    Node* remove(Node* node, int registro);
    Node* findMin(Node* node);
    void displayInOrder(Node* node);
    void displayPreOrder(Node* node);
    void displayPostOrder(Node* node);
    int countNodes(Node* node);
    int calculateHeight(Node* node);
    Node* search(Node* node, int registro);

    Node* rotateRight(Node* node);
    Node* rotateLeft(Node* node);
    Node* rotateLeftRight(Node* node);
    Node* rotateRightLeft(Node* node);

    int getBalance(Node* node);
    int max(int a, int b);
};

#endif

