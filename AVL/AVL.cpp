#include "AVL.H"

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    eliminarTodo();
}

void AVLTree::agregar(int registro, const std::string& nombre, const std::string& fechaNacimiento) {
    root = insert(root, registro, nombre, fechaNacimiento);
}

void AVLTree::eliminar(int registro) {
    root = remove(root, registro);
}

void AVLTree::eliminarTodo() {
    while (root != nullptr) {
        eliminar(root->registro);
    }
}

void AVLTree::mostrar() {
    displayInOrder(root);
    std::cout << std::endl;
}

void AVLTree::orden() {
    mostrar();
}

void AVLTree::preorden() {
    displayPreOrder(root);
    std::cout << std::endl;
}

void AVLTree::postorden() {
    displayPostOrder(root);
    std::cout << std::endl;
}

int AVLTree::contar() {
    return countNodes(root);
}

int AVLTree::calcularAltura() {
    return calculateHeight(root);
}

Node* AVLTree::buscar(int registro) {
    return search(root, registro);
}

Node* AVLTree::insert(Node* node, int registro, const std::string& nombre, const std::string& fechaNacimiento) {
    if (node == nullptr) {
        node = new Node;
        node->registro = registro;
        node->nombre = nombre;
        node->fechaNacimiento = fechaNacimiento;
        node->height = 0;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (registro < node->registro) {
        node->left = insert(node->left, registro, nombre, fechaNacimiento);
        if (getBalance(node) == 2) {
            if (registro < node->left->registro)
                node = rotateRight(node);
            else
                node = rotateLeftRight(node);
        }
    }
    else if (registro > node->registro) {
        node->right = insert(node->right, registro, nombre, fechaNacimiento);
        if (getBalance(node) == -2) {
            if (registro > node->right->registro)
                node = rotateLeft(node);
            else
                node = rotateRightLeft(node);
        }
    }
    node->height = max(calculateHeight(node->left), calculateHeight(node->right)) + 1;
    return node;
}

Node* AVLTree::remove(Node* node, int registro) {
    if (node == nullptr)
        return nullptr;
    if (registro < node->registro) {
        node->left = remove(node->left, registro);
    }
    else if (registro > node->registro) {
        node->right = remove(node->right, registro);
    }
    else {
        if ((node->left == nullptr) || (node->right == nullptr)) {
            Node* temp = node->left ? node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            }
            else {
                *node = *temp;
            }
            delete temp;
        }
        else {
            Node* temp = findMin(node->right);
            node->registro = temp->registro;
            node->nombre = temp->nombre;
            node->fechaNacimiento = temp->fechaNacimiento;
            node->right = remove(node->right, temp->registro);
        }
    }
    if (node == nullptr)
        return nullptr;
    node->height = max(calculateHeight(node->left), calculateHeight(node->right)) + 1;
    if (getBalance(node) == 2) {
        if (getBalance(node->left) >= 0)
            return rotateRight(node);
        else
            return rotateLeftRight(node);
    }
    if (getBalance(node) == -2) {
        if (getBalance(node->right) <= 0)
            return rotateLeft(node);
        else
            return rotateRightLeft(node);
    }
    return node;
}

Node* AVLTree::findMin(Node* node) {
    if (node == nullptr)
        return nullptr;
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void AVLTree::displayInOrder(Node* node) {
    if (node != nullptr) {
        displayInOrder(node->left);
        std::cout << "Registro: " << node->registro << ", Nombre: " << node->nombre << ", Fecha de nacimiento: " << node->fechaNacimiento << std::endl;
        displayInOrder(node->right);
    }
}

void AVLTree::displayPreOrder(Node* node) {
    if (node != nullptr) {
        std::cout << "Registro: " << node->registro << ", Nombre: " << node->nombre << ", Fecha de nacimiento: " << node->fechaNacimiento << std::endl;
        displayPreOrder(node->left);
        displayPreOrder(node->right);
    }
}

void AVLTree::displayPostOrder(Node* node) {
    if (node != nullptr) {
        displayPostOrder(node->left);
        displayPostOrder(node->right);
        std::cout << "Registro: " << node->registro << ", Nombre: " << node->nombre << ", Fecha de nacimiento: " << node->fechaNacimiento << std::endl;
    }
}

int AVLTree::countNodes(Node* node) {
    if (node == nullptr)
        return 0;
    return countNodes(node->left) + countNodes(node->right) + 1;
}

int AVLTree::calculateHeight(Node* node) {
    if (node == nullptr)
        return -1;
    return node->height;
}

Node* AVLTree::search(Node* node, int registro) {
    if (node == nullptr || node->registro == registro)
        return node;
    if (registro < node->registro)
        return search(node->left, registro);
    return search(node->right, registro);
}

Node* AVLTree::rotateRight(Node* node) {
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = max(calculateHeight(node->left), calculateHeight(node->right)) + 1;
    temp->height = max(calculateHeight(temp->left), node->height) + 1;
    return temp;
}

Node* AVLTree::rotateLeft(Node* node) {
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = max(calculateHeight(node->left), calculateHeight(node->right)) + 1;
    temp->height = max(node->height, calculateHeight(temp->right)) + 1;
    return temp;
}

Node* AVLTree::rotateLeftRight(Node* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

Node* AVLTree::rotateRightLeft(Node* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

int AVLTree::getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return calculateHeight(node->left) - calculateHeight(node->right);
}

int AVLTree::max(int a, int b) {
    return (a > b) ? a : b;
}
