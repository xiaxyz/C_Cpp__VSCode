#include "./SudokuVault.h"

SudokuCell::SudokuCell(int XMark0_, int YMark0_, int Data0_, bool Modify0_)
{
    XMark_ = XMark0_;
    YMark_ = YMark0_;
    Data_ = Data0_;
    Modify_ = Modify0_;
}
SudokuCell::~SudokuCell()
{
}
/// @brief 定义数据修改性
/// @param Modify0_ true 可修改 false 不可修改
void SudokuCell::SetModify(bool Modify0_)
{
    Modify_ = Modify0_;
}
/// @brief 判断修改性
/// @return true 可修改 false 不可修改
bool SudokuCell::JudgeModify()
{
    return Modify_;
}
/// @brief 获取数据
/// @return int 数据值
int SudokuCell::GetData()
{
    return Data_;
}
/// @brief 设置点的数据
/// @param Data0_ 数据值
void SudokuCell::SetData(int Data0_)
{
    Data_ = Data0_;
}

SudokuBlock::SudokuBlock()
{
    Block_.resize(BLOCK_SIDE);
    for (int i = Block_.size() - 1; i >= 0; --i)
    {
        Block_[i].resize(BLOCK_SIDE, NULL);
    }
}
SudokuBlock::~SudokuBlock()
{
}

SudokuRow::SudokuRow()
{
    Row_.resize(ALL_SIDE, NULL);
}
SudokuRow::~SudokuRow()
{
}

SudokuCol::SudokuCol()
{
    Col_.resize(ALL_SIDE, NULL);
}
SudokuCol::~SudokuCol()
{
}

SudokuAll::SudokuAll()
{
    AllCell_.resize(CELL_COUNT);
    AllBlock_.resize(BLOCK_COUNT);
    AllRow_.resize(ALL_SIDE);
    AllCol_.resize(ALL_SIDE);
}
SudokuAll::~SudokuAll()
{
}
/// @brief 从文件中读取数据
/// @param File0_ 文件名
void SudokuAll::ReadFile(std::string File0_)
{
    std::ifstream File_(File0_);
    int TempCellData_; // 暂时存放点的数据
    for (int i = 0; i < CELL_COUNT; ++i)
    {
        File_ >> TempCellData_;
        if (TempCellData_ != 0)
        {
            AllCell_[i].SetData(TempCellData_);
            AllCell_[i].SetModify(false);
        }
        AllCell_[i].XMark_ = i % ALL_SIDE;
        AllCell_[i].YMark_ = i / ALL_SIDE;
        SetData(&AllCell_[i], i);
    }
}
/// @brief 从控制台中读取数据
void SudokuAll::ReadConsole()
{
    int TempCellData_; // 暂时存放点的数据
    for (int i = 0; i < CELL_COUNT; ++i)
    {
        std::cin >> TempCellData_;
        std::cin.get();
        if (TempCellData_ != 0)
        {
            AllCell_[i].SetData(TempCellData_);
            AllCell_[i].SetModify(false);
        }
        AllCell_[i].XMark_ = i % ALL_SIDE;
        AllCell_[i].YMark_ = i / ALL_SIDE;
        SetData(&AllCell_[i], i);
    }
}
/// @brief 将一个点中的数据存入Sudoku中
/// @param Cell0_ 点的数据
/// @param Num0_ 点所在的位置
void SudokuAll::SetData(SudokuCell *Cell0_, int Num0_)
{
    AllBlock_[(AllCell_[Num0_].XMark_ / ALL_SIDE_BLOCK_COUNT) + (AllCell_[Num0_].YMark_ / ALL_SIDE_BLOCK_COUNT) * ALL_SIDE_BLOCK_COUNT].Block_[AllCell_[Num0_].XMark_ % BLOCK_SIDE][AllCell_[Num0_].YMark_ % BLOCK_SIDE] = Cell0_;
    AllRow_[AllCell_[Num0_].YMark_].Row_[AllCell_[Num0_].XMark_] = Cell0_;
    AllCol_[AllCell_[Num0_].XMark_].Col_[AllCell_[Num0_].YMark_] = Cell0_;
}
/// @brief 设置某坐标的值
/// @param Current0_ 所在位置
/// @param CellData0_ 将设置的值
void SudokuAll::SetDataCurrent(int Current0_, int CellData0_)
{
    AllCell_[Current0_].SetData(CellData0_);
}
/// @brief 判断所在编号是否可被修改
/// @param Current0_
/// @return true 可修改 false 不可修改
bool SudokuAll::JudgeModify(int Current0_)
{
    return AllCell_[Current0_].JudgeModify();
}
/// @brief 通过 宫格, 行, 列 判断数据唯一性
/// @param CellData0_ 需要判断的值
/// @param BlockNum0_ 所在的宫格编号
/// @param RowNum0_ 所在的行编号
/// @param ColNum0_ 所在的列编号
/// @return true 唯一 false 不唯一
bool SudokuAll::JudgeUnique(int CellData0_, int BlockNum0_, int RowNum0_, int ColNum0_)
{
    for (int i = 0; i < BLOCK_SIDE; ++i)
    {
        for (int j = 0; j < BLOCK_SIDE; ++j)
        {
            if (CellData0_ == AllBlock_[BlockNum0_].Block_[i][j]->GetData())
            {
                return false;
            }
            if (CellData0_ == AllRow_[RowNum0_].Row_[i * BLOCK_SIDE + j]->GetData())
            {
                return false;
            }
            if (CellData0_ == AllCol_[ColNum0_].Col_[i * BLOCK_SIDE + j]->GetData())
            {
                return false;
            }
        }
    }
    return true;
}
/// @brief 数据输出
void SudokuAll::PrintData()
{
    for (int i = 0; i < CELL_COUNT; ++i)
    {
        if (AllCell_[i].JudgeModify())
        {
            std::cout << " \033[36m" << AllCell_[i].GetData() << "\033[37m";
        }
        else
        {
            std::cout << " \033[31m" << AllCell_[i].GetData() << "\033[37m";
        }
        if ((i + 1) % ALL_SIDE == 0)
        {
            std::cout << std::endl;
        }
    }
}
