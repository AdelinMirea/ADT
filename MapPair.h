template <class T>
class Pair{
    private:
        int key;
        T value;
    public:
        Pair();
        Pair(int Key, T Value);
        void setKey(int Key);
        void setValue(T Value);
        int getKey();
        T getValue();
        bool operator>(const Pair<T>& ot);
        bool operator>=(const Pair<T>& ot);
        bool operator<(const Pair<T>& ot);
        bool operator<=(const Pair<T>& ot);
};

template <class T>
Pair<T>::Pair(){
    key = -1;
}

template <class T>
Pair<T>::Pair(int Key, T Value){
    key = Key;
    value = Value;
}

template <class T>
void Pair<T>::setKey(int Key){
    key = Key;
}

template <class T>
void Pair<T>::setValue(T Value){
    value = Value;
}

template <class T>
int Pair<T>::getKey(){
    return key;
}

template <class T>
T Pair<T>::getValue(){
    return value;
}

template <class T>
bool Pair<T>::operator<(const Pair<T>& ot){
    if(this.key < ot.key){
        return true;
    }else{
        return false;
    }
}
template <class T>
bool Pair<T>::operator<=(const Pair<T>& ot){
    if(this.key <= ot.key){
        return true;
    }else{
        return false;
    }
}
template <class T>
bool Pair<T>::operator>(const Pair<T>& ot){
    if(this.key > ot.key){
        return true;
    }else{
        return false;
    }
}
template <class T>
bool Pair<T>::operator>=(const Pair<T>& ot){
    if(this.key >= ot.key){
        return true;
    }else{
        return false;
    }
}
