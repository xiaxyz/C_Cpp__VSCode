#ifndef _SupermarketMerchandiseManagementSystem_h_
#define _SupermarketMerchandiseManagementSystem_h_ 1

#include <iostream>
#include <vector>
#include <fstream>
#include "GetTime.cpp"

using namespace std;

class Commodity;
class Commodity_Collection;
class Commodity_Collection_Pointer;
class All_Commodity;
class Records;
class Records_Collection;

class Commodity
{
public:
    string Name;
    static int Count;
    int ID;
    float Price;
    int Inventory;
    string Manufacturer;
    string Brand;
    Commodity(string = "", float = 0, int = 0, string = "", string = "");
    ~Commodity();
    friend class Commodity_Collection;
    friend class Commodity_Collection_Pointer;
    friend ostream &operator<<(ostream &, Commodity &);
    void Set(int, string, float, int, string, string);
};

class Commodity_Collection
{
public:
    Commodity_Collection();
    ~Commodity_Collection();
    friend class Commodity_Collection_Pointer;
    bool ReadFile(string);
    bool WriteFile(string);
    bool CreateGoods(Commodity);
    bool DeleteGoods(string);
    bool Sort_ID(int, int);
    bool Sort_Name(int, int);
    bool Sort_Price(int, int);
    Commodity *Find(string);
    int GetSize();
    void Print(string);
    void Print_Name(string, Commodity_Collection_Pointer &);
    void Print_Manufacturer(string, Commodity_Collection_Pointer &);

protected:
    vector<Commodity> CommodityCollection;
};

class Commodity_Collection_Pointer
{
public:
    Commodity_Collection_Pointer();
    ~Commodity_Collection_Pointer();
    bool CreateGoods(Commodity *);
    Commodity_Collection_Pointer &operator=(Commodity_Collection &);
    Commodity *SearchGoods_Num(int);
    Commodity *SearchGoods_ID(int);
    Commodity *SearchGoods_Name(string);

protected:
    vector<Commodity *> CommodityCollectionPointer;
};

class All_Commodity
{
public:
    All_Commodity();
    ~All_Commodity();
    bool ReadFile();
    bool ReadFile(string, string, string, string);
    bool WriteFile();
    bool WriteFile(string, string, string, string);
    Commodity_Collection &Judge_Category(string);
    Commodity *Find(string, string);
    Commodity *Locate(string);
    bool CreateGoods(string, Commodity);
    bool DeleteGoods(string, string);
    bool Sort(string, string);
    Commodity_Collection_Pointer Print_Category(string);
    Commodity_Collection_Pointer Print_Name(string);
    Commodity_Collection_Pointer Print_Manufacturer(string);

protected:
    Commodity_Collection Foodstuffs, Cosmetics, Necessities, Drinks;
};

class Records
{
public:
    Records(string = "", int = 0, float = 0, DateRecord = DateRecord());
    ~Records();
    friend class Records_Collection;
    friend ostream &operator<<(ostream &, Records &);
    bool Set(string, int, float);

protected:
    string GoodsName;
    int Count;
    float Price;
    DateRecord Date;
};

class Records_Collection
{
public:
    Records_Collection();
    ~Records_Collection();
    bool ReadFile(string, All_Commodity &);
    bool WriteFile(string);
    bool CreateRecord(Records);
    bool DeleteRecord(int, All_Commodity &);
    bool UpdateRecord_Goods(int, string, All_Commodity &);
    bool UpdateRecord_Count(int, int, All_Commodity &);
    bool UpdateRecord_Price(int, float);
    bool Sort_Date(int,int);
    bool Sort_Name(int,int, All_Commodity &);
    bool Sort_Price(int,int);
    bool Sort_Count(int,int);
    int GetSize();
    void Print();

protected:
    vector<Records> RecordsCollection;
};

#endif