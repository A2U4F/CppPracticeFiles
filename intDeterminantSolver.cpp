#include <iostream>
#include <vector>
using namespace std;

// 计算方阵（行列式）的值
int intDet_Solve(vector<vector<int>>, int);

int main()
{
    int n; // 行列式的阶数
    cout << "请输入行列式阶数:";
    cin >> n;

    // 创建n x n的二维向量表示行列式，初始化为0
    vector<vector<int>> Determinant(n, vector<int>(n, 0));

    cout << "请输入行列式:" << endl;

    // 输入行列式元素
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Determinant[i][j];
        }
    }

    // 输出结果，调用行列式求解函数
    cout << endl << "结果是:" << intDet_Solve(Determinant, n);

    return 0;
}

// 递归求解行列式的值，Determinant是行列式，n是其阶数
int intDet_Solve(vector<vector<int>> Determinant, int n)
{
    int ans = 0; // 存储行列式的值
    int a;       // 用于保存首行元素的符号调整值
    vector<vector<int>> LDeterminant = Determinant; // 保存原始行列式副本

    // 如果阶数为1，直接返回行列式唯一元素
    if (n == 1) {
        return Determinant[0][0];
    }

    // 遍历第一行的每个元素，计算该元素对应的代数余子式
    for (int i = 0; i < n; i++) {
        Determinant = LDeterminant; // 恢复行列式

        // 根据i的奇偶性确定当前元素的符号
        if (i % 2 == 1) {
            a = -Determinant[0][i]; // 奇数位置，符号为负
        }
        else {
            a = Determinant[0][i];  // 偶数位置，符号为正
        }

        // 删除当前列i的元素，并移除第一行，形成子矩阵
        for (int j = 1; j < n; j++) {
            Determinant[j].erase(Determinant[j].begin() + i); // 删除列
        }
        Determinant.erase(Determinant.begin()); // 删除第一行

        // 递归求解子矩阵的行列式并累加结果
        ans += a * intDet_Solve(Determinant, n - 1);
    }

    // 返回最终计算的行列式值
    return ans;
}
