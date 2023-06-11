// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <array>
#include <cassert>

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


template <typename T, size_t N>
std::array<std::array<float, N - 1>, N - 1>
SubArray(std::array<std::array<T, N>, N>& array, int x, int y)
{
    std::array<std::array<float, N - 1>, N - 1> ret;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == x || j == y) continue;
            ret[i > x ? i - 1 : i][j > y ? j - 1 : j] = array[i][j];
        }
    }
    return ret;
}

template <typename T>
float Determinent(std::array<std::array<T, 2>, 2> array)
{
    return array[0][0] * array[1][1] - array[0][1] * array[1][0];
}

template <typename T>
float Determinent(std::array<std::array<T, 1>, 1> array)
{
    return array[0][0];
}

template <typename T, size_t N>
float Determinent(std::array<std::array<T, N>, N> array)
{
    static_assert(N >= 2 && N <= 4, "N must be between 2 and 4");
	float ret = 0.0f;
    float flag = 1.0f;
    for (int i = 0; i < N; i++)
    {
        auto tmp = SubArray(array, 0, i);
        float v = Determinent(tmp);
        ret += flag * v * array[0][i];
        flag = -flag;
    }
    return ret;
}

template <typename T, size_t N>
std::array<std::array<T, N>, N> Inverse(std::array<std::array<T, N>, N>& array)
{
    std::array<std::array<T, N>, N> C_T;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C_T[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * Determinent(SubArray(array, i, j));
        }
    }
    float det = Determinent(array);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C_T[i][j] /= det;
        }
    }

    return C_T;
}

int main()
{
    std::array<std::array<float, 4>, 4> a = {
        {1.0f, 0.0f, 0.0f, 0.0f, 
         0.0f, 2.0f, 0.0f, 0.0f,
         0.0f, 0.0f, 3.0f, 0.0f,
         0.0f, 0.0f, 0.0f, 4.0f}
    };
    PrintArray(a);
    std::cout << Determinent(a) << endl;
    PrintArray(Inverse(a));
    std::cout << "Hello World!\n";
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
