#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// ����������������һ���ַ���������������ʽ�������ؼ�����
double Calculator(vector<char>);

// ɾ��������ʽ�ж����'0'�ַ�����ʼʱ��������ַ�������0��
void Delete0inString(vector<char>&);

int main()
{
    // ʹ��do-whileѭ����ȷ�������������
    do {
        vector<char> str = { 0 }; // ��ʼ���ַ���������ʼֵΪ0
        cout << "��������ʽ��" << endl;

        // ѭ����ȡ�û�������ַ���ֱ������'='
        while (str.back() != '=') {
            char i;
            cin >> i;
            str.push_back(i); // �������ַ�����������
        }

        // ɾ���ַ������еĳ�ʼ'0'
        Delete0inString(str);

        // ��ӡ�����ı��ʽ
        for (int i = 0; i < str.size(); i++) {
            cout << str[i];
        }

        // ���ü�����������������
        cout << Calculator(str) << endl;
    } while (1); // ����ѭ�������ֳ����������

    return 0;
}

// ���������������ձ��ʽ���������ؼ�����
double Calculator(vector<char> str)
{
    stack<double> stk; // �������ڱ����������ջ
    double num = 0;    // ��ǰ����
    char sgn = '+';    // ��ǰ���ţ���ʼΪ�Ӻ�
    bool frac = false; // ���ڼ��С����
    int fraction = 0;  // С�����ֵ�λ��

    // �������ʽ�ַ�����
    for (int i = 0; i < str.size(); i++) {
        // �����ǰ�ַ�������
        if (isdigit(str[i])) {
            num = num * 10 + (str[i] - '0'); // ��������
            if (frac) { // �������С���㣬��¼С��λ��
                fraction++;
            }
        }
        // �������С����
        if (str[i] == '.') {
            frac = true; // ���С����������
        }
        // ������������ţ����������ڵı��ʽ
        if (str[i] == '(') {
            // �ҵ��������Ŷ�Ӧ��������
            int j = i + 1, bracketCount = 1;
            while (j < str.size() && bracketCount > 0) {
                if (str[j] == '(') bracketCount++;
                if (str[j] == ')') bracketCount--;
                j++;
            }

            // �ݹ����Calculator���������ڵ�����
            vector<char> Tstr(str.begin() + i + 1, str.begin() + j - 1);
            num = Calculator(Tstr);

            // ����i�������ź�
            i = j - 1;
        }

        // �����������������ѵ�����ʽĩβ
        if ((!isdigit(str[i]) && str[i] != '.') || i == str.size() - 1) {
            double last;

            // ����С��
            while (fraction > 0) {
                num /= 10;
                fraction--;
            }

            // ����ǰһ������ִ����Ӧ�Ĳ���
            switch (sgn)
            {
            case '+': // �ӷ�
                stk.push(num);
                break;
            case '-': // ����
                stk.push(-num);
                break;
            case '*': // �˷�
                last = stk.top();
                stk.pop();
                stk.push(last * num);
                break;
            case '/': // ����
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

            // ����ٷֺŲ���
            if (str[i] == '%') {
                double res = 0;
                stk.pop(); // ����ջ��Ԫ��
                if (stk.empty()) {
                    stk.push(num * 0.01); // �������İٷֺ�
                }
                else {
                    // ���ջ��Ϊ�գ���������ٷֺŴ���
                    while (!stk.empty()) {
                        res += stk.top();
                        stk.pop();
                    }
                    stk.push(res);
                    stk.push(res * num * 0.01); // �ٷֺŴ���
                }
            }

            // ���µ�ǰ���Ų����ñ���
            sgn = str[i];
            num = 0;
            frac = false;
            fraction = 0;
        }
    }

    // ��ջ�е���������ӣ��õ����ս��
    double ans = 0;
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }

    return ans;
}

// ɾ�������ַ������г�ʼ��'0'�ַ�
void Delete0inString(vector<char>& str)
{
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 0) { // �������'0'��ɾ����
            str.erase(str.begin() + i);
        }
    }
}





/*          case '%':
*               last = stk.top();
*               stk.pop();
*               stk.push(last * 0.01);
*               break;
*/