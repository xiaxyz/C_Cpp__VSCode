#include "SupermarketMerchandiseManagementSystem.h"
#include <algorithm>
#include <cmath>

using namespace std;

int Commodity::Count = 0;

Commodity::Commodity(string Name0, float Price0, int Inventory0, string Manufacturer0, string Brand0)
{
    ID = 10000 + Count;
    Set(ID, Name0, Price0, Inventory0, Manufacturer0, Brand0);
}
Commodity::~Commodity()
{
}
ostream &operator<<(ostream &Out0, Commodity &Goods0)
{
    cout << setfill(' ') << Goods0.ID << setw(15) << Goods0.Name << setw(15) << Goods0.Price << setw(15) << Goods0.Inventory << setw(15) << Goods0.Manufacturer << setw(15) << Goods0.Brand;
    return Out0;
}
void Commodity::Set(int ID0, string Name0, float Price0, int Inventory0, string Manufacturer0, string Brand0)
{
    ID = ID0;
    Name = Name0;
    Price = Price0;
    Inventory = Inventory0;
    Manufacturer = Manufacturer0;
    Brand = Brand0;
}

Commodity_Collection::Commodity_Collection()
{
}
Commodity_Collection::~Commodity_Collection()
{
}
bool Commodity_Collection::ReadFile(string File0)
{
    ifstream File(File0);
    Commodity TempStored;
    while (File.peek() != EOF)
    {
        File >> TempStored.ID >> TempStored.Name >> TempStored.Price >> TempStored.Inventory >> TempStored.Manufacturer >> TempStored.Brand;
        File.get();
        ++Commodity::Count;
        CommodityCollection.push_back(TempStored);
    }
    File.close();
    return true;
}
bool Commodity_Collection::WriteFile(string File0)
{
    ofstream File(File0);
    for (int i = 0; i < CommodityCollection.size(); ++i)
    {
        File << CommodityCollection[i].ID << " " << CommodityCollection[i].Name << " " << CommodityCollection[i].Price << " " << CommodityCollection[i].Inventory << " " << CommodityCollection[i].Manufacturer << " " << CommodityCollection[i].Brand << endl;
    }
    File.close();
    return true;
}
bool Commodity_Collection::CreateGoods(Commodity Goods0)
{
    CommodityCollection.push_back(Goods0);
    return true;
}
bool Commodity_Collection::DeleteGoods(string Name0)
{
    for (int i = 0; i < CommodityCollection.size(); ++i)
    {
        if (Name0 == CommodityCollection[i].Name)
        {
            CommodityCollection.erase(CommodityCollection.begin() + i);
            return true;
        }
    }
    return false;
}
bool Commodity_Collection::Sort_ID(int Start0, int End0)
{
    if (End0 - Start0 <= 1)
    {
        return true;
    }
    int Mark = Start0;
    for (int i = Start0 + 1; i < End0; ++i)
    {
        if (CommodityCollection[i].ID <= CommodityCollection[Start0].ID)
        {
            ++Mark;
            swap(CommodityCollection[Mark], CommodityCollection[i]);
        }
    }
    swap(CommodityCollection[Start0], CommodityCollection[Mark]);
    Sort_ID(Start0, Mark);
    Sort_ID(Mark + 1, End0);
    return true;
}
bool Commodity_Collection::Sort_Name(int Start0, int End0)
{
    if (End0 - Start0 <= 1)
    {
        return true;
    }
    int Mark = Start0;
    for (int i = Start0 + 1; i < End0; ++i)
    {
        if (CommodityCollection[i].Name <= CommodityCollection[Start0].Name)
        {
            ++Mark;
            swap(CommodityCollection[Mark], CommodityCollection[i]);
        }
    }
    swap(CommodityCollection[Start0], CommodityCollection[Mark]);
    Sort_Name(Start0, Mark);
    Sort_Name(Mark + 1, End0);
    return true;
}
bool Commodity_Collection::Sort_Price(int Start0, int End0)
{
    if (End0 - Start0 <= 1)
    {
        return true;
    }
    int Mark = Start0;
    for (int i = Start0 + 1; i < End0; ++i)
    {
        if (CommodityCollection[i].Price <= CommodityCollection[Start0].Price)
        {
            ++Mark;
            swap(CommodityCollection[Mark], CommodityCollection[i]);
        }
    }
    swap(CommodityCollection[Start0], CommodityCollection[Mark]);
    Sort_Price(Start0, Mark);
    Sort_Price(Mark + 1, End0);
    return true;
}
Commodity *Commodity_Collection::Find(string Name0)
{
    for (int i = 0; i < CommodityCollection.size(); ++i)
    {
        if (Name0 == CommodityCollection[i].Name)
        {
            return &CommodityCollection[i];
        }
    }
    return NULL;
}
int Commodity_Collection::GetSize()
{
    return CommodityCollection.size();
}
void Commodity_Collection::Print(string Category0)
{
    cout << setfill(' ') << setw(log10(CommodityCollection.size()) + 16) << "类别" << setw(15) << "商品编号" << setw(15) << "商品名称" << setw(15)  << "商品价格" << setw(15) << "库存" << setw(15) << "生产厂家" << setw(15) << "品牌" << endl;
    for (int i = 0; i < CommodityCollection.size(); ++i)
    {
        cout << setfill(' ') << setw(log10(CommodityCollection.size()) + 1) << i << setw(15) << Category0 << setw(15) << CommodityCollection[i] << endl;
    }
}
void Commodity_Collection::Print_Name(string Name0, Commodity_Collection_Pointer &Goods0)
{
    for (int i = 0; i < CommodityCollection.size(); ++i)
    {
        if (CommodityCollection[i].Name == Name0)
        {
            cout << setfill(' ') << setw(log10(CommodityCollection.size()) + 1) << i << " " << CommodityCollection[i] << endl;
            Goods0.CreateGoods(&CommodityCollection[i]);
        }
    }
}
void Commodity_Collection::Print_Manufacturer(string Manufacturer0, Commodity_Collection_Pointer &Goods0)
{
    for (int i = 0; i < CommodityCollection.size(); ++i)
    {
        if (CommodityCollection[i].Manufacturer == Manufacturer0)
        {
            cout << setfill(' ') << setw(log10(CommodityCollection.size()) + 1) << i << " " << CommodityCollection[i] << endl;
            Goods0.CreateGoods(&CommodityCollection[i]);
        }
    }
}

Commodity_Collection_Pointer::Commodity_Collection_Pointer()
{
}
Commodity_Collection_Pointer::~Commodity_Collection_Pointer()
{
}
bool Commodity_Collection_Pointer::CreateGoods(Commodity *Goods0)
{
    CommodityCollectionPointer.push_back(Goods0);
    return true;
}
Commodity_Collection_Pointer &Commodity_Collection_Pointer::operator=(Commodity_Collection &Goods0)
{
    for (int i = 0; i < Goods0.CommodityCollection.size(); ++i)
    {
        CreateGoods(&Goods0.CommodityCollection[i]);
    }
    return *this;
}
Commodity *Commodity_Collection_Pointer::SearchGoods_Num(int Num0)
{
    if (CommodityCollectionPointer.size() <= Num0)
    {
        return NULL;
    }
    return CommodityCollectionPointer[Num0];
}
Commodity *Commodity_Collection_Pointer::SearchGoods_ID(int ID0)
{
    for (int i = 0; i < CommodityCollectionPointer.size(); ++i)
    {
        if (ID0 == CommodityCollectionPointer[i]->ID)
        {
            return CommodityCollectionPointer[i];
        }
    }
    return NULL;
}
Commodity *Commodity_Collection_Pointer::SearchGoods_Name(string Name0)
{
    for (int i = 0; i < CommodityCollectionPointer.size(); ++i)
    {
        if (Name0 == CommodityCollectionPointer[i]->Name)
        {
            return CommodityCollectionPointer[i];
        }
    }
    return NULL;
}

All_Commodity::All_Commodity()
{
}
All_Commodity::~All_Commodity()
{
}
bool All_Commodity::ReadFile()
{
    ReadFile("SMMSFoodstuffs.txt", "SMMSCosmetics.txt", "SMMSNecessities.txt", "SMMSDrinks.txt");
    return true;
}
bool All_Commodity::ReadFile(string FoodstuffsFile0, string CosmeticsFile0, string NecessitiesFile0, string DrinksFile0)
{
    Foodstuffs.ReadFile(FoodstuffsFile0);
    Cosmetics.ReadFile(CosmeticsFile0);
    Necessities.ReadFile(NecessitiesFile0);
    Drinks.ReadFile(DrinksFile0);
    return true;
}
bool All_Commodity::WriteFile()
{
    WriteFile("SMMSFoodstuffs.txt", "SMMSCosmetics.txt", "SMMSNecessities.txt", "SMMSDrinks.txt");
    return true;
}
bool All_Commodity::WriteFile(string FoodstuffsFile0, string CosmeticsFile0, string NecessitiesFile0, string DrinksFile0)
{
    Foodstuffs.WriteFile(FoodstuffsFile0);
    Cosmetics.WriteFile(CosmeticsFile0);
    Necessities.WriteFile(NecessitiesFile0);
    Drinks.WriteFile(DrinksFile0);
    return true;
}
Commodity_Collection &All_Commodity::Judge_Category(string Category0)
{
    if (Category0 == "Foodstuffs")
    {
        return Foodstuffs;
    }
    else if (Category0 == "Cosmetics")
    {
        return Cosmetics;
    }
    else if (Category0 == "Necessities")
    {
        return Necessities;
    }
    else if (Category0 == "Drinks")
    {
        return Drinks;
    }
    throw -1;
}
Commodity *All_Commodity::Find(string Category0, string GoodsName0)
{
    return Judge_Category(Category0).Find(GoodsName0);
}
Commodity *All_Commodity::Locate(string GoodsName0)
{
    if (Foodstuffs.Find(GoodsName0) != NULL)
    {
        return Foodstuffs.Find(GoodsName0);
    }
    else if (Cosmetics.Find(GoodsName0) != NULL)
    {
        return Cosmetics.Find(GoodsName0);
    }
    else if (Necessities.Find(GoodsName0) != NULL)
    {
        return Necessities.Find(GoodsName0);
    }
    else if (Drinks.Find(GoodsName0) != NULL)
    {
        return Drinks.Find(GoodsName0);
    }
    return NULL;
}
bool All_Commodity::CreateGoods(string Category0, Commodity Goods0)
{
    Judge_Category(Category0).CreateGoods(Goods0);
    return true;
}
bool All_Commodity::DeleteGoods(string Category0, string Name0)
{
    return Judge_Category(Category0).DeleteGoods(Name0);
}
bool All_Commodity::Sort(string Category0, string Mode0)
{
    if (Mode0 == "ID")
    {
        return Judge_Category(Category0).Sort_ID(0, Judge_Category(Category0).GetSize());
    }
    else if (Mode0 == "Name")
    {
        return Judge_Category(Category0).Sort_Name(0, Judge_Category(Category0).GetSize());
    }
    else if (Mode0 == "Price")
    {
        return Judge_Category(Category0).Sort_Price(0, Judge_Category(Category0).GetSize());
    }
    return false;
}
Commodity_Collection_Pointer All_Commodity::Print_Category(string Category0)
{
    Commodity_Collection_Pointer Goods;
    Judge_Category(Category0).Print(Category0);
    Goods = Judge_Category(Category0);
    return Goods;
}
Commodity_Collection_Pointer All_Commodity::Print_Name(string Name0)
{
    Commodity_Collection_Pointer Goods;
    Foodstuffs.Print_Name(Name0, Goods);
    Cosmetics.Print_Name(Name0, Goods);
    Necessities.Print_Name(Name0, Goods);
    Drinks.Print_Name(Name0, Goods);
    return Goods;
}
Commodity_Collection_Pointer All_Commodity::Print_Manufacturer(string Manufacturer0)
{
    Commodity_Collection_Pointer Goods;
    Foodstuffs.Print_Manufacturer(Manufacturer0, Goods);
    Cosmetics.Print_Manufacturer(Manufacturer0, Goods);
    Necessities.Print_Manufacturer(Manufacturer0, Goods);
    Drinks.Print_Manufacturer(Manufacturer0, Goods);
    return Goods;
}

Records::Records(string Goods0, int Count0, float Price0, DateRecord Date0)
{
    Set(Goods0, Count0, Price0);
    Date = Date0;
}
Records::~Records()
{
}
ostream &operator<<(ostream &Out, Records &Note0)
{
    Out << setfill(' ') << Note0.GoodsName << setw(15) << Note0.Count << setw(15) << Note0.Price << setw(15) << Note0.Date;
    return Out;
}
bool Records::Set(string Name0, int Count0, float Price0)
{
    GoodsName = Name0;
    Count = Count0;
    Price = Price0;
    return true;
}

Records_Collection::Records_Collection()
{
}
Records_Collection::~Records_Collection()
{
}
bool Records_Collection::ReadFile(string File0, All_Commodity &Goods0)
{
    ifstream File(File0);
    Records TempStored;
    while (File.peek() != EOF)
    {
        File >> TempStored.GoodsName >> TempStored.Count >> TempStored.Price >> TempStored.Date;
        File.get();
        RecordsCollection.push_back(TempStored);
    }
    File.close();
    return true;
}
bool Records_Collection::WriteFile(string File0)
{
    ofstream File(File0);
    for (int i = 0; i < RecordsCollection.size(); ++i)
    {
        File << RecordsCollection[i].GoodsName << " " << RecordsCollection[i].Count << " " << RecordsCollection[i].Price << " " << RecordsCollection[i].Date << endl;
    }
    File.close();
    return true;
}
bool Records_Collection::CreateRecord(Records Note0)
{
    RecordsCollection.push_back(Note0);
    return true;
}
bool Records_Collection::DeleteRecord(int Num0, All_Commodity &Goods0)
{
    if (Goods0.Locate(RecordsCollection[Num0].GoodsName) != NULL)
    {
        Goods0.Locate(RecordsCollection[Num0].GoodsName)->Inventory += RecordsCollection[Num0].Count;
    }
    RecordsCollection.erase(RecordsCollection.begin() + Num0);
    return true;
}
bool Records_Collection::UpdateRecord_Goods(int Num0, string Name0, All_Commodity &Goods0)
{
    if (Goods0.Locate(Name0) != NULL)
    {
        Goods0.Locate(Name0)->Inventory -= RecordsCollection[Num0].Count;
    }
    Records TempRecord;
    TempRecord = RecordsCollection[Num0];
    DeleteRecord(Num0, Goods0);
    TempRecord.GoodsName = Name0;
    RecordsCollection.insert(RecordsCollection.begin() + Num0, TempRecord);
    return true;
}
bool Records_Collection::UpdateRecord_Count(int Num0, int Count0, All_Commodity &Goods0)
{
    if (Goods0.Locate(RecordsCollection[Num0].GoodsName) != NULL)
    {
        Goods0.Locate(RecordsCollection[Num0].GoodsName)->Inventory += RecordsCollection[Num0].Count;
        Goods0.Locate(RecordsCollection[Num0].GoodsName)->Inventory -= Count0;
    }
    RecordsCollection[Num0].Count = Count0;
    return true;
}
bool Records_Collection::UpdateRecord_Price(int Num0, float Price0)
{
    RecordsCollection[Num0].Price = Price0;
    return true;
}
bool Records_Collection::Sort_Date(int Start0, int End0)
{
    if (End0 - Start0 <= 1)
    {
        return true;
    }
    int Mark = Start0;
    for (int i = Start0 + 1; i < End0; ++i)
    {
        if (RecordsCollection[i].Date <= RecordsCollection[Start0].Date)
        {
            ++Mark;
            swap(RecordsCollection[Mark], RecordsCollection[i]);
        }
    }
    swap(RecordsCollection[Start0], RecordsCollection[Mark]);
    Sort_Date(Start0, Mark);
    Sort_Date(Mark + 1, End0);
    return true;
}
bool Records_Collection::Sort_Name(int Start0, int End0, All_Commodity &Goods0)
{
    if (End0 - Start0 <= 1)
    {
        return true;
    }
    int Mark = Start0;
    for (int i = Start0 + 1; i < End0; ++i)
    {

        if (Goods0.Locate(RecordsCollection[i].GoodsName)->Name <= Goods0.Locate(RecordsCollection[Start0].GoodsName)->Name)
        {
            ++Mark;
            swap(RecordsCollection[Mark], RecordsCollection[i]);
        }
    }
    swap(RecordsCollection[Start0], RecordsCollection[Mark]);
    Sort_Name(Start0, Mark, Goods0);
    Sort_Name(Mark + 1, End0, Goods0);
    return true;
}
bool Records_Collection::Sort_Price(int Start0, int End0)
{
    if (End0 - Start0 <= 1)
    {
        return true;
    }
    int Mark = Start0;
    for (int i = Start0 + 1; i < End0; ++i)
    {
        if (RecordsCollection[i].Price <= RecordsCollection[Start0].Price)
        {
            ++Mark;
            swap(RecordsCollection[Mark], RecordsCollection[i]);
        }
    }
    swap(RecordsCollection[Start0], RecordsCollection[Mark]);
    Sort_Price(Start0, Mark);
    Sort_Price(Mark + 1, End0);
    return true;
}
bool Records_Collection::Sort_Count(int Start0, int End0)
{
    if (End0 - Start0 <= 1)
    {
        return true;
    }
    int Mark = Start0;
    for (int i = Start0 + 1; i < End0; ++i)
    {
        if (RecordsCollection[i].Count <= RecordsCollection[Start0].Count)
        {
            ++Mark;
            swap(RecordsCollection[Mark], RecordsCollection[i]);
        }
    }
    swap(RecordsCollection[Start0], RecordsCollection[Mark]);
    Sort_Count(Start0, Mark);
    Sort_Count(Mark + 1, End0);
    return true;
}
int Records_Collection::GetSize()
{
    return RecordsCollection.size();
}
void Records_Collection::Print()
{
    for (int i = 0; i < RecordsCollection.size(); ++i)
    {
        cout << setfill(' ') << setw(log10(RecordsCollection.size()) + 1) << i << setw(15) << RecordsCollection[i] << endl;
    }
}