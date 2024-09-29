#include <iostream>
#include <vector>
using namespace std;

int intDet_Solve(vector<vector<int>> , int);

int main()
{
	int n;
	cout << "请输入行列式阶数:";
	cin >> n;
	vector<vector<int>> Determinant(n, vector<int>(n, 0));
	cout << "请输入行列式:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Determinant[i][j];
		}
	}
	cout << endl << "结果是:" << intDet_Solve(Determinant, n);
	return 0;
}

int intDet_Solve(vector<vector<int>>Determinant, int n)
{
	int ans = 0;
	int a;
	vector<vector<int>> LDeterminant = Determinant;
	if (n == 1) { return Determinant[0][0]; }
	for (int i = 0; i < n; i++) {
		Determinant = LDeterminant;
		if(i%2==1){ a = -Determinant[0][i]; }
		else { a = Determinant[0][i]; }
		for (int j = 1; j < n; j++) {
			Determinant[j].erase(Determinant[j].begin() + i);
		}
		Determinant.erase(Determinant.begin());
		ans+= a * intDet_Solve(Determinant, n - 1);
	}
	return ans;
}

