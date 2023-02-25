#include "SupermarketMerchandiseManagementSystem.h"

using namespace std;

void Menu(All_Commodity &, Records_Collection &);
bool ReadFile(All_Commodity &, Records_Collection &);
bool WriteFile(All_Commodity &, Records_Collection &);
bool Category_Conversion(string &);
bool Sale(All_Commodity &, Records_Collection &);
bool CreateLog(string, int, Records_Collection &, All_Commodity &);
bool DeleteLog(Records_Collection &, All_Commodity &);
bool UpdateLog(Records_Collection &, All_Commodity &);
bool CreateGoods(All_Commodity &);
bool DeleteGoods(All_Commodity &);
bool UpdateGoods(All_Commodity &);
void PrintGoods(All_Commodity &);
void PrintLog(Records_Collection &, All_Commodity &);
Commodity *SearchGoods(All_Commodity &);
Commodity_Collection_Pointer SearchGoods_Category(All_Commodity &);
Commodity_Collection_Pointer SearchGoods_Name(All_Commodity &);
Commodity_Collection_Pointer SearchGoods_Manufacturer(All_Commodity &);
Commodity *ConfirmGoods(Commodity_Collection_Pointer);

int main(void)
{
    All_Commodity Goods;
    Records_Collection Note;
    ReadFile(Goods, Note);
    Menu(Goods, Note);
    WriteFile(Goods, Note);
    return 0;
}

// 展示菜单和提供用户选择功能
void Menu(All_Commodity &Goods0, Records_Collection &Note0)
{
    while (1)
    {
        cout << "\033c";
        cout << "================超市商品管理系统================" << endl;
        cout << "|    1.购买商品    2.创建商品    3.修改商品    |" << endl;
        cout << "|    4.删除商品    5.查看商品    6.查看记录    |" << endl;
        cout << "|    7.修改记录    8.删除记录    0.退    出    |" << endl;
        cout << "================================================" << endl;
        cout << "请选择您需要的功能:" << endl;
        int Case;
        cin >> Case;
        switch (Case)
        {
        case 1:
            Sale(Goods0, Note0);
            break;
        case 2:
            CreateGoods(Goods0);
            break;
        case 3:
            UpdateGoods(Goods0);
            break;
        case 4:
            DeleteGoods(Goods0);
            break;
        case 5:
            PrintGoods(Goods0);
            break;
        case 6:
            PrintLog(Note0, Goods0);
            break;
        case 7:
            UpdateLog(Note0, Goods0);
            break;
        case 8:
            DeleteLog(Note0, Goods0);
            break;
        case 0:
            return;
        }
        system("pause");
    }
}
// 从文件中读取信息
bool ReadFile(All_Commodity &Goods0, Records_Collection &Note0)
{
    Goods0.ReadFile();
    Note0.ReadFile("SMMSRecords.txt", Goods0);
    return true;
}
// 将信息写入文件中
bool WriteFile(All_Commodity &Goods0, Records_Collection &Note0)
{
    Goods0.WriteFile();
    Note0.WriteFile("SMMSRecords.txt");
    return true;
}
// 将类别规范化
bool Category_Conversion(string &Category0)
{
    if (Category0 == "Foodstuffs" || Category0 == "Cosmetics" || Category0 == "Necessities" || Category0 == "Drinks")
    {
        return true;
    }
    else if (Category0 == "食品" || Category0 == "shipin")
    {
        Category0 = "Foodstuffs";
        return true;
    }
    else if (Category0 == "化妆品" || Category0 == "huazhuangpin")
    {
        Category0 = "Cosmetics";
        return true;
    }
    else if (Category0 == "日用品" || Category0 == "riyongpin")
    {
        Category0 = "Necessities";
        return true;
    }
    else if (Category0 == "饮料" || Category0 == "yinliao")
    {
        Category0 = "Drinks";
        return true;
    }
    else
    {
        return false;
    }
}
// 销售功能实现
bool Sale(All_Commodity &Goods0, Records_Collection &Note0)
{
    string Category;
    string Name;
    int Count;
    do
    {
        cout << "请输入商品类别(输入\"exit\"退出):" << endl;
        cin >> Category;
        if (Category == "exit")
        {
            return false;
        }
        Category_Conversion(Category);
        Goods0.Print_Category(Category);
        cout << "请输入商品名称:" << endl;
        cin >> Name;
        if (Goods0.Find(Category, Name) == NULL)
        {
            cout << "商品不存在, 请重新输入" << endl;
        }
        else
        {
            cout << *Goods0.Find(Category, Name) << endl;
            cout << "请输入商品件数:" << endl;
            cin >> Count;
            if (Goods0.Find(Category, Name)->Inventory < Count)
            {
                cout << "商品库存不足, 请重新输入" << endl;
            }
            else
            {
                break;
            }
        }
    } while (1);
    CreateLog(Name, Count, Note0, Goods0);
    Goods0.Find(Category, Name)->Inventory -= Count;
    cout << "成功购买" << endl;
    return true;
}
// 创造记录, 在销售功能中使用
bool CreateLog(string Name0, int Count0, Records_Collection &Note0, All_Commodity &Goods0)
{
    Note0.CreateRecord(Records(Name0, Count0, Goods0.Locate(Name0)->Price * Count0));
    return true;
}
// 删除记录
bool DeleteLog(Records_Collection &Note0, All_Commodity &Goods0)
{
    Note0.Print();
    cout << "请输入要删除的编号:" << endl;
    int Num;
    cin >> Num;
    if (Note0.GetSize() < Num)
    {
        cout << "未找到该记录" << endl;
        return false;
    }
    Note0.DeleteRecord(Num, Goods0);
    cout << "成功删除" << endl;
    return true;
}
// 修改记录
bool UpdateLog(Records_Collection &Note0, All_Commodity &Goods0)
{
    Note0.Print();
    cout << "请输入要修改的编号:" << endl;
    int Num;
    cin >> Num;
    cout << "请选择要进行的操作(1.修改商品 2.修改数量 3.修改价格):" << endl;
    int Case;
    cin >> Case;
    switch (Case)
    {
    case 1:
    {
        cout << "请输入商品名称:" << endl;
        string Name;
        cin >> Name;
        try
        {
            Note0.UpdateRecord_Goods(Num, Name, Goods0);
            cout << "成功修改" << endl;
        }
        catch (int)
        {
            cout << "未找到该商品";
            return false;
        }
        break;
    }
    case 2:
    {
        cout << "请输入商品数量:" << endl;
        int Count;
        cin >> Count;
        Note0.UpdateRecord_Count(Num, Count, Goods0);
        cout << "成功修改" << endl;
        break;
    }
    case 3:
    {
        cout << "请输入总价格:" << endl;
        float Price;
        cin >> Price;
        Note0.UpdateRecord_Price(Num, Price);
        cout << "成功修改" << endl;
        break;
    }
    default:
    {
        break;
    }
    }
    return true;
}
// 创造商品
bool CreateGoods(All_Commodity &Goods0)
{
    cout << "请按已下格式输入\n商品类别 商品名称 价格 库存量 生产厂家 品牌" << endl;
    string Category;
    string Name;
    float Price;
    int Inventory;
    string Manufacturer;
    string Brand;
    cin >> Category;
    cin >> Name;
    cin >> Price;
    cin >> Inventory;
    cin >> Manufacturer;
    cin >> Brand;
    Category_Conversion(Category);
    Goods0.CreateGoods(Category, Commodity(Name, Price, Inventory, Manufacturer, Brand));
    cout << "成功创建" << endl;
    return true;
}
// 删除商品
bool DeleteGoods(All_Commodity &Goods0)
{
    string Category;
    string Name;
    cout << "请输入商品类别(输入\"exit\"退出):" << endl;
    cin >> Category;
    if (Category == "exit")
    {
        return false;
    }
    Category_Conversion(Category);
    cout << "请输入商品名称:" << endl;
    cin >> Name;
    if (Goods0.Find(Category, Name) == NULL)
    {
        cout << "商品不存在" << endl;
    }
    else
    {
        Goods0.DeleteGoods(Category, Name);
        cout << "成功删除" << endl;
        return true;
    }
    return false;
}
// 修改商品
bool UpdateGoods(All_Commodity &Goods0)
{
    string Category;
    string Name;
    cout << "请输入商品类别(输入\"exit\"退出):" << endl;
    cin >> Category;
    if (Category == "exit")
    {
        return false;
    }
    Category_Conversion(Category);
    cout << "请输入商品名称:" << endl;
    cin >> Name;
    if (Goods0.Find(Category, Name) == NULL)
    {
        cout << "商品不存在" << endl;
    }
    else
    {
        cout << *Goods0.Find(Category, Name) << endl;
        cout << "请输入要修改的信息(1.商品类别 2.商品编号 3.商品名称 4.价格 5.库存量 6.生产厂家 7.品牌)" << endl;
        int Case;
        cin >> Case;
        switch (Case)
        {
        case 1:
        {
            cout << "请输入商品类别:" << endl;
            string CategoryUpdate;
            cin >> CategoryUpdate;
            Goods0.CreateGoods(CategoryUpdate, *Goods0.Find(Category, Name));
            Goods0.DeleteGoods(Category, Name);
            cout << "成功修改" << endl;
            break;
        }
        case 2:
        {
            cout << "请输入商品编号:" << endl;
            int IDUpdate;
            cin >> IDUpdate;
            Goods0.Find(Category, Name)->ID = IDUpdate;
            cout << "成功修改" << endl;
            break;
        }
        case 3:
        {
            cout << "请输入商品名称:" << endl;
            string NameUpdate;
            cin >> NameUpdate;
            Goods0.Find(Category, Name)->Name = NameUpdate;
            cout << "成功修改" << endl;
            break;
        }
        case 4:
        {
            cout << "请输入商品价格:" << endl;
            float PriceUpdate;
            cin >> PriceUpdate;
            Goods0.Find(Category, Name)->Price = PriceUpdate;
            cout << "成功修改" << endl;
            break;
        }
        case 5:
        {
            cout << "请输入商品库存:" << endl;
            int InventoryUpdate;
            cin >> InventoryUpdate;
            Goods0.Find(Category, Name)->Inventory = InventoryUpdate;
            cout << "成功修改" << endl;
            break;
        }
        case 6:
        {
            cout << "请输入生产厂家:" << endl;
            string ManufacturerUpdate;
            cin >> ManufacturerUpdate;
            Goods0.Find(Category, Name)->Manufacturer = ManufacturerUpdate;
            cout << "成功修改" << endl;
            break;
        }
        case 7:
        {
            cout << "请输入品牌:" << endl;
            string BrandUpdate;
            cin >> BrandUpdate;
            Goods0.Find(Category, Name)->Brand = BrandUpdate;
            cout << "成功修改" << endl;
            break;
        }
        default:
        {
            break;
        }
        }
    }
    return false;
}
// 打印单一类别商品
void PrintGoods(All_Commodity &Goods0)
{
    cout << "请输入要查看的商品类别:" << endl;
    string Category;
    cin >> Category;
    int Case = 1;
    Category_Conversion(Category);
    do
    {
        Goods0.Print_Category(Category);
        cout << "请选择排序方式:" << endl
             << "1.编号排序 2.名称排序 3.价格排序 其他退出" << endl;
        cin >> Case;
        switch (Case)
        {
        case 1:
        {
            Goods0.Sort(Category, "ID");
            break;
        }
        case 2:
        {
            Goods0.Sort(Category, "Name");
            break;
        }
        case 3:
        {
            Goods0.Sort(Category, "Price");
            break;
        }
        default:
        {
            return;
        }
        }
    } while (1);
}
// 打印所有记录
void PrintLog(Records_Collection &Note0, All_Commodity &Goods0)
{
    int Case = 1;
    do
    {
        Note0.Print();
        cout << "请选择排序方式:" << endl
             << "1.日期排序 2.名称排序 3.价格排序 4.数量排序 其他退出" << endl;
        cin >> Case;
        switch (Case)
        {
        case 1:
        {
            Note0.Sort_Date(0, Note0.GetSize());
            break;
        }
        case 2:
        {
            Note0.Sort_Name(0, Note0.GetSize(), Goods0);
            break;
        }
        case 3:
        {
            Note0.Sort_Price(0, Note0.GetSize());
            break;
        }
        case 4:
        {
            Note0.Sort_Count(0, Note0.GetSize());
            break;
        }
        default:
        {
            return;
        }
        }
    } while (1);
}
// 查找商品(未使用)
Commodity *SearchGoods(All_Commodity &Goods0)
{
    cout << "" << endl;
    int Case;
    cin >> Case;
    switch (Case)
    {
    case 1:
        return ConfirmGoods(SearchGoods_Category(Goods0));
        break;

    case 2:
        return ConfirmGoods(SearchGoods_Name(Goods0));
        break;

    case 3:
        return ConfirmGoods(SearchGoods_Manufacturer(Goods0));
        break;

    default:
        throw 0;
        break;
    }
}
// 查找商品附加函数, 按类别查找
Commodity_Collection_Pointer SearchGoods_Category(All_Commodity &Goods0)
{
    cout << "请输入商品类别:" << endl;
    string Category;
    cin >> Category;
    Category_Conversion(Category);
    return Goods0.Print_Category(Category);
}
Commodity_Collection_Pointer SearchGoods_Name(All_Commodity &Goods0)
{
    cout << "请输入商品名称:" << endl;
    string Name;
    cin >> Name;
    return Goods0.Print_Name(Name);
}
// 查找商品附加函数, 按名称查找
Commodity_Collection_Pointer SearchGoods_Manufacturer(All_Commodity &Goods0)
{
    cout << "请输入生产厂家:" << endl;
    string Manufacturer;
    cin >> Manufacturer;
    return Goods0.Print_Manufacturer(Manufacturer);
}
// 查找商品附加函数, 最终确定商品
Commodity *ConfirmGoods(Commodity_Collection_Pointer Goods0)
{
    cout << "请选择您的操作(1.按序号查找 2.按商品编号查找 3.按商品名称查找 其他退出)" << endl;
    int Case;
    cin >> Case;
    switch (Case)
    {
    case 1:
    {
        cout << "请输入序号:" << endl;
        int Num;
        cin >> Num;
        return Goods0.SearchGoods_Num(Num);
    }
    case 2:
    {
        cout << "请输入商品编号:" << endl;
        int ID;
        cin >> ID;
        return Goods0.SearchGoods_ID(ID);
    }
    case 3:
    {
        cout << "请输入商品名称:" << endl;
        string Name;
        cin >> Name;
        return Goods0.SearchGoods_Name(Name);
    }
    default:
    {
        throw 0;
    }
    }
}
