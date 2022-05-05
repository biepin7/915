# Disjoint Sets 并查集

并查集

## ADT

对并查集来说，最为基础的操作只有两个：

- onnect(x, y): Connects x and y.

- isConnected(x, y): Returns true if x and y are connected. Connections can be transitive, i.e. they don’t need to be direct.

|         |                        |                                       |
| ------- | ---------------------- | ------------------------------------- |
|         | UF（int N）            | 初始化 N 个触点                       |
| void    | union(int p,int q)     | 在 p 和 q 直接添加一条连接            |
| int     | find（int p）          | p 所在分量的标示符                    |
| boolean | connected(int p,int q) | 若 p 和 q 存在于同一个分量则返回 true |
| int     | count()                | 连通分量的数量                        |

## 刷题用模板 （已优化版本）

### 朴素并查集

```

    int p[N]; //存储每个点的祖宗节点

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    // 合并a和b所在的两个集合：
    p[find(a)] = find(b);
```

### 例题 ：ACWING 836. 合并集合

刷题链接： https://www.acwing.com/problem/content/838/

一共有 nn 个数，编号是 1∼n1∼n，最开始每个数各自在一个集合中。

现在要进行 mm 个操作，操作共有两种：

1. `M a b`，将编号为 aa 和 bb 的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
2. `Q a b`，询问编号为 aa 和 bb 的两个数是否在同一个集合中；

#### 输入格式

第一行输入整数 nn 和 mm。

接下来 mm 行，每行包含一个操作指令，指令为 `M a b` 或 `Q a b` 中的一种。

#### 输出格式

对于每个询问指令 `Q a b`，都要输出一个结果，如果 aa 和 bb 在同一集合内，则输出 `Yes`，否则输出 `No`。

每个结果占一行。

#### 数据范围

$1≤n,m≤10^5$

#### 输入样例：

```
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
```

#### 输出样例：

```
Yes
No
Yes
```

```
#include "iostream"
using namespace std;

const int N = 100010;

int p[N]; 

int n,m;

int find(int x) // return x的root + 路径压缩
{
    if(p[x]!= x) p[x] = find(p[x]);
    return p[x];
    
    // return p[x] == x ? x : p[x] = find(p[x]); // 方便记忆
}

int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    
    while (m -- ){
        // char op[2];
        char c;
        int a,b;
        // cin >>op>>a>>b;
        cin >>c>>a>>b;
        
        // if(op[0] == 'M') p[find(a)] = find(b); // OP[0]是C处理的时候的写法，不作深究
        if(c == 'M') p[find(a)] = find(b);
        else {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        
    }
    return 0;
}
```

