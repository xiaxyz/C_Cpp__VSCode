#include "Game2048Vault.cpp"

Game2048All Game_(2, 2);

char JudgeDirection(char);

int main(int argc, char **argv)
{
    Game_.CreateNewNumber();
    Game_.Print();
    do
    {
        char Direction_; // 接收用户的输入
        std::cin >> Direction_;
        std::cin.get();
        std::cout << "\033c";
        Game_.Move(JudgeDirection(Direction_));
        Game_.Print();
    } while (!Game_.JudgeEnd());
    std::cout << "game over";
    std::cin.get();
    return 0;
}

/// @brief 将用户输入字符转换为可识别的字符
/// @param Direction0_ 用户输入的字符
/// @return 可识别的字符
char JudgeDirection(char Direction0_)
{
    if (Direction0_ == 'w')
    {
        return 'U';
    }
    else if (Direction0_ == 's')
    {
        return 'D';
    }
    else if (Direction0_ == 'a')
    {
        return 'L';
    }
    else if (Direction0_ == 'd')
    {
        return 'R';
    }
    return Direction0_;
}