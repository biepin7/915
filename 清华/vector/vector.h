typedef int Rank // 秩 
#define DEFAULT_CAPACITY 3 // 默认初始容量 3 ：为了学习设的较小

template <tempname T> class Vector
{
protected:
    Rank _size; // 当前容量
    int _capacity; // 容量
    T* elem; // 数据
public:
    // 构造函数
    Vector(int c = DEFAULT_CAPACITY)  // 默认构造函数
    { 
        _elem = new T[_capacity = c];
        _size = 0;
    }

    Vector(T const *A,Rank lo,Rank hi) // 数组区间复制
    {
        copyFrom(A,lo,hi);
    }

    

    Vector ( int c = DEFAULT_CAPACITY, Rank s = 0, T v = 0 ) //容量为c、规模为s、所有元素初始为v

    // 析构函数
    ~Vector(){delete [] _elem;}
};


