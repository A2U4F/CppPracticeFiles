#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    // 设置控制台代码页为UTF-8，防止中文乱码（仅适用于Windows）
    system("chcp 65001>nul");

    // 定义输入文件流（fi, add）和输出文件流（fo），以及字符串变量
    std::ifstream fi, add;
    std::ofstream fo;
    std::string s;
    std::string addr;

    // 第一步：生成待合并的markdown文件路径列表，写入add.txt
    fo.open("D:\\学习\\知识库\\1.笔记仓库\\日记本\\add.txt", std::ios::out);
    // 循环生成2025年9月1日到9月30日的markdown文件路径
    for (int i = 1; i < 31; i++) {
        fo << "D:\\学习\\知识库\\1.笔记仓库\\日记本\\2025-09-"
           << std::setfill('0') << std::setw(2) << std::to_string(i)
           << ".md"
           << std::endl;
    }
    fo.close();

    // 第二步：创建一个汇总文件2025-09.md，用于合并所有日记内容
    fo.open("D:\\学习\\知识库\\1.笔记仓库\\日记本\\2025-09.md", std::ios::out);
    if (!fo.is_open()) std::cout << "Failed to open file" << std::endl;

    // 打开之前生成的add.txt，读取每个markdown文件路径
    add.open("D:\\学习\\知识库\\1.笔记仓库\\日记本\\add.txt", std::ios::in);
    if (!add.is_open()) std::cout << "broken add" << std::endl;

    // 逐行读取add.txt中的文件路径
    while (std::getline(add, addr)) {
        // 打开单个日记文件
        fi.open(addr, std::ios::in);
        if (!fi.is_open()) std::cout << "Failed to open file:" << addr << std::endl;

        // 在汇总文件中写入分隔符和日期标题（从文件路径中提取日期）
        fo << std::endl << "---" << std::endl;
        fo << "# " << addr.substr(33, 10) << std::endl << std::endl;

        // 同时在控制台输出相同内容，方便查看进度
        std::cout << std::endl << "---" << std::endl;
        std::cout << "# " << addr.substr(33, 10) << std::endl << std::endl;

        // 读取当前日记文件的所有内容，并写入汇总文件和控制台
        while (std::getline(fi, s)) {
            std::cout << s << std::endl;
            fo << s << std::endl;
        }
        fi.close(); // 关闭当前日记文件
    }

    // 关闭文件流
    add.close();
    fo.close();
    return 0;
}
