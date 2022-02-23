#include "MyBTree.h"

template<typename T>
MyBTree<T>::MyBTree(const std::vector<T>& from) : m_root(nullptr), m_size(0) {
    std::cout << "init by vector..." << std::endl;
    for (int i = 0; i < from.size(); ++i) {
        insert(from[i]);
    }
}
template<typename T>
MyBTree<T>::MyBTree(const MyBTree& from) : m_root(nullptr), m_size(0) {
    std::cout << "init by another tree..." << std::endl;
    copy(from);
}
template<typename T>
MyBTree<T>& MyBTree<T>::operator= (const MyBTree<T>& from) {
    std::cout << "operator = ...." << std::endl;
    copy(from);
    return *this;
}
template<typename T>
bool MyBTree<T>::insert(const T& data) {
   if (m_root == nullptr) {
        m_root = new MyBTree<T>::Node(data);
        m_size++;
   } else {
        Node* fast = m_root;
        Node* slow = m_root;
        while (fast != nullptr) {
            slow = fast;
            if (data > fast->m_data) {
                fast = fast->m_right;
            } else if (data < fast->m_data) {
                fast = fast->m_left;
            } else {
                std::cout << "insert a data while existing" << std::endl;
                // std::runtime_error("insert a data while existing");
                return false;
            }
        }
        if (data > slow->m_data) {
            slow->m_right = new MyBTree<T>::Node(data);
            slow->m_right->m_parent = slow;
        } else {
            slow->m_left = new MyBTree<T>::Node(data);
            slow->m_left->m_parent = slow;
        }
        m_size++;
   }
   return true;
}
template<typename T>
bool MyBTree<T>::exists(const T& data) const {
    Node* node = m_root;
    while (node != nullptr) {
        if (data > node->m_data) {
            node = node->m_right;
        } else if (data < node->m_data) {
            node = node->m_left;
        } else {
            return true;
        }
    }
    return false;
}
template<typename T>
void MyBTree<T>::clear() {
    if (m_root == nullptr) {
        return;
    }
    std::stack<MyBTree<T>::Node*> st;
    st.push(m_root);
    while (!st.empty()) {
        auto topNode = st.top();
        st.pop();
        if (topNode->m_left != nullptr) {
            st.push(topNode->m_left);
        }
        if (topNode->m_right != nullptr) {
            st.push(topNode->m_right);
        }
        delete topNode;
    }
    m_root = nullptr;
    m_size = 0;
}
template<typename T>
T MyBTree<T>::minmum() const {
    return minmum(m_root)->m_data;
}
template<typename T>
T MyBTree<T>::maxmum() const {
    return maxmum(m_root)->m_data;
}
template<typename T>
std::ostream& operator<<(std::ostream& out, const MyBTree<T>& tree) {

}
template<typename T>
void MyBTree<T>::print(std::ostream& out) const {
    print_LPR_nonrecursive(out, m_root);
    print_LRP_nonrecursive(out, m_root);
    print_PLR_nonrecursive(out, m_root);
}                                                                                                                                                                
template<typename T>
void MyBTree<T>::print_PLR_nonrecursive(std::ostream& out, MyBTree<T>::Node* node) const {
    out << "PLR: ";
    if (node == nullptr) {
        return;
    }
    std::stack<MyBTree<T>::Node*> st;
    st.push(node);
    while (!st.empty()) {
        node = st.top();
        st.pop();
        out << node->m_data << " ";
        if (node->m_right != nullptr) {
            st.push(node->m_right);
        }
        if (node->m_left != nullptr) {
            st.push(node->m_left);
        }
    }
}                                                                                                                                  
template<typename T>
void MyBTree<T>::print_LPR_nonrecursive(std::ostream& out, MyBTree<T>::Node* node) const {
    out << "LPR: ";
    if (node == nullptr) {
        return;
    }
    auto pre = node;
    std::stack<MyBTree<T>::Node*> st;
    while (pre != nullptr || !st.empty()) {
        if (pre != nullptr) {
            st.push(pre);
            pre = pre->m_left;
        } else {
            auto topNode = st.top();
            st.pop();
            out << topNode->m_data << " ";
            pre = topNode->m_right;
        }
    }
}
template<typename T>
void MyBTree<T>::print_LRP_nonrecursive(std::ostream& out, Node* node) const {
    out << "LRP: ";
    if (node == nullptr) {
        return;
    }
    auto pre = node;
    auto last = node;
    last = nullptr;
    std::stack<MyBTree<T>::Node*> st;
    while (pre != nullptr || !st.empty()) {
        if (pre != nullptr) {
            st.push(pre);
            pre = pre->m_left;
        } else {
            auto topNode = st.top();
            if (topNode->m_right != nullptr && topNode->m_right != last) {
                pre = topNode->m_right;
            } else {
                st.pop();
                out << topNode->m_data << " ";
                last = topNode;
            }
        }
    }
}
template<typename T>
int MyBTree<T>::max_length_between_node() const {
    if (empty()) {
        return 0;
    }
    int max_length = 0;
    std::stack<MyBTree<T>::Node*> st;
    st.push(m_root);
    while (!st.empty()) {
        auto node = st.top();
        st.pop();
        max_length = std::max(max_length, high(node->m_left) + high( node->m_right));
        if (node->m_left != nullptr) {
            st.push(node->m_left);
        }
        if (node->m_right != nullptr) {
            st.push(node->m_right);
        }
    }
    return max_length;
}
template<typename T>
int MyBTree<T>::high() const {
    return high(m_root);
}
template<typename T>
bool MyBTree<T>::equal(const MyBTree& other) const {
    return equal(m_root, other.m_root);
}
template<typename T>
int MyBTree<T>::count_node(const MyBTree<T>::Node* ptree) const {
    if (ptree == nullptr) {
        return 0;
    } else {
        return 1 + count_node(ptree->m_left) + count_node(ptree->m_right);
    }
}
template<typename T>
typename MyBTree<T>::Node* MyBTree<T>::maxmum(MyBTree<T>::Node* node) const {
    if (node == nullptr) {
        std::runtime_error("maxmum in empty node");
    }
    while (node->m_right != nullptr) {
        node = node->m_right;
    }
    return node;
}
template<typename T>
typename MyBTree<T>::Node* MyBTree<T>::minmum(MyBTree<T>::Node* node) const {
    if (node == nullptr) {
        std::runtime_error("minmum in empty node");
    }
    while (node->m_left != nullptr) {
        node = node->m_left;
    }
    return node;
}
template<typename T>
int MyBTree<T>::high(const MyBTree<T>::Node* node) const {
    if (node == nullptr) {
        return 0;
    } else {
        return std::max(high(node->m_left), high(node->m_right)) + 1; 
    }
}
template<typename T>
bool MyBTree<T>::equal(const MyBTree<T>::Node* lhs, const MyBTree<T>::Node* rhs) const {
    if (lhs == nullptr && rhs == nullptr) {
        return true;
    }
    if (is_leaf_node_equal(lhs, rhs)) {
        return true;
    }
    if (lhs != nullptr && rhs != nullptr && lhs->m_data == rhs->m_data) {
        return equal(lhs->m_left, rhs->m_left) && equal(lhs->m_right, rhs->m_right);
    }
    return false;
}
template<typename T>
bool MyBTree<T>::is_node_leaf(const MyBTree<T>::Node* node) const {
    return node != nullptr && node->m_left == nullptr && node->m_right == nullptr;
}
template<typename T>
bool MyBTree<T>::is_leaf_node_equal(const MyBTree<T>::Node* lhs, const MyBTree<T>::Node* rhs) const {
    if (is_node_leaf(lhs) && is_node_leaf(rhs)) {
        return lhs->m_data == rhs->m_data;
    }
    return false;
}
template<typename T>
void MyBTree<T>::copy(const MyBTree& other) {
    if (this == &other) {
        return;
    }
    clear();
    m_size = other.m_size;
    copy_node(m_root, nullptr, other.m_root);
}
template<typename T>
void MyBTree<T>::copy_node(MyBTree<T>::Node*& dest, MyBTree<T>::Node* dest_parent, const MyBTree<T>::Node* from) {
    if (from == nullptr) {
        return;
    }
    dest = new MyBTree<T>::Node(from->m_data);
    dest->m_parent = dest_parent;
    copy_node(dest->m_left, dest, from->m_left);
    copy_node(dest->m_right, dest, from->m_right);
}
template class MyBTree<int>;
