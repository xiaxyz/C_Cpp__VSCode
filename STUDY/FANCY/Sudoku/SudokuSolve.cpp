/*在 "Sudoku.txt" 中输入数据或直接从控制台输入数据, 0 代表需要解的数据, 1~9 代表题目给的数据, 结果在控制台输出*/
#include "./SudokuVault.cpp"
#include <chrono>

#define SudokuFile "./SudokuFile.txt"

SudokuAll Sudoku_;

void CurrentToXY(int, int &, int &);
bool JudgeUniqueCurrent(int, int);
bool GoThrough(int);

int main(int argc, char *argv[])
{
    clock_t Start_, Finish_;
    std::cout << "选择输入方式(1.从文件中输入 2.从控制台输入):";
    int Case_;
    std::cin >> Case_;
    std::cin.get();
    switch (Case_)
    {
    case 1:
    {
        Sudoku_.ReadFile(SudokuFile); // 从文件中输入数据
        break;
    }
    case 2:
    {
        Sudoku_.ReadConsole(); // 从控制台中输入数据
        break;
    }
    default:
    {
        return -1;
    }
    }
    Start_ = clock();
    GoThrough(0);
    Sudoku_.PrintData();
    Finish_ = clock();
    std::cout << (1.0 * (Finish_ - Start_) / CLOCKS_PER_SEC) << " second" << std::endl;
    std::cout << "calculations completed";
    std::cin.get();
    return 0;
}

/// @brief 将当前编号转换为坐标
/// @param Current0_ 当前编号
/// @param XMark0_ 行标
/// @param YMark0_ 列标
void CurrentToXY(int Current0_, int &XMark0_, int &YMark0_)
{
    XMark0_ = Current0_ % 9;
    YMark0_ = Current0_ / 9;
}
/// @brief 通过坐标判断唯一性
/// @param PointData0_ 数据值
/// @param Current0_ 当前所在编号
/// @return true 唯一 false 不唯一
bool JudgeUniqueCurrent(int PointData0_, int Current0_)
{
    int XMark_;
    int YMark_;
    CurrentToXY(Current0_, XMark_, YMark_);
    int BoxNum_; // 宫格编号
    int RowNum_; // 行编号
    int ColNum_; // 列编号
    BoxNum_ = XMark_ / BLOCK_SIDE + YMark_ / BLOCK_SIDE * ALL_SIDE_BLOCK_COUNT;
    RowNum_ = YMark_;
    ColNum_ = XMark_;
    return Sudoku_.JudgeUnique(PointData0_, BoxNum_, RowNum_, ColNum_);
}
/// @brief 遍历所有点
/// @param Current0_ 当前所在位置
/// @return true 结果可行 false 结果不可行
bool GoThrough(int Current0_)
{
    if (Current0_ == POINT_COUNT)
    {
        return true;
    }
    if (Sudoku_.JudgeModify(Current0_))
    {
        for (int i = 0; i < 9; ++i)
        {
            if (JudgeUniqueCurrent(i + 1, Current0_))
            {
                Sudoku_.SetDataCurrent(Current0_, i + 1);
                if (GoThrough(Current0_ + 1))
                {
                    return true;
                }
            }
        }
        Sudoku_.SetDataCurrent(Current0_, 0);
    }
    else
    {
        if (GoThrough(Current0_ + 1))
        {
            return true;
        }
    }
    return false;
}