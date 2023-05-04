#ifndef INPUT_H
#define INPUT_H

#include <conio.h>
#include <string>
#include <vector>


constexpr auto KEY_ESC = 0x1B;
constexpr auto KEY_1 = 0x31;
constexpr auto KEY_2 = 0x32;
constexpr auto KEY_3 = 0x33;
constexpr auto KEY_4 = 0x34;
constexpr auto KEY_5 = 0x35;
constexpr auto KEY_6 = 0x36;
constexpr auto KEY_7 = 0x37;
constexpr auto KEY_8 = 0x38;
const double DBL_WRONG = 100000000000000000;

enum InputMenu
{
    FILE_INPUT = KEY_1,
    MANUAL_INPUT = KEY_2,
    MODUL_TESTS = KEY_3,
    RANDOM_INPUT = KEY_4
};

enum MenuCW
{
    CW1 = KEY_1,
    CW2 = KEY_2,
    CW3 = KEY_3,
    CW4 = KEY_4,
    QUIT = KEY_ESC
};

enum BoolMenu
{
    YES = KEY_1,
    NO = KEY_2
};

enum BoolInput
{
    WITHOUT_DIGITS,
    WITH_DIGITS,
    ONLY_DIGITS,
    ALMOST_ALL_DIGITS,
    CW4_INPUT
};

enum MainMenuCW1
{
    ALPH_SEARCH = KEY_1,
    CARD_SEARCH = KEY_2,
    ADDorMODIFY = KEY_3,
    SAVE = KEY_4
};

enum MainMenuCW2
{
    SHOW = KEY_1,
    ADDorMODIFYCW2 = KEY_2,
    SAVECW2 = KEY_3
};

enum MainMenuCW3
{
    SAVECW3 = KEY_2
};

enum MainMenuCW4
{
    ENTRY_LENGTH = KEY_1,
    SHOW_RESTORED = KEY_2,
    SHOW_MODIFIED = KEY_3,
    SAVE_RESTORED = KEY_4,
    SAVE_MODIFIED = KEY_5
};

enum SubMenuCW1
{
    ADD = KEY_1,
    MODIFY = KEY_2,
};

enum ModMenuCW1
{
    MOD_NAME = KEY_1,
    MOD_ADDRESS = KEY_2,
    MOD_CONTACT = KEY_3,
    DELETE = KEY_4
};

enum ModMenuCW2
{
    MOD_SURNAME = KEY_1,
    MOD_GENDER = KEY_2,
    MOD_ADDRESSCW2 = KEY_3,
    MOD_POSITION = KEY_5,
    MOD_DEPARTMENT = KEY_6,
    MOD_RESPONSIBILITIES = KEY_7,
    MOD_SALARY = KEY_8,
};

enum IsEmployeeOrPersonality
{
    PERSONALITY,
    EMPLOYEE
};

enum SORTS
{
    BUBBLE_SORT,
    SELECTION_SORT,
    INSERTION_SORT,
    SHELL_SORT,
    QUICK_SORT
};

int GetKey(int key_min, int key_max);

int GetPosInt();
size_t GetSubstringSize();
int GetInt();
int GetRandInt(int lowBound, int upBound);

double GetDouble();
double GetPosDouble();

long long GetPosLongLong();
long long GetLongLong();

bool GetBool();

std::string GetLine(std::istream& _Input, std::string& line, int num_exists, int isInput);

size_t GetMaxNumLength(std::vector<std::vector<int>> matrix, int rows, int columns);
void ShowColoredNum(int& num, size_t max_num_length, int white);

#endif