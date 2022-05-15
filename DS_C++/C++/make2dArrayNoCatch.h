// create a 2D array but do not catch exception thrown
// when new fails to allocate sufficient memory

#ifndef make2dArrayNoCatch_
#define make2dArrayNoCatch_

using namespace std;

template <class T>
void make2dArray(T ** &x, int numberOfRows, int numberOfColumns)
{
   x = new T * [numberOfRows];

   for (int i = 0; i < numberOfRows; i++)
      x[i] = new T [numberOfColumns];
}

#endif

// try
// {
//     make2dArray(x, r, c);
// }
// catch(const std::exception& e)
// {
//     std::cerr << e.what() << '\n';
//     cerr<<"Could not crete x"<<endl;
//     exit(1);
// }

