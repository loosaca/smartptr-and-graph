// TODO: Implement the member functions of Node (Part (B), except the output operator)
//             and the graph operations (Part (C))
template <typename T>
Node<T>::Node(const T &val) : val(val), capacity(0), size_p(0), out(nullptr)
{
}
template <typename T>
Node<T>::Node(const Node<T> &that) : Node(that.val)
{
}
template <typename T>
Node<T>::~Node()
{
    if (out)
    {
        delete[] out;
    }
}
template <typename T>
T &Node<T>::operator*()
{
    return val;
}
template <typename T>
const T &Node<T>::operator*() const
{
    return val;
}
template <typename T>
unsigned int Node<T>::degree() const
{
    return capacity;
}
template <typename T>
unsigned int Node<T>::size() const
{
    return size_p;
}
template <typename T>
SmartPtr<Node<T>> Node<T>::operator[](unsigned int i) const
{
    if (!out[i].is_null())
        return out[i];
    else
        return SmartPtr<Node<T>>();
}
template <typename T>
void Node<T>::add(SmartPtr<Node<T>> n)
{
    if (!n.is_null())
    {

        SmartPtr<Node<T>> *temp;

        if (size_p++ % init_capacity == 0)
        {
            temp = new SmartPtr<Node<T>>[size_p + init_capacity];
            for (int i = 0; i < size_p - 1; i++)
                temp[i] = out[i];
            if (out)
                delete[] out;
            out = temp;
        }
        capacity++;
        out[size_p - 1] = n;
    }
}
template <typename T>
void Node<T>::remove(SmartPtr<Node<T>> n)
{
    int i;
    for (i = 0; i < size_p; i++)
    {
        if (n.operator->() == out[i].operator->())
            out[i].unset(), size_p = i == size_p - 1 ? size_p - 1 : size_p;

    }
    capacity--;
}
template <typename T>
bool Node<T>::exists(SmartPtr<Node<T>> n) const
{
    if (!n.is_null())
    {
        for (int i = 0; i < size_p; i++)
        {
            if (out[i].operator->() == n.operator->())
                return true;
        }
    }
    return false;
}
template <typename T>
SmartPtr<Node<T>> Node<T>::find(T val) const
{
    for (int i = 0; i < size_p; i++)
    {
        if (out[i]->val == val)
            return out[i];
    }
    return SmartPtr<Node<T>>();
}

template <typename T>
SmartPtr<Node<T>> new_node(const T &val)
{
    return SmartPtr<Node<T>>(val);
}
template <typename T>
void remove_node(SmartPtr<Node<T>> n)
{
    for (int i = 0; i < n->size(); i++)
    {
        if (!(*n)[i].is_null())
        {
            remove_edge(n, (*n)[i]);
        }
    }
}
template <typename T>
void add_edge(SmartPtr<Node<T>> n1, SmartPtr<Node<T>> n2)
{
    if (n1.is_null() || n2.is_null() || n1 == n2)
        return;
    if (!n1->exists(n2))
    {
        n1->add(n2);
    }
    if (!n2->exists(n1))
    {
        n2->add(n1);
    }
}
template <typename T>
void remove_edge(SmartPtr<Node<T>> n1, SmartPtr<Node<T>> n2)
{
    if (n1.is_null() || n2.is_null())
        return;
    if (n1->exists(n2))
        n1->remove(n2);
    if (n2->exists(n1))
        n2->remove(n1);
}
template <typename T>
void remove_graph(SmartPtr<Node<T>> root)
{
    for (int i = 0; i < root->size(); i++)
    {
        remove_node((*root)[i]);
    }
}
struct cmp
{
    template <typename T>
    bool operator()(const SmartPtr<Node<T>> a, const SmartPtr<Node<T>> b) const
    {
        return **a > **b;
    }
};

template <typename T>
SmartPtr<Node<T>> rec(SmartPtr<Node<T>> root, T val, set<SmartPtr<Node<T>>, cmp> &s)
{
    if (**root == val)
        return root;

    if (s.find(root) == s.end())
    {

        for (int i = 0; i < root->size(); i++)
        {
            if (s.find(root) == s.end())
            {
                s.insert(root);
            }
            SmartPtr<Node<T>> res = rec((*root)[i], val, s);
            if(!res.is_null())
                return res;
        }
    }
            return SmartPtr<Node<T>>();

}

template <typename T>
SmartPtr<Node<T>> find(SmartPtr<Node<T>> root, T val)
{
    set<SmartPtr<Node<T>>, cmp> s;
    return rec(root, val, s);
}
template <typename T>
bool reachable(SmartPtr<Node<T>> root, SmartPtr<Node<T>> dest) {
    return !find(root, **dest).is_null();
}
// TODO: Implement the output operator<< for Node
// template <typename T>
// std::ostream &operator<<(std::ostream &os, const Node<T> &n)
// {
//     os << "Node(" << n.val << ",{";
//     int i;
//     for (i = 0; i < n.size_p; i++)
//     {
//         if (!n.out[i].is_null())
//         {
//             os << (*(n.out[i])).val;
//             break;
//         }
//     }
//     i++;
//     for (;i < n.size_p; i++)
//         if (!n.out[i].is_null())
//         {
//             cout << ",";
//             os << (*(n.out[i])).val;
//         }
//     os << "})";

//     return os;
// }
