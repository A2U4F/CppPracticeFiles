#include<iostream>
#include<math.h>
#include<Windows.h>
#include<random>
#include<time.h>
#include <list>

using namespace std;

// 函数声明
void Leibniz_formula();     // 莱布尼兹公式求PI
void Piece_of_cycle();      // 使用矩形区域近似圆面积求PI
void Line_of_cycle();       // 使用直线分割圆来求PI
void Random_point();        // 随机点法（蒙特卡罗方法）求PI
void Slid_the_cycle();      // 利用几何变换求PI
void Infinite();            // 无限级数法求PI

int main()
{
    // 设置控制台标题
    SetConsoleTitle(L"made by 王俊艺  version 0.50");
    int col = 10;

    // 菜单驱动程序，让用户选择计算PI的方法
    while (col != 0)
    {
        cout << "选择计算方法" << endl
            << "1......Leibniz_formula" << endl
            << "2......Piece_of_cycle" << endl
            << "3......Line_of_cycle" << endl
            << "4......Random_point" << endl
            << "5......Slid_the_cycle" << endl
            << "6......Infinite" << endl;

        // 用户选择
        cin >> col;
        system("cls"); // 清屏

        // 根据用户选择调用相应的PI计算方法
        switch (col)
        {
        case 1:
            Leibniz_formula();
            break;
        case 2:
            Piece_of_cycle();
            break;
        case 3:
            Line_of_cycle();
            break;
        case 4:
            Random_point();
            break;
        case 5:
            Slid_the_cycle();
            break;
        case 6:
            Infinite();
            break;
        default:
            cout << "I can't find it......" << endl << endl << endl;
        }
    }
    system("pause"); // 暂停，等待用户按键
    return 0;
}

// 莱布尼兹公式计算PI
void Leibniz_formula()
{
    double i = 1.0; // 分母初始值
    double pi = 0.0; // PI的初始值
    double k = 1.0;  // 符号（正负交替）
    double t = 1.0;  // 每项的值
    double c = 1e-8; // 计算精度

    // 根据莱布尼兹公式计算PI，当每项小于精度时停止
    while (fabs(t) >= c)
    {
        pi += t;
        k = -k; // 交替改变符号
        i += 2; // 分母每次加2
        t = k / i;
    }

    pi *= 4; // 最终PI值
    cout << "pi = " << pi << endl
        << "precision = " << c * 10;

    cout << endl << endl << endl;
}

// 使用矩形区域近似圆面积计算PI
void Piece_of_cycle()
{
    double x = 0.0, y = 0.0;
    double c = 0.001; // 步长
    double init = 0, total = 0;
    double pi;

    // 双重循环遍历矩形区域，计算落在圆内的点数
    do {
        do {
            x += c;
            total += 1;
            if (pow(x, 2) + pow(y, 2) <= 100) init += 1; // 判断点是否在圆内
        } while (x <= 10);
        x = 0;
        y += c;
    } while (y <= 10);

    // 使用圆内点与总点的比值计算PI
    pi = 4 * (init / total);
    cout << "pi = " << pi << endl
        << "init = " << init << endl
        << "total = " << total << endl;

    cout << endl << endl << endl;
}

// 使用直线分割圆的方式计算PI
void Line_of_cycle()
{
    double x = 0.0, y = 0.0;
    double c = 0.00001; // 步长
    double init = 0, total = 0, added = 0;
    double pi;

    x += c;
    y += c;
    while (x <= 10) {
        added += 1;
        x += c;
    }

    total = pow(added, 2); // 计算总点数

    x = 10;

    // 计算落在圆内的点数
    while (y <= 10) {
        while (pow(x, 2) + pow(y, 2) >= 100) {
            added -= 1;
            x -= c;
        }
        init += added;
        y += c;
    }

    // 计算PI
    pi = 4 * (init / total);
    cout << "pi = " << pi << endl
        << "init = " << init << endl
        << "total = " << total << endl;

    cout << endl << endl << endl;
}

// 使用随机点方法（蒙特卡罗方法）计算PI
void Random_point()
{
    srand(time(0) * 100 + 56); // 初始化随机数种子

    long long int c = 1000000; // 每次迭代的点数
    long double init = 0;
    long double total = 0;
    double pi = 0.0;

    // 进行100轮模拟，每轮c次点投掷
    for (int timeo = 1; timeo <= 100; timeo++) {
        for (long long int timei = 1; timei <= c; timei++) {
            double x = rand() / static_cast<double>(32767); // 随机生成x坐标
            double y = rand() / static_cast<double>(32767); // 随机生成y坐标
            total += 1;
            if (pow(x, 2) + pow(y, 2) <= 1) init += 1; // 判断点是否在圆内
        }
        system("cls");
        cout << "进度条" << timeo << "%";
    }

    cout << endl;

    // 根据圆内点与总点的比值计算PI
    pi = 4 * (init / total);
    cout << "pi = " << pi << endl
        << "init = " << init << endl
        << "total = " << total;

    cout << endl << endl << endl;
}

// 通过几何变换迭代方式计算PI
void Slid_the_cycle()
{
    double cosrate = 0.50;
    double line = 6;
    double pi = 0.50;

    // 通过迭代几何变换计算PI
    for (int t = 1; t <= 10; t++) {
        cosrate = sqrt((cosrate + 1) / 2);
        line *= sqrt(2 / (cosrate + 1));
        cout << "pi == " << pi * line << endl;
    }

    pi *= line;

    cout << "pi = " << pi << endl;

    cout << endl << endl << endl;
}

// 计算需要的项数
int count(int n)
{
    int i = 1;
    double sum = 0;
    int a, b;
    while (1)
    {
        a = 2 * i + 1;
        b = i;
        sum = sum + log10(a / b);
        i++;
        if (sum > n + 1) {
            return i; // 返回达到所需精度所需的项数
        }
    }
}

// 无限级数法计算PI
void Infinite()
{
    cout << "Please enter the digit you want to calculate:" << endl;
#define NODE_NUM 550
    list<int> num(NODE_NUM, 0); // 初始化链表，存储计算中间值
    list<int> sum(NODE_NUM, 0); // 存储结果
    int print;
    cin >> print;
    int cnt = count(print); // 计算所需项数

    num.front() = 2;
    sum.front() = 2;

    // 迭代计算每一项的值
    for (int i = 1; i <= cnt; ++i)
    {
        int ret = 0;

        for (list<int>::reverse_iterator cur1 = num.rbegin(); cur1 != num.rend(); cur1++)
        {
            int val = *cur1 * i + ret;
            ret = val / 10;
            *cur1 = val % 10;
        }

        ret = 0;

        for (list<int>::iterator cur1 = num.begin(); cur1 != num.end(); cur1++)
        {
            int div = (i << 1) + 1;
            int val = *cur1 + ret * 10;
            *cur1 = val / div;
            ret = val - *cur1 * div;
        }

        ret = 0;

        for (auto cur2 = sum.rbegin(), cur1 = num.rbegin(); cur2 != sum.rend(); cur2++, cur1++)
        {
            int val = *cur1 + *cur2 + ret;
            *cur2 = val % 10;
            ret = val / 10;
        }
    }

    // 输出PI的计算结果
    cout << sum.front() << '.';
    list<int>::iterator it = sum.begin();
    it++;

    int i = 0;
    while (i < print)
    {
        cout << *it;
        it++;
        i++;
    }

    cout << endl << endl << endl;
}
