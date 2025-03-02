/*
* 穷举日期拼图
* 拼图板：(9 * 6)
* ______________________________
* |JAN  FEB  MAR  APR  MAY  JUN|
* |JUL  AUG  SEP  OCT  NOV  DEC|
* | 1    2    3    4    5    6 |
* | 7    8    9   10   11   12 |
* |13   14   15   16   17   18 |
* |19   20   21   22   23   24 |
* |25   26   27   28   29   30 |
* |31             MON  TUER WED|
* |          THUR FRI  SAT  SUN|
* ------------------------------
拼图片：
#
#####

#
###
# #

#
##
##

 #
 #
####

##
 ###

#
#
####

#
####

 #
 ###
##

 #
#####

*/

#include<iostream>
#include<vector>
#include<queue>

// 定义一个表示拼图块的类
class Piece
{
public:
    int len = 0, hei = 0; // 拼图块的长度和高度
    std::vector<std::vector<int>> Shape; // 拼图块的形状，用二维数组表示

    // 翻转拼图块
    void FlipOver(void);
    // 旋转拼图块
    void Rotate(void);
    // 设置拼图块的长度和高度
    void Set_lh(void);
};

// 翻转拼图块的实现
void Piece::FlipOver(void)
{
    std::vector<std::vector<int>> Tem = Shape; // 创建一个临时数组存储原始形状
    for (int i = 0; i < hei; i++) {
        for (int j = 0; j < len; j++) {
            Shape[i][j] = Tem[i][len - j - 1]; // 沿垂直轴翻转形状
        }
    }
}

// 旋转拼图块的实现
void Piece::Rotate(void)
{
    std::vector<std::vector<int>> Tem(Shape[0].size(), std::vector<int>(Shape.size())); // 创建一个临时数组存储旋转后的形状
    for (int i = 0; i < hei; i++) {
        for (int j = 0; j < len; j++) {
            Tem[j][hei - i - 1] = Shape[i][j]; // 旋转90度
        }
    }
    Shape.swap(Tem); // 更新拼图块的形状
    Set_lh(); // 重新设置长度和高度
}

// 设置拼图块的长度和高度
void Piece::Set_lh(void)
{
    len = Shape[0].size(); // 更新长度
    hei = Shape.size(); // 更新高度
}

// 定义一个表示拼图地图的类
class Map
{
private:
    std::vector<std::vector<int>> map; // 拼图地图，用二维数组表示
    int len = 0, hei = 0; // 地图的长度和高度
    Piece Puz[9]; // 存储9个拼图块

public:
    // 构造函数，初始化地图和拼图块
    Map();
    // 显示地图
    void ShowMap(void) const;
    // 在地图上放置一个单元格
    bool PlaceCell(int x, int y, int N);
    // 在地图上放置日期信息
    bool PlaceDate(int mon, int day, int wek);
    // 在地图上放置一个拼图块
    bool PlacePiece(int x, int y, int p);
    // 移除一个拼图块
    void RemoveP(int P);
    // 解决拼图问题
    bool SOLVE(int P);
    // 检查地图是否满足条件
    bool Check(void) const;
};

// 构造函数的实现
Map::Map()
{
    map.resize(9, std::vector<int>(6, 0)); // 初始化地图为9x6的二维数组，初始值为0
    len = 6; // 设置地图长度
    hei = 9; // 设置地图高度

    // 初始化9个拼图块的形状
    Puz[0].Shape.resize(2, std::vector<int>(5, 0));
    Puz[0].Set_lh();
    Puz[0].Shape = {
        {1,0,0,0,0},
        {1,1,1,1,1}
    };
    Puz[1].Shape.resize(3, std::vector<int>(3, 0));
    Puz[1].Set_lh();
    Puz[1].Shape = {
        {2,0,0},
        {2,2,2},
        {2,0,2}
    };
    Puz[2].Shape.resize(3, std::vector<int>(2, 0));
    Puz[2].Set_lh();
    Puz[2].Shape = {
        {3,0},
        {3,3},
        {3,3}
    };
    Puz[3].Shape.resize(3, std::vector<int>(4, 0));
    Puz[3].Set_lh();
    Puz[3].Shape = {
        {0,4,0,0},
        {0,4,0,0},
        {4,4,4,4}
    };
    Puz[4].Shape.resize(2, std::vector<int>(4, 0));
    Puz[4].Set_lh();
    Puz[4].Shape = {
        {5,5,0,0},
        {0,5,5,5}
    };
    Puz[5].Shape.resize(3, std::vector<int>(4, 0));
    Puz[5].Set_lh();
    Puz[5].Shape = {
        {6,0,0,0},
        {6,0,0,0},
        {6,6,6,6}
    };
    Puz[6].Shape.resize(2, std::vector<int>(4, 0));
    Puz[6].Set_lh();
    Puz[6].Shape = {
        {7,0,0,0},
        {7,7,7,7}
    };
    Puz[7].Shape.resize(3, std::vector<int>(4, 0));
    Puz[7].Set_lh();
    Puz[7].Shape = {
        {0,8,0,0},
        {0,8,8,8},
        {8,8,0,0}
    };
    Puz[8].Shape.resize(2, std::vector<int>(5, 0));
    Puz[8].Set_lh();
    Puz[8].Shape = {
        {0,9,0,0,0},
        {9,9,9,9,9}
    };
}

// 在地图上放置一个单元格
bool Map::PlaceCell(int x, int y, int N)
{
    if (map[y][x] != 0 && N != 0) { // 如果该位置已被占用且要放置的值不为0，返回false
        return false;
    }
    map[y][x] = std::max(N, map[y][x]); // 放置单元格，取较大值
    return true;
}

// 在地图上放置日期信息
bool Map::PlaceDate(int mon, int day, int wek)
{
    if (mon < 1 || mon > 12 || day < 1 || day > 31 || wek < 1 || wek > 7) // 检查日期是否合法
        return false;
    PlaceCell((--mon) % 6, (int)(mon / 6), 10); // 放置月份信息
    PlaceCell((--day) % 6, (int)(day / 6) + 2, 10); // 放置日期信息
    PlaceCell(wek % 4 + 2, (int)(wek / 4) + 7, 10); // 放置星期信息
}

// 在地图上放置一个拼图块
bool Map::PlacePiece(int x, int y, int P)
{
    if (x + Puz[P - 1].len - 1 > len || y + Puz[P - 1].hei - 1 > hei) // 检查拼图块是否超出地图范围
        return false;
    for (int i = 0; i < Puz[P - 1].hei; i++) {
        for (int j = 0; j < Puz[P - 1].len; j++) {
            if (!PlaceCell(x + j, y + i, Puz[P - 1].Shape[i][j])) { // 放置拼图块的每个单元格
                RemoveP(P); // 如果放置失败，移除已放置的部分
                return false;
            }
        }
    }
    return true;
}

// 移除一个拼图块
void Map::RemoveP(int P)
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 6; j++) {
            if (map[i][j] == P) map[i][j] = 0; // 将拼图块的单元格值设置为0
        }
    }
}

// 显示地图
void Map::ShowMap(void) const
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << map[i][j] % 10; // 输出地图的每个单元格值
        }
        std::cout << std::endl;
    }
}

// 解决拼图问题
// 回溯算法，慢的吓人，55min找一个解
bool Map::SOLVE(int P)
{
    std::system("cls"); // 清屏
    ShowMap(); // 显示当前地图状态
    if (P > 9) return true; // 如果所有拼图块都已放置，返回true
    Piece original = Puz[P - 1]; // 保存当前拼图块的原始状态
    for (int flip = 0; flip <= 1; flip++) { // 遍历翻转状态
        if (flip) Puz[P - 1].FlipOver(); // 翻转拼图块
        Piece temp = Puz[P - 1]; // 保存翻转后的状态
        for (int rotate = 0; rotate < 4; rotate++) { // 遍历旋转状态
            Puz[P - 1] = temp; // 恢复翻转后的状态
            for (int r = 0; r < rotate; r++) {
                Puz[P - 1].Rotate(); // 旋转拼图块
            }
            int pieceHei = Puz[P - 1].hei; // 获取拼图块的高度
            int pieceLen = Puz[P - 1].len; // 获取拼图块的长度
            for (int y = 0; y <= hei - pieceHei; y++) { // 遍历放置位置
                for (int x = 0; x <= len - pieceLen; x++) {
                    if (PlacePiece(x, y, P)) { // 尝试放置拼图块
                        if (!Check()) { // 检查放置后是否满足条件
                            RemoveP(P); // 如果不满足，移除拼图块
                            continue;
                        }
                        if (SOLVE(P + 1)) { // 递归解决下一个拼图块
                            return true;
                        }
                        RemoveP(P); // 如果递归失败，移除拼图块
                    }
                }
            }
        }
        Puz[P - 1] = original; // 恢复原始状态
    }
    return false; // 如果所有尝试都失败，返回false
}

// 检查地图是否有空间小于4的空
// 广度优先搜索
bool Map::Check(void) const
{
    int dy[4] = { 1, -1, 0, 0 }; // 定义上下左右的偏移量
    int dx[4] = { 0, 0, 1, -1 };
    std::vector<std::vector<int>> m = map; // 复制地图
    for (int i = 0; i < hei; i++) {
        for (int j = 0; j < len; j++) {
            if (m[i][j] == 0) { // 如果发现空单元格
                std::queue<std::pair<int, int>> island; // 使用队列进行广度优先搜索
                island.push({ i, j }); // 将空单元格加入队列
                m[i][j] = 1; // 标记为已访问
                int check = 1; // 记录空区域的大小
                while (!island.empty()) {
                    int y = island.front().first; // 获取队列中的单元格坐标
                    int x = island.front().second;
                    island.pop();
                    check++; // 空区域大小加1
                    for (int d = 0; d < 4; d++) { // 遍历上下左右
                        int ny = std::max(std::min(hei - 1, y + dy[d]), 0); // 计算相邻单元格的坐标
                        int nx = std::max(std::min(len - 1, x + dx[d]), 0);
                        if (m[ny][nx] == 0) { // 如果相邻单元格为空
                            m[ny][nx] = 1; // 标记为已访问
                            island.push({ ny, nx }); // 加入队列
                        }
                    }
                }
                if (check < 5) return false; // 如果空区域小于5，返回false
            }
        }
    }
    return true; // 如果所有空区域都满足条件，返回true
}

// 主函数
int main()
{
    Map Puzzle; // 创建一个拼图地图对象
    int m, d, w; // 定义月份、日期和星期的变量
    std::cout << "Input Date(Month, Day, Week)(int):"; // 提示用户输入日期
    std::cin >> m >> d >> w; // 输入日期
    Puzzle.PlaceDate(m, d, w); // 在地图上放置日期信息
    Puzzle.SOLVE(1); // 解决拼图问题
    std::system("cls"); // 清屏
    Puzzle.ShowMap(); // 显示最终的地图
    return 0;
}
