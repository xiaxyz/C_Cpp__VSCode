#ifndef _SudokuVault_h_
#define _SudokuVault_h_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#define BLOCK_SIDE 3 // 宫格的边长
#define ALL_SIDE 9     // 总边长
#define CELL_COUNT (ALL_SIDE * ALL_SIDE)    // 总点数
#define ALL_SIDE_BLOCK_COUNT (ALL_SIDE / BLOCK_SIDE) // 总边长中含有的宫格数
#define BLOCK_COUNT (ALL_SIDE_BLOCK_COUNT * ALL_SIDE_BLOCK_COUNT) // 总宫格数

class SudokuCell;
class SudokuBlock;
class SudokuRow;
class SudokuCol;
class SudokuAll;

// 一个点中的信息
class SudokuCell
{
public:
    int XMark_; // 行标
    int YMark_; // 列标
    SudokuCell(int = -1, int = -1, int = 0, bool = true);
    ~SudokuCell();
    void SetModify(bool);
    bool JudgeModify();
    int GetData();
    void SetData(int = 0);

protected:
    bool Modify_; // 可修改性
    int Data_; // 数据
};

// 一个宫格中的信息
class SudokuBlock
{
public:
    SudokuBlock();
    ~SudokuBlock();
    friend class SudokuAll;

protected:
    std::vector<std::vector<SudokuCell *>> Block_; // 宫格编号
};

// 一行中的信息
class SudokuRow
{
public:
    SudokuRow();
    ~SudokuRow();
    friend class SudokuAll;

protected:
    std::vector<SudokuCell *> Row_; // 行编号
};

// 一列中的信息
class SudokuCol
{
public:
    SudokuCol();
    ~SudokuCol();
    friend class SudokuAll;

protected:
    std::vector<SudokuCell *> Col_; // 列编号
};

// 整个数独中的信息
class SudokuAll
{
public:
    SudokuAll();
    ~SudokuAll();
    void ReadFile(std::string);
    void ReadConsole();
    void SetData(SudokuCell *, int);
    void SetDataCurrent(int, int);
    bool JudgeModify(int);
    bool JudgeUnique(int, int, int, int);
    void PrintData();

protected:
    std::vector<SudokuCell> AllCell_; // 所有点
    std::vector<SudokuBlock> AllBlock_; // 所有宫格
    std::vector<SudokuRow> AllRow_; // 所有行
    std::vector<SudokuCol> AllCol_; // 所有列
};

#endif
