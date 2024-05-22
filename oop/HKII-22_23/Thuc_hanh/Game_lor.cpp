#include <iostream>
#include <string>
using namespace std;
class Character
{
  public:
    float get_HP()
    {
        return HP;
    }
    bool is_dead()
    {
        return HP <= 0;
    }
    void attack(Character *enemy)
    {
        if (ATK > enemy->DEF)
        {
            enemy->HP = enemy->HP - (ATK - enemy->DEF);
        }
    }
    virtual void adjust()
    {
        return;
    }
    virtual void Nhap()
    {
        cin >> name >> HP >> ATK >> DEF;
    }
    void Xuat()
    {
        cout << name << " " << HP << endl;
    }
    virtual ~Character() = default;

  protected:
    static int dem_Nhan_loai;
    string name = "Unknown";
    float HP = 0.0;
    float ATK = 0.0;
    float DEF = 0.0;
};

int Character::dem_Nhan_loai = 0;
class Boss : public Character
{
};

class Nhan_loai : public Character
{
  public:
    void Nhap()
    {
        Character::Nhap();
        cin >> job;
        ++dem_Nhan_loai;
    }

  protected:
    string job = "Unknown";
};

class Ban_nhan : public Character
{
  public:
    void Nhap()
    {
        Character::Nhap();
        cin >> racial;
    }

  protected:
    string racial = "Unknown";
};

class Di_hinh : public Character
{
};

class Human : public Nhan_loai
{
};

class Elf : public Nhan_loai
{
  public:
    void adjust()
    {
        DEF = DEF * 1.5;
    }
};

class Orc : public Ban_nhan
{
  public:
    void adjust()
    {
        HP = HP * 1.5;
    }
};

class Golbin : public Ban_nhan
{
  public:
    void adjust()
    {
        ATK = ATK * 1.1;
    }
};

class Vampire : public Di_hinh
{
  public:
    void adjust()
    {
        HP = HP + HP * 0.1 * dem_Nhan_loai;
    }
};

class Devil : public Di_hinh
{
  public:
    void Nhap()
    {
        Character::Nhap();
        ++dem_Devil;
    }
    void adjust()
    {
        ATK = ATK + ATK * 0.1 * dem_Devil;
        DEF = DEF + DEF * 0.1 * dem_Devil;
    }

  protected:
    static int dem_Devil;
};

int Devil::dem_Devil = 0;
Character *init(int type)
{
    switch (type)
    {
    case 1:
        return new Human;
    case 2:
        return new Elf;
    case 3:
        return new Orc;
    case 4:
        return new Golbin;
    case 5:
        return new Vampire;
    case 6:
        return new Devil;
    }
    return new Character;
}

class Guild
{
  public:
    void Nhap()
    {
        cin >> size;
        arr = new Character *[size];
        for (int i = 0; i < size; ++i)
        {
            int loai;
            cin >> loai;
            arr[i] = init(loai);
            arr[i]->Nhap();
        }
        for (int i = 0; i < size; ++i)
        {
            arr[i]->adjust();
        }
    }
    void Xuat()
    {
        for (int i = 0; i < size; ++i)
        {
            if (!arr[i]->is_dead())
            {
                arr[i]->Xuat();
            }
        }
    }
    void attack(Character *enemy)
    {
        for (int i = 0; i < size; ++i)
        {
            if (!arr[i]->is_dead())
            {
                arr[i]->attack(enemy);
            }
        }
    }
    bool is_all_dead()
    {
        for (int i = 0; i < size; ++i)
        {
            if (!arr[i]->is_dead())
            {
                return false;
            }
        }
        return true;
    }
    Character *find_min_HP()
    {
        int min_index = 0;
        for (int i = 0; i < size; ++i)
        {
            if (!arr[i]->is_dead())
            {
                min_index = i;
                break;
            }
        }
        for (int i = 0; i < size; ++i)
        {
            if (!arr[i]->is_dead() && arr[i]->get_HP() < arr[min_index]->get_HP())
            {
                min_index = i;
            }
        }
        return arr[min_index];
    }
    void sort_HP()
    {
        for (int i = 0; i <= size - 2; ++i)
            for (int j = i + 1; j <= size - 1; ++j)
                if (arr[j]->get_HP() < arr[i]->get_HP())
                    swap(arr[i], arr[j]);
    }
    ~Guild()
    {
        delete[] arr;
    }

  private:
    int size = 0;
    Character **arr = NULL;
};
int main()
{
    Guild team;
    team.Nhap();
    Boss boss;
    boss.Nhap();
    do
    {
        team.attack(&boss);
        if (boss.is_dead())
        {
            break;
        }
        boss.attack(team.find_min_HP());
    } while (!team.is_all_dead());
    if (!boss.is_dead())
    {
        boss.Xuat();
    }
    else
    {
        team.sort_HP();
        team.Xuat();
    }
    return 0;
}
/* Test case:
3
1
Adam 100 10 10 NongDan
2 Vi 200 10 10 CungThu
6 Jacob 400 50 30
6
TRƯỜNG ĐẠI HỌC CÔNG NGHỆ THÔNG TIN – ĐHQG-HCM
BAN HỌC TẬP CÔNG NGHỆ PHẦN MỀM
Ainz 200 50 20
*/
