#include "Game2048Vault.h"

Game2048All Game_(4, 4);

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
    switch (Direction0_)
    {
    case 'w':
    case 'W':
    case '8':
        return 'U';
    case 's':
    case 'S':
    case '2':
        return 'D';
    case 'a':
    case 'A':
    case '4':
        return 'L';
    case 'd':
    case 'D':
    case '6':
        return 'R';
    default:
        break;
    }
    return Direction0_;
}
