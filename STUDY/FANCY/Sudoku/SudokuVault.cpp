#include "./SudokuVault.h"
#include <fstream>
#include <iostream>

SudokuPoint::SudokuPoint(int XMark0_, int YMark0_, int Data0_, bool Modify0_)
{
    XMark_ = XMark0_;
    YMark_ = YMark0_;
    Data_ = Data0_;
    Modify_ = Modify0_;
}
SudokuPoint::~SudokuPoint()
{
}
/// @brief 定义数据修改性
/// @param Modify0_ true 可修改 false 不可修改
void SudokuPoint::SetModify(bool Modify0_)
{
    Modify_ = Modify0_;
}
/// @brief 判断修改性
/// @return true 可修改 false 不可修改
bool SudokuPoint::JudgeModify()
{
    return Modify_;
}
/// @brief 获取数据
/// @return int 数据值
int SudokuPoint::GetData()
{
    return Data_;
}
/// @brief 设置点的数据
/// @param Data0_ 数据值
void SudokuPoint::SetData(int Data0_)
{
    Data_ = Data0_;
}

SudokuBox::SudokuBox()
{
    Box_.resize(BOX_SIDE);
    for (int i = Box_.size() - 1; i >= 0; --i)
    {
        Box_[i].resize(BOX_SIDE, NULL);
    }
}
SudokuBox::~SudokuBox()
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
    AllPoint_.resize(POINT_COUNT);
    AllBox_.resize(BOX_COUNT);
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
    int TempPointData_; // 暂时存放点的数据
    for (int i = 0; i < POINT_COUNT; ++i)
    {
        File_ >> TempPointData_;
        if (TempPointData_ != 0)
        {
            AllPoint_[i].SetData(TempPointData_);
            AllPoint_[i].SetModify(false);
        }
        AllPoint_[i].XMark_ = i % ALL_SIDE;
        AllPoint_[i].YMark_ = i / ALL_SIDE;
        SetData(&AllPoint_[i], i);
    }
}
/// @brief 从控制台中读取数据
void SudokuAll::ReadConsole()
{
    int TempPointData_; // 暂时存放点的数据
    for (int i = 0; i < POINT_COUNT; ++i)
    {
        std::cin >> TempPointData_;
        std::cin.get();
        if (TempPointData_ != 0)
        {
            AllPoint_[i].SetData(TempPointData_);
            AllPoint_[i].SetModify(false);
        }
        AllPoint_[i].XMark_ = i % ALL_SIDE;
        AllPoint_[i].YMark_ = i / ALL_SIDE;
        SetData(&AllPoint_[i], i);
    }
}
/// @brief 将一个点中的数据存入Sudoku中
/// @param Point0_ 点的数据
/// @param Num0_ 点所在的位置
void SudokuAll::SetData(SudokuPoint *Point0_, int Num0_)
{
    AllBox_[(AllPoint_[Num0_].XMark_ / ALL_SIDE_BOX_COUNT) + (AllPoint_[Num0_].YMark_ / ALL_SIDE_BOX_COUNT) * ALL_SIDE_BOX_COUNT].Box_[AllPoint_[Num0_].XMark_ % BOX_SIDE][AllPoint_[Num0_].YMark_ % BOX_SIDE] = Point0_;
    AllRow_[AllPoint_[Num0_].YMark_].Row_[AllPoint_[Num0_].XMark_] = Point0_;
    AllCol_[AllPoint_[Num0_].XMark_].Col_[AllPoint_[Num0_].YMark_] = Point0_;
}
/// @brief 设置某坐标的值
/// @param Current0_ 所在位置
/// @param PointData0_ 将设置的值
void SudokuAll::SetDataCurrent(int Current0_, int PointData0_)
{
    AllPoint_[Current0_].SetData(PointData0_);
}
/// @brief 判断所在编号是否可被修改
/// @param Current0_ 
/// @return true 可修改 false 不可修改
bool SudokuAll::JudgeModify(int Current0_)
{
    return AllPoint_[Current0_].JudgeModify();
}
/// @brief 通过 宫格, 行, 列 判断数据唯一性
/// @param PointData0_ 需要判断的值
/// @param BoxNum0_ 所在的宫格编号
/// @param RowNum0_ 所在的行编号
/// @param ColNum0_ 所在的列编号
/// @return true 唯一 false 不唯一
bool SudokuAll::JudgeUnique(int PointData0_, int BoxNum0_, int RowNum0_, int ColNum0_)
{
    for (int i = 0; i < BOX_SIDE; ++i)
    {
        for (int j = 0; j < BOX_SIDE; ++j)
        {
            if (PointData0_ == AllBox_[BoxNum0_].Box_[i][j]->GetData())
            {
                return false;
            }
            if (PointData0_ == AllRow_[RowNum0_].Row_[i * BOX_SIDE + j]->GetData())
            {
                return false;
            }
            if (PointData0_ == AllCol_[ColNum0_].Col_[i * BOX_SIDE + j]->GetData())
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
    for (int i = 0; i < POINT_COUNT; ++i)
    {
        if (AllPoint_[i].JudgeModify())
        {
            std::cout << " \033[36m" << AllPoint_[i].GetData() << "\033[37m";
        }
        else 
        {
            std::cout << " \033[31m" << AllPoint_[i].GetData() << "\033[37m";
        }
        if ((i + 1) % ALL_SIDE == 0)
        {
            std::cout << std::endl;
        }
    }
}