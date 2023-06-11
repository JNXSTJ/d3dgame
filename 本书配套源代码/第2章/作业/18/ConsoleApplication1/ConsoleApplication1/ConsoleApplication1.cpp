#include <iostream>
#include <array>
using namespace std;

template <typename T, size_t N, size_t M>
std::array<std::array<T, N>, M> 
Transpose(std::array<std::array<T, M>, N> array)
{
    std::array<std::array<T, N>, M> ret;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ret[j][i] = array[i][j];
        }
    }
    return ret;
}

template <typename T, size_t N, size_t M>
void PrintArray(std::array<std::array<T, M>, N> array)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << endl;
    }
}


int main()
{
    std::array<std::array<float, 4>, 3> a = { {1, 2,3, 4, 5, 6, 7, 8, 9, 10, 11, 12, } };
    PrintArray(a);
    auto ret = Transpose(a);
    PrintArray(ret);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
