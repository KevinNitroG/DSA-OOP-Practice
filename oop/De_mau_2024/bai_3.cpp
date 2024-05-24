#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

enum He
{
    NUOC,
    LUA,
    DAT,
    CO
};

map<pair<He, He>, int> KHAC{{{NUOC, LUA}, 0}, {{LUA, CO}, 1},  {{CO, DAT}, 2},
                            {{DAT, NUOC}, 3}, {{CO, NUOC}, 4}, {{DAT, LUA}, 5}};

class Pokemon
{
  private:
    int cong;
    int mau;
    He he;

  public:
    void Nhap()
    {
        cout << "Nhap cong: ";
        cin >> this->cong;
        cout << "Nhap mau: ";
        cin >> this->mau;
        cout << "Nhap he: ";
        int temp;
        cin >> temp;
        this->he = static_cast<He>(temp);
    }

    void Xuat()
    {
        cout << "Cong: " << this->cong << endl;
        cout << "Mau: " << this->mau << endl;
        cout << "He: " << this->he << endl;
    }

    bool operator<(const Pokemon &rhs)
    {
        int condition = 0;
        Pokemon a, b;
        pair<Pokemon, Pokemon> returnPair = this->modify(*this, rhs);
        a = returnPair.first;
        b = returnPair.second;
        // So sanh
        if (a.cong < b.cong)
            condition++;
        if (a.mau < b.mau)
            condition++;
        pair<He, He> heKhacAvaB{a.he, b.he};
        if (KHAC.find(heKhacAvaB) == KHAC.end())
            condition++;
        return condition >= 2;
    }

    bool operator==(const Pokemon &rhs)
    {
        Pokemon a, b;
        pair<Pokemon, Pokemon> returnPair = this->modify(*this, rhs);
        a = returnPair.first;
        b = returnPair.second;
        return (a.cong == b.cong) && (a.mau == b.mau);
    }

    static pair<Pokemon, Pokemon> modify(const Pokemon &lhs, const Pokemon &rhs)
    {
        if (lhs.he == rhs.he)
            return {lhs, rhs};
        Pokemon a{lhs}, b{rhs};
        pair<He, He> he{lhs.he, rhs.he};
        bool haveSwitched = false;
        if (KHAC.find(he) == KHAC.end())
        {
            he = {rhs.he, lhs.he};
            swap(a, b);
            haveSwitched = true;
        }
        switch (KHAC[he])
        {
        case 0: {
            a.cong = a.cong * 120 / 100;
            break;
        }
        case 1: {
            a.cong = a.cong * 125 / 100;
            break;
        }
        case 2: {
            a.cong = a.cong * 115 / 100;
            break;
        }
        case 3: {
            a.cong = a.cong * 130 / 100;
            break;
        }
        case 4: {
            a.cong = a.cong * 110 / 100;
            break;
        }
        case 5: {
            a.cong = a.cong * 135 / 100;
            break;
        }
        }
        if (haveSwitched)
            swap(a, b);
        return {a, b};
    }
};

class Pokemons
{
  private:
    vector<Pokemon> dsPokemons;

  public:
    void Nhap()
    {
        int n;
        cout << "Nhap so luong pokemon: ";
        cin >> n;
        // Quy uoc
        cout << "[0]: Nuoc" << endl;
        cout << "[1]: Lua" << endl;
        cout << "[2]: Dat" << endl;
        cout << "[3]: Co" << endl;
        for (int i = 0; i < n; i++)
        {
            Pokemon temp;
            temp.Nhap();
            dsPokemons.push_back(temp);
        }
    }

    void Xuat()
    {
        for (auto &pokemon : dsPokemons)
            pokemon.Xuat();
    }

    vector<Pokemon> timCacPokeMonManhNhat()
    {
        vector<Pokemon> newPokemons{this->dsPokemons};
        sort(newPokemons.begin(), newPokemons.end());
        Pokemon pokemonManhnhat = newPokemons[newPokemons.size() - 1];
        vector<Pokemon> pokemonsToReturn;
        for (auto &pokemon : newPokemons)
            if (pokemon == pokemonManhnhat)
                pokemonsToReturn.push_back(pokemon);
        return pokemonsToReturn;
    }
};

int main()
{
    Pokemons pokemons;
    pokemons.Nhap();

    cout << endl << "Cac Pokemons" << endl;
    pokemons.Xuat();

    cout << endl << "Cac Pokemons manh nhat: " << endl;
    for (auto &pokemon : pokemons.timCacPokeMonManhNhat())
        pokemon.Xuat();
    return 0;
}
