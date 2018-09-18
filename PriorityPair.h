template <class T>
class PriorityPair{
    private:
        int priority;
        T value;
    public:
        PriorityPair();
        PriorityPair(int Priority, T Value);
        void setPriority(int Priority);
        void setValue(T Value);
        int getPriority();
        T getValue();
        bool operator>(const PriorityPair<T>& ot);
        bool operator>=(const PriorityPair<T>& ot);
        bool operator<(const PriorityPair<T>& ot);
        bool operator<=(const PriorityPair<T>& ot);
};

template <class T>
PriorityPair<T>::PriorityPair(){
    priority = -1;
}

template <class T>
PriorityPair<T>::PriorityPair(int Priority, T Value){
    priority = Priority;
    value = Value;
}

template <class T>
void PriorityPair<T>::setPriority(int Priority){
    priority = Priority;
}

template <class T>
void PriorityPair<T>::setValue(T Value){
    value = Value;
}

template <class T>
int PriorityPair<T>::getPriority(){
    return priority;
}

template <class T>
T PriorityPair<T>::getValue(){
    return value;
}

template <class T>
bool PriorityPair<T>::operator<(const PriorityPair<T>& ot){
    if(this.priority < ot.priority){
        return true;
    }else{
        return false;
    }
}
template <class T>
bool PriorityPair<T>::operator<=(const PriorityPair<T>& ot){
    if(this.priority <= ot.priority){
        return true;
    }else{
        return false;
    }
}
template <class T>
bool PriorityPair<T>::operator>(const PriorityPair<T>& ot){
    if(this.priority > ot.priority){
        return true;
    }else{
        return false;
    }
}
template <class T>
bool PriorityPair<T>::operator>=(const PriorityPair<T>& ot){
    if(this.priority >= ot.priority){
        return true;
    }else{
        return false;
    }
}
