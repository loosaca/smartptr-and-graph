// TODO: Implement the member functions of SmartPtr (Part (A), except the output operator)

template <typename T>
SmartPtr<T>::SmartPtr() : count(nullptr), ptr(nullptr) {    
}

template <typename T>
SmartPtr<T>::SmartPtr(const T &val)
{
    count = new unsigned int(1);
    ptr = new T(val);
}

template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> &that)
{
    count = that.count;
    ptr = that.ptr;
    ++*count;

}

template <typename T>
void SmartPtr<T>::set(const T &val)
{
    if(count != NULL){
    
        if(--(*count) == 0){
            delete count;
            delete ptr;
            count = nullptr;
            ptr = nullptr;
        }

    }
    ptr = new T(val);
    count = new unsigned int(1);
}

template <typename T>
SmartPtr<T> &SmartPtr<T>::operator=(const SmartPtr<T> &that)
{
    if (count && !--*count)
    {

        delete ptr;
        delete count;
        ptr = nullptr;
        count = nullptr;
    }
    count = that.count;
    ptr = that.ptr;
    if (!that.is_null())
        ++*count;
 
    return *this;
}

template <typename T>
SmartPtr<T>::~SmartPtr()
{
    if (count && --*count == 0){

        delete count;
        delete ptr;
    }
}

template <typename T>
void SmartPtr<T>::unset()
{
    if (!--*count)
    {
        delete count;
    }
    ptr = nullptr;
    count = nullptr;
}

template <typename T>
bool SmartPtr<T>::is_null() const
{
    return count == nullptr;
}

template <typename T>
bool SmartPtr<T>::operator==(const SmartPtr<T> &that) const
{
    return that.operator->() == ptr;
}
template <typename T>
T &SmartPtr<T>::operator*() const
{
    return *ptr;
}

template <typename T>
T *SmartPtr<T>::operator->() const
{
    return ptr;
}
template <typename T>
bool SmartPtr<T>::operator!=(const SmartPtr<T> &that) const
{
    return that.operator->() != ptr;
}
