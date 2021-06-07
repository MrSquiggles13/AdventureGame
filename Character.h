#pragma once 
#include "Inventory.h"
#include "Spells.h"

class Character : public Inventory
{
private:
    std::string m_name;
    int m_difficulty;
    std::string m_class;
    std::string m_alignment;
    int m_lvl;

    Inventory m_inv;
    Weapon m_wep;
    Armour m_arm;
    Potions m_pots;
    std::vector<Spells*> m_spellBook;
    int m_gold;

    int m_posMain;
    int m_posSide;

    int m_AC;
    int m_boostAC;
    int m_damageMin;
    int m_damageMax;
    int m_initiative;
    int m_health;
    int m_healthMax;
    int m_stamina;
    int m_staminaMax;
    int m_magica;
    int m_magicaMax;
    int m_expCurrent;
    int m_expNext;

    int m_mapX;
    int m_mapY;
    int m_movement;
    int m_turnOrder;
    bool m_isAlive;

    int m_str;
    int m_con;
    int m_dex;
    int m_wis;
    int m_intl;
    int m_chrs;
    int m_luck;

    int m_accuracy;
    int m_appraise;
    int m_deftness;
    int m_engineering;
    int m_espionage;
    int m_handleAnimals;
    int m_influence;
    int m_medicinal;
    int m_perception;

    int m_skillPoints;
    int m_statPoints;

public:
    Character(
        std::string name = "",
        int difficulty = 0,
        std::string charClass = "",
        std::string alignment = "",
        int lvl = 1,

        int gold = 100,

        int posMain = 0,
        int posSide = 0,

        int AC = 10,
        int damageMin = 0,
        int damageMax = 2,
        int initiative = 0,
        int health = 20,
        int healthMax = 20,
        int stamina = 10,
        int staminaMax = 10,
        int magica = 10,
        int magicaMax = 10,
        int expCurrent = 0,
        int expNext = 100,

        int movement = 2,
        int turnOrder = 0,
        bool isAlive = true,

        int str = 0,
        int con = 0,
        int dex = 0,
        int wis = 0,
        int intl = 0,
        int chrs = 0,
        int luck = 0,

        int accuracy = 0,
        int appraise = 0,
        int deftness = 0,
        int engineering = 0,
        int espionage = 0,
        int handleAnimals = 0,
        int influence = 0,
        int medicinal = 0,
        int perception = 0,

        int skillPoints = 0,
        int statPoints = 0);

    //Print Difficulty
    inline const std::string printDiff(int diff)
    {
        switch (diff)
        {
        case 1:
            return "Easy";
        case 2:
            return "Normal";
        case 3:
            return "Hard";
        case 4:
            return "Very Hard";
        default:
            return "invalid Choice";
        }
    }

    //Create Character
    std::string_view selectCharClass();
    bool charDescription(std::string_view userChar);
    void assignCharClass();
    void pickCharName();
    void rollForStats();
    int validateRoll(std::array<int, 7>& rolls);
    void validateStat(int selectRoll, std::array<int, 7>& rolls);
    void assignRolls(std::array<int, 7>& rolls);
    void alignment();
    void difficulty();
    void setBoosts();

    void addEquipment();

    void printStats();
    void manageInv();
    void lvlUp();
    void addSpell(Spells& spell);




    inline const int& getStrength() const { return m_str; }
    inline const int& getDexterity() const { return m_dex; }
    inline const int& getLuck() const { return m_luck; }
    inline const int& getAccuracy() const { return m_accuracy; }
    inline const int& getAppraise() const { return m_appraise; }
    inline const int& getDeftness() const { return m_deftness; }
    inline const int& getEngineering() const { return m_engineering; }
    inline const int& getEspionage() const { return m_espionage; }
    inline const int& getHandleAnimals() const { return m_handleAnimals; }
    inline const int& getInfluence() const { return m_influence; }
    inline const int& getMedicinal() const { return m_medicinal; }
    inline const int& getPerception() const { return m_perception; }
    inline const int& getAC() const { return m_AC; }
    inline const int& getACboost() { return m_boostAC; }
    inline const void setACboost() { m_boostAC +=  4; }
    inline const void resetACboost() { m_boostAC = m_AC; }
    inline const int& getHealth() const { return m_health; }
    inline const int& getHealthMax() const { return m_healthMax; }
    inline const int& getStam() const { return m_stamina; }
    inline const int& getStamMax() const { return m_staminaMax; }
    inline const int& getMag() const { return m_magica; }
    inline const int& getMagMax() const { return m_magicaMax; }
    inline const int& getLvl() const { return m_lvl; }
    inline const int& getDifficulty() const { return m_difficulty; }
    inline const void setTurnOrder(int turnOrder) { m_turnOrder += turnOrder; }
    inline const int& getTurnOrder() const { return m_turnOrder; }
    inline const int& getMapX() { return m_mapX; }
    inline const int& getMapY() { return m_mapY; }
    inline const void setMapX(int coord) { m_mapX += coord; }
    inline const void setMapY(int coord) { m_mapY += coord; }
    inline const void setStartMapX(int coord) { m_mapX = coord; }
    inline const void setStartMapY(int coord) { m_mapY = coord; }
    inline const int& getMove() { return m_movement; }
    inline const void setPosMain() { m_posMain++; }
    inline const void setPosSide() { m_posSide++; }
    inline const void setDead() { m_isAlive = false; }
    inline const bool& getIsAlive() { return m_isAlive; }
    inline const void setGold(int gold) { m_gold += gold; }
    inline const void loseGold(int gold) { m_gold -= gold; }
    inline const int& getExpCurrent() const { return m_expCurrent; }
    inline const int& getExpNext() const { return m_expNext; }
    inline const void setExp(int exp) { m_expCurrent += exp; }
    inline  Weapon getWeapon() { return m_wep; }
    inline  Armour getArmour() { return m_arm; }
    inline const int& getDamageMin() const { return m_damageMin; }
    inline const int& getDamageMax() const { return m_damageMax; }

    inline const void takeDamage(int& damage) { m_health -= damage; }
    inline void equipWeapon(Weapon wep) 
    {
        m_wep = wep; 
        m_damageMin = wep.getDamageMin() + ((m_str - 10) / 2); 
        m_damageMax = wep.getDamageMax() + ((m_str - 10) / 2);
        if (m_damageMax <= 0)
            m_damageMax = 1;
        if (m_damageMin <= 0)
            m_damageMin = 1;
    }
    inline void equipArmour(Armour arm) { m_arm = arm; m_AC = arm.getACbonus() + 10 + ((m_dex - 10) / 2); }
    ~Character();
};