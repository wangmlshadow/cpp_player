#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <stack>

// 二叉查找树
template<typename T>
class MyBTree
{
    class Node;
public:
    MyBTree() :m_root(nullptr), m_size(0) { std::cout << "init with null" << std::endl; }
    MyBTree(const std::vector<T>& from);
    MyBTree(const MyBTree& from);
    MyBTree& operator= (const MyBTree& from);
    ~MyBTree() { clear(); }
public:
    bool insert(const T& data);
    bool empty() const { return (nullptr == m_root); }
    bool exists(const T& data) const;
    void clear();
    int size() const { return m_size; }
    T minmum() const;
    T maxmum() const;
    friend std::ostream& operator<<(std::ostream& out, const MyBTree& tree);
    void print(std::ostream& out) const;
    void print_PLR_nonrecursive(std::ostream& out, Node* node) const;
    void print_LPR_nonrecursive(std::ostream& out, Node* node) const;
    void print_LRP_nonrecursive(std::ostream& out, Node* node) const;
    int max_length_between_node() const;
    int high() const;
    bool operator==(const MyBTree& other) const { return equal(other); }
    bool operator!=(const MyBTree& other) const { return !equal(other); }
    bool equal(const MyBTree& other) const;
private:
    void print_MyBTree(std::ostream&, const Node* bt, int depth) const;
    int count_node(const Node* ptree) const;
    Node* maxmum(Node* node) const;
    Node* minmum(Node* node) const;
    int high(const Node* node) const;
    bool equal(const Node* lhs, const Node* rhs) const;
    bool is_node_leaf(const Node* node) const;
    bool is_leaf_node_equal(const Node* lhs, const Node* rhs) const;
    void copy(const MyBTree& other);
    void copy_node(Node*& dest, Node* dest_parent, const Node* from);
private:
    class Node {
    public:
        friend class MyBTree;
        Node() :m_data(T()), m_parent(NULL), m_left(NULL), m_right(NULL) {}
        Node(const T& t) :m_data(t), m_parent(NULL), m_left(NULL), m_right(NULL) {}
    private:
        T m_data;
        Node* m_parent;
        Node* m_left;
        Node* m_right;
    };

private:
    Node* m_root;//OK
    int m_size = 0;
};
