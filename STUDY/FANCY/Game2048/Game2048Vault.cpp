#include "./Game2048Vault.h"
#include <algorithm>
#include <random>
#include <iomanip>
#include <ctime>
#define ALIGN 7

Game2048Point::Game2048Point(int Data0_)
{
    Data_ = Data0_;
    WhetherNew_ = false;
}
Game2048Point::~Game2048Point()
{
}
std::ostream &operator<<(std::ostream &Out0_, Game2048Point &Point0_)
{
    if(Point0_.WhetherNew_)
    {
        std::cout << "\033[7m";
        Point0_.WhetherNew_ = false;
    }
    if (Point0_.Data_ >= 4096)
    {
        std::cout << "\033[1;31m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    else if (Point0_.Data_ >= 2048)
    {
        std::cout << "\033[31m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    else if (Point0_.Data_ >= 1024)
    {
        std::cout << "\033[1;33m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    else if (Point0_.Data_ >= 512)
    {
        std::cout << "\033[33m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    else if (Point0_.Data_ >= 256)
    {
        std::cout << "\033[1;32m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    else if (Point0_.Data_ >= 128)
    {
        std::cout << "\033[32m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    else if (Point0_.Data_ >= 64)
    {
        std::cout << "\033[1;35m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    else if (Point0_.Data_ >= 32)
    {
        std::cout << "\033[35m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    else if (Point0_.Data_ >= 16)
    {
        std::cout << "\033[1;34m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    else if (Point0_.Data_ >= 8)
    {
        std::cout << "\033[34m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    else if (Point0_.Data_ >= 4)
    {
        std::cout << "\033[1;36m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    else if (Point0_.Data_ >= 2)
    {
        std::cout << "\033[36m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    else
    {
        std::cout << "\033[0m" << std::setw(ALIGN) << Point0_.Data_ << "\033[0m";
    }
    return Out0_;
}

Game2048All::Game2048All(int Length0_, int Width0_)
{
    Score_ = 0;
    Length_ = Length0_;
    Width_ = Width0_;
    MaxNewNumber_ = sqrt(sqrt(Length0_ * Width0_));
    AllPoint_.resize(Length0_);
    for (int i = 0; i < Length0_; ++i)
    {
        AllPoint_[i].resize(Width0_);
    }
}
Game2048All::~Game2048All()
{
}
/// @brief 朝某方向移动
/// @param Direction0_ 移动方向
void Game2048All::Move(char Direction0_)
{
    bool flag = Blend(Direction0_);
    if (Direction0_ == 'U')
    {
        for (int i = 0; i < Length_; ++i)
        {
            int Mark_ = 0;
            for (int j = 0; j < Width_; ++j)
            {
                if (AllPoint_[i][j].Data_ != 0)
                {
                    if (Mark_ != j)
                    {
                        std::swap(AllPoint_[i][Mark_], AllPoint_[i][j]);
                        flag = true;
                    }
                    ++Mark_;
                }
            }
        }
    }
    else if (Direction0_ == 'D')
    {
        for (int i = 0; i < Length_; ++i)
        {
            int Mark_ = Width_ - 1;
            for (int j = Width_ - 1; j >= 0; --j)
            {
                if (AllPoint_[i][j].Data_ != 0)
                {
                    if (Mark_ != j)
                    {
                        std::swap(AllPoint_[i][Mark_], AllPoint_[i][j]);
                        flag = true;
                    }
                    --Mark_;
                }
            }
        }
    }
    else if (Direction0_ == 'L')
    {
        for (int i = 0; i < Width_; ++i)
        {
            int Mark_ = 0;
            for (int j = 0; j < Length_; ++j)
            {
                if (AllPoint_[j][i].Data_ != 0)
                {
                    if (Mark_ != j)
                    {
                        std::swap(AllPoint_[Mark_][i], AllPoint_[j][i]);
                        flag = true;
                    }
                    ++Mark_;
                }
            }
        }
    }
    else if (Direction0_ == 'R')
    {
        for (int i = 0; i < Width_; ++i)
        {
            int Mark_ = Length_ - 1;
            for (int j = Length_ - 1; j >= 0; --j)
            {
                if (AllPoint_[j][i].Data_ != 0)
                {
                    if (Mark_ != j)
                    {
                        std::swap(AllPoint_[Mark_][i], AllPoint_[j][i]);
                        flag = true;
                    }
                    --Mark_;
                }
            }
        }
    }
    if (flag)
    {
        CreateNewNumber();
    }
}
/// @brief 合成所有相同格子
/// @param Direction0_ 合成方向
bool Game2048All::Blend(char Direction0_)
{
    bool flag = false;
    if (Direction0_ == 'U')
    {
        for (int i = 0; i < Length_; ++i)
        {
            for (int j = 0; j < Width_ - 1; ++j)
            {
                if (AllPoint_[i][j].Data_ != 0)
                {
                    int Position_ = 1;
                    while (j + Position_ <= Width_ - 1)
                    {
                        if (AllPoint_[i][j].Data_ == AllPoint_[i][j + Position_].Data_)
                        {
                            AllPoint_[i][j].Data_ += AllPoint_[i][j + Position_].Data_;
                            AllPoint_[i][j + Position_].Data_ = 0;
                            j += Position_;
                            flag = true;
                            break;
                        }
                        else if (AllPoint_[i][j + Position_].Data_ == 0)
                        {
                            ++Position_;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    else if (Direction0_ == 'D')
    {
        for (int i = 0; i < Length_; ++i)
        {
            for (int j = Width_ - 1; j >= 1; --j)
            {
                if (AllPoint_[i][j].Data_ != 0)
                {
                    int Position_ = 1;
                    while (j - Position_ >= 0)
                    {
                        if (AllPoint_[i][j].Data_ == AllPoint_[i][j - Position_].Data_)
                        {
                            AllPoint_[i][j].Data_ += AllPoint_[i][j - Position_].Data_;
                            AllPoint_[i][j - Position_].Data_ = 0;
                            j -= Position_;
                            flag = true;
                            break;
                        }
                        else if (AllPoint_[i][j - Position_].Data_ == 0)
                        {
                            ++Position_;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    else if (Direction0_ == 'L')
    {
        for (int i = 0; i < Width_; ++i)
        {
            for (int j = 0; j < Length_ - 1; ++j)
            {
                if (AllPoint_[j][i].Data_ != 0)
                {
                    int Position_ = 1;
                    while (j + Position_ <= Length_ - 1)
                    {
                        if (AllPoint_[j][i].Data_ == AllPoint_[j + Position_][i].Data_)
                        {
                            AllPoint_[j][i].Data_ += AllPoint_[j + Position_][i].Data_;
                            AllPoint_[j + Position_][i].Data_ = 0;
                            j += Position_;
                            flag = true;
                            break;
                        }
                        else if (AllPoint_[j + Position_][i].Data_ == 0)
                        {
                            ++Position_;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    else if (Direction0_ == 'R')
    {
        for (int i = 0; i < Width_; ++i)
        {
            for (int j = Length_ - 1; j >= 1; --j)
            {
                if (AllPoint_[j][i].Data_ != 0)
                {
                    int Position_ = 1;
                    while (j - Position_ >= 0)
                    {
                        if (AllPoint_[j][i].Data_ == AllPoint_[j - Position_][i].Data_)
                        {
                            AllPoint_[j][i].Data_ += AllPoint_[j - Position_][i].Data_;
                            AllPoint_[j - Position_][i].Data_ = 0;
                            j -= Position_;
                            flag = true;
                            break;
                        }
                        else if (AllPoint_[j - Position_][i].Data_ == 0)
                        {
                            ++Position_;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    return flag;
}
/// @brief 判断空位的个数
/// @return 将所有空位返回
std::vector<Game2048Point *> Game2048All::JudgeEmpty()
{
    std::vector<Game2048Point *> AllEmpty_;
    for (int i = 0; i < Length_; ++i)
    {
        for (int j = 0; j < Width_; ++j)
        {
            if (AllPoint_[i][j].Data_ == 0)
            {
                AllEmpty_.push_back(&AllPoint_[i][j]);
            }
        }
    }
    return AllEmpty_;
}
/// @brief 创建新的数字
/// @param AllEmpty0_ 所有空位
void Game2048All::CreateNewNumber()
{
    std::vector<Game2048Point *> AllEmpty_;
    AllEmpty_ = JudgeEmpty();
    if (AllEmpty_.size() == 0)
    {
        return;
    }
    static std::default_random_engine Engine_(time(nullptr));                            // 随机数引擎
    std::uniform_int_distribution<int> RandomEmpty_(0, AllEmpty_.size() - 1);            // 随机空位编号
    std::uniform_int_distribution<int> RandomNumber_(1, MaxNewNumber_); // 随机概率
    int NewID_;
    NewID_ = RandomEmpty_(Engine_);
    int NewNumber_;
    NewNumber_ = (int)pow(2, RandomNumber_(Engine_));
    AllEmpty_[NewID_]->Data_ = NewNumber_;
    AllEmpty_[NewID_]->WhetherNew_ = true;
    Score_ += NewNumber_ / 2;
}
/// @brief 判断结束
/// @return true 结束 false 未结束
bool Game2048All::JudgeEnd()
{
    if (JudgeEmpty().size() == 0)
    {
        for (int i = 0; i < Width_; ++i)
        {
            for (int j = 0; j < Length_; ++j)
            {
                if (j == Length_ - 1)
                {
                    if (AllPoint_[j][i].Data_ == AllPoint_[j][i + 1].Data_)
                    {
                        return false;
                    }
                }
                else if (i == Width_ - 1)
                {
                    if (AllPoint_[j][i].Data_ == AllPoint_[j + 1][i].Data_)
                    {
                        return false;
                    }
                }
                else
                {
                    if (AllPoint_[j][i].Data_ == AllPoint_[j + 1][i].Data_ || AllPoint_[j][i].Data_ == AllPoint_[j][i + 1].Data_)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    return false;
}
/// @brief 打印所有信息
void Game2048All::Print()
{
    std::cout << "score:" << Score_ << std::endl;
    for (int i = 0; i < Width_; ++i)
    {
        for (int j = 0; j < Length_; ++j)
        {
            std::cout << AllPoint_[j][i];
        }
        std::cout << std::endl;
    }
}