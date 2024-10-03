#include <iostream>
#include <vector>
using namespace std;

// ���㷽������ʽ����ֵ
int intDet_Solve(vector<vector<int>>, int);

int main()
{
    int n; // ����ʽ�Ľ���
    cout << "����������ʽ����:";
    cin >> n;

    // ����n x n�Ķ�ά������ʾ����ʽ����ʼ��Ϊ0
    vector<vector<int>> Determinant(n, vector<int>(n, 0));

    cout << "����������ʽ:" << endl;

    // ��������ʽԪ��
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Determinant[i][j];
        }
    }

    // ����������������ʽ��⺯��
    cout << endl << "�����:" << intDet_Solve(Determinant, n);

    return 0;
}

// �ݹ��������ʽ��ֵ��Determinant������ʽ��n�������
int intDet_Solve(vector<vector<int>> Determinant, int n)
{
    int ans = 0; // �洢����ʽ��ֵ
    int a;       // ���ڱ�������Ԫ�صķ��ŵ���ֵ
    vector<vector<int>> LDeterminant = Determinant; // ����ԭʼ����ʽ����

    // �������Ϊ1��ֱ�ӷ�������ʽΨһԪ��
    if (n == 1) {
        return Determinant[0][0];
    }

    // ������һ�е�ÿ��Ԫ�أ������Ԫ�ض�Ӧ�Ĵ�������ʽ
    for (int i = 0; i < n; i++) {
        Determinant = LDeterminant; // �ָ�����ʽ

        // ����i����ż��ȷ����ǰԪ�صķ���
        if (i % 2 == 1) {
            a = -Determinant[0][i]; // ����λ�ã�����Ϊ��
        }
        else {
            a = Determinant[0][i];  // ż��λ�ã�����Ϊ��
        }

        // ɾ����ǰ��i��Ԫ�أ����Ƴ���һ�У��γ��Ӿ���
        for (int j = 1; j < n; j++) {
            Determinant[j].erase(Determinant[j].begin() + i); // ɾ����
        }
        Determinant.erase(Determinant.begin()); // ɾ����һ��

        // �ݹ�����Ӿ��������ʽ���ۼӽ��
        ans += a * intDet_Solve(Determinant, n - 1);
    }

    // �������ռ��������ʽֵ
    return ans;
}
