#include<iostream>
#include<vector>
#include<stack>

using namespace std;

double Calculator(vector<char>);
void Delete0inString(vector<char>&);

int main()
{
	do {
		vector<char> str = { 0 };
		cout << "请输入算式：" << endl;

		while (str.back() != '=') {
			char i;
			cin >> i;
			str.push_back(i);
		}

		Delete0inString(str);

		for (int i = 0; i < str.size(); i++) {
			cout << str[i];
		}
		cout << Calculator(str) << endl;
	}while (1);
	return 0;
}

double Calculator(vector<char> str)
{
    stack<double> stk;
    double num = 0;
    char sgn = '+';
    bool frac = false;
    int fraction = 0;

    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            num = num * 10 + (str[i] - '0');
            if (frac) {
                fraction++;
            }
        }
        if (str[i] == '.') {
            frac = true;
        }
        if (str[i] == '(') {
            // 找到对应的右括号
            int j = i + 1, bracketCount = 1;
            while (j < str.size() && bracketCount > 0) {
                if (str[j] == '(') bracketCount++;
                if (str[j] == ')') bracketCount--;
                j++;
            }

            // 递归计算括号中的内容
            vector<char> Tstr(str.begin() + i + 1, str.begin() + j - 1);
            num = Calculator(Tstr);

            // 将i更新到右括号后
            i = j - 1;
        }

        if ((!isdigit(str[i]) && str[i] != '.') || i == str.size() - 1) {
            double last;
            while (fraction > 0) {
                num /= 10;
                fraction--;
            }
            switch (sgn)
            {
            case '+':
                stk.push(num);
                break;
            case '-':
                stk.push(-num);
                break;
            case '*':
                last = stk.top();
                stk.pop();
                stk.push(last * num);
                break;
            case '/':
                last = stk.top();
                stk.pop();
                stk.push(last / num);
                break;
            default:
                break;
            }
            if (str[i] == '%') {
                double res = 0;
                stk.pop();
                if (stk.empty()) {
                    stk.push(num * 0.01);
                }
                else {
                    while (!stk.empty()) {
                        res += stk.top();
                        stk.pop();
                    }
                    stk.push(res);
                    stk.push(res * num * 0.01);
                }
            }
            sgn = str[i];
            num = 0;
            frac = false;
            fraction = 0;
        }
    }

    double ans = 0;
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }

    return ans;
}


void Delete0inString(vector<char> &str)
{
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 0) { str.erase(str.begin() + i); }
	}
}