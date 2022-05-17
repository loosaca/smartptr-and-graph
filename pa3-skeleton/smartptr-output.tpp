// TODO: Implement the output operator<< for SmartPtr
template <typename T>
std::ostream& operator<<(std::ostream& os, const SmartPtr<T>& sp){
    if(sp.is_null())
        os << "SmartPtr()";
    else{
        // cout<<endl;
        // cout <<  sp.count<<endl;
        // // if(sp.count == NULL)
        //     cout<<" L";
        os <<  "SmartPtr("<< *sp<<","<< *(sp.count)<< ")";
    }
    return os;
}
