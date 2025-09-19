#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("ratings.txt");       // 1) 打开文件
    if (!fin) {                        // 2) 打开失败就报错返回
        cerr << "Cannot open ratings.txt\n";
        return 1;
    }

    int x;                             // 3) 读一个数字看看
    fin >> x;
    cout << "First number: " << x << '\n';

    fin.close();                       // 4) 关文件
    return 0;
}