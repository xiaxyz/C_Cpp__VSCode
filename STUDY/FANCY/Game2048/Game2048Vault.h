#ifndef _Game2048Vault_h_
#define _Game2048Vault_h_

#include <vector>
#include <iostream>

class Game2048Point;
class Game2048All;

/// @brief 记录一个格子中的信息
class Game2048Point
{
public:
    Game2048Point(int = 0);
    ~Game2048Point();
    friend class Game2048All;
    friend std::ostream &operator<<(std::ostream &, Game2048Point &);

private:
    int Data_; // 格子中的数字
    bool WhetherNew_; // 是否为新产生的数字
};

/// @brief 记录所有格子中的信息
class Game2048All
{
public:
    Game2048All(int = 4, int = 4);
    ~Game2048All();
    void Move(char);
    bool Blend(char);
    std::vector<Game2048Point *> JudgeEmpty();
    void CreateNewNumber();
    bool JudgeEnd();
    void Print();

private:
    std::vector<std::vector<Game2048Point>> AllPoint_; // 所有的格子信息
    int Length_; // 长
    int Width_; // 宽
    long long Score_; // 分数
    int MaxNewNumber_; // 最大能产生的数字
};

#endif