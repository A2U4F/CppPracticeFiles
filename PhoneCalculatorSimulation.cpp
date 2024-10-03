#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// 计算器函数，输入一个字符向量（包含运算式），返回计算结果
double Calculator(vector<char>);

// 删除输入表达式中多余的'0'字符（起始时用于填充字符向量的0）
void Delete0inString(vector<char>&);

int main()
{
    // 使用do-while循环来确保程序持续运行
    do {
        vector<char> str = { 0 }; // 初始化字符向量，初始值为0
        cout << "请输入算式：" << endl;

        // 循环读取用户输入的字符，直到遇到'='
        while (str.back() != '=') {
            char i;
            cin >> i;
            str.push_back(i); // 将输入字符加入向量中
        }

        // 删除字符向量中的初始'0'
        Delete0inString(str);

        // 打印处理后的表达式
        for (int i = 0; i < str.size(); i++) {
            cout << str[i];
        }

        // 调用计算器函数并输出结果
        cout << Calculator(str) << endl;
    } while (1); // 无限循环，保持程序持续运行

    return 0;
}

// 计算器函数，接收表达式向量，返回计算结果
double Calculator(vector<char> str)
{
    stack<double> stk; // 定义用于保存操作数的栈
    double num = 0;    // 当前数字
    char sgn = '+';    // 当前符号，初始为加号
    bool frac = false; // 用于检测小数点
    int fraction = 0;  // 小数部分的位数

    // 遍历表达式字符向量
    for (int i = 0; i < str.size(); i++) {
        // 如果当前字符是数字
        if (isdigit(str[i])) {
            num = num * 10 + (str[i] - '0'); // 构建数字
            if (frac) { // 如果遇到小数点，记录小数位数
                fraction++;
            }
        }
        // 如果遇到小数点
        if (str[i] == '.') {
            frac = true; // 标记小数点已遇到
        }
        // 如果遇到左括号，处理括号内的表达式
        if (str[i] == '(') {
            // 找到与左括号对应的右括号
            int j = i + 1, bracketCount = 1;
            while (j < str.size() && bracketCount > 0) {
                if (str[j] == '(') bracketCount++;
                if (str[j] == ')') bracketCount--;
                j++;
            }

            // 递归调用Calculator计算括号内的内容
            vector<char> Tstr(str.begin() + i + 1, str.begin() + j - 1);
            num = Calculator(Tstr);

            // 更新i至右括号后
            i = j - 1;
        }

        // 如果遇到运算符或者已到达表达式末尾
        if ((!isdigit(str[i]) && str[i] != '.') || i == str.size() - 1) {
            double last;

            // 处理小数
            while (fraction > 0) {
                num /= 10;
                fraction--;
            }

            // 根据前一个符号执行相应的操作
            switch (sgn)
            {
            case '+': // 加法
                stk.push(num);
                break;
            case '-': // 减法
                stk.push(-num);
                break;
            case '*': // 乘法
                last = stk.top();
                stk.pop();
                stk.push(last * num);
                break;
            case '/': // 除法
                last = stk.top();
                stk.pop();
                stk.push(last / num);
                break;

/*          case '%':
*               last = stk.top();
*               stk.pop();
*               stk.push(last * 0.01);
*               break;
*/

            default:
                break;
            }

            // 处理百分号操作
            if (str[i] == '%') {
                double res = 0;
                stk.pop(); // 弹出栈顶元素
                if (stk.empty()) {
                    stk.push(num * 0.01); // 处理单独的百分号
                }
                else {
                    // 如果栈不为空，将结果按百分号处理
                    while (!stk.empty()) {
                        res += stk.top();
                        stk.pop();
                    }
                    stk.push(res);
                    stk.push(res * num * 0.01); // 百分号处理
                }
            }

            // 更新当前符号并重置变量
            sgn = str[i];
            num = 0;
            frac = false;
            fraction = 0;
        }
    }

    // 将栈中的所有数相加，得到最终结果
    double ans = 0;
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }

    return ans;
}

// 删除输入字符向量中初始的'0'字符
void Delete0inString(vector<char>& str)
{
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 0) { // 如果遇到'0'，删除它
            str.erase(str.begin() + i);
        }
    }
}
