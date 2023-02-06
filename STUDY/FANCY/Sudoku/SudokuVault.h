#ifndef _SudokuVault_h_
#define _SudokuVault_h_

#include <vector>
#include <string>

#define BOX_SIDE 3 // 宫格的边长
#define ALL_SIDE 9     // 总边长
#define POINT_COUNT (ALL_SIDE * ALL_SIDE)    // 总点数
#define ALL_SIDE_BOX_COUNT (ALL_SIDE / BOX_SIDE) // 总边长中含有的宫格数
#define BOX_COUNT (ALL_SIDE_BOX_COUNT * ALL_SIDE_BOX_COUNT) // 总宫格数

class SudokuPoint;
class SudokuBox;
class SudokuRow;
class SudokuCol;
class SudokuAll;

// 一个点中的信息
class SudokuPoint
{
public:
    int XMark_; // 行标
    int YMark_; // 列标
    SudokuPoint(int = -1, int = -1, int = 0, bool = true);
    ~SudokuPoint();
    void SetModify(bool);
    bool JudgeModify();
    int GetData();
    void SetData(int = 0);

protected:
    bool Modify_; // 可修改性
    int Data_; // 数据
};

// 一个宫格中的信息
class SudokuBox
{
public:
    SudokuBox();
    ~SudokuBox();
    friend class SudokuAll;

protected:
    std::vector<std::vector<SudokuPoint *>> Box_; // 宫格编号
};

// 一行中的信息
class SudokuRow
{
public:
    SudokuRow();
    ~SudokuRow();
    friend class SudokuAll;

protected:
    std::vector<SudokuPoint *> Row_; // 行编号
};

// 一列中的信息
class SudokuCol
{
public:
    SudokuCol();
    ~SudokuCol();
    friend class SudokuAll;

protected:
    std::vector<SudokuPoint *> Col_; // 列编号
};

// 整个数独中的信息
class SudokuAll
{
public:
    SudokuAll();
    ~SudokuAll();
    void ReadFile(std::string);
    void ReadConsole();
    void SetData(SudokuPoint *, int);
    void SetDataCurrent(int, int);
    bool JudgeModify(int);
    bool JudgeUnique(int, int, int, int);
    void PrintData();

protected:
    std::vector<SudokuPoint> AllPoint_; // 所有点
    std::vector<SudokuBox> AllBox_; // 所有宫格
    std::vector<SudokuRow> AllRow_; // 所有行
    std::vector<SudokuCol> AllCol_; // 所有列
};

#endif