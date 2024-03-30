#include <iostream>
#include <vector>
#include <string>

/**
 * @brief
 * Находит максимальное среди двух чисел
 * 
 * @param num1
 * первое число
 * 
 * @param num2
 * второе число
*/
void max_num(unsigned int& num1, unsigned int& num2)
{
    if (num2 > num1)
    {
        num1 = num2;
    }

    return;
}

/**
 * @brief
 * Находит букву в векторе
 * 
 * @param letter
 * буква
 * 
 * @param letters
 * вектор букв
 * 
 * @return
 * Индекс буквы в векторе
*/
long long find_in_vector(const char& letter, const std::vector<char>& letters)
{
    long long index = -1;

    for (size_t i = 0; i < letters.size(); ++i)
    {
        if (letters[i] == letter)
        {
            index = i;
            break;
        }
    }

    return index;
}

/**
 * @brief
 * Считает вес каждого слова и находит среди них маскимальный счёт
 * 
 * @param words
 * слова
 * 
 * @param letters
 * буквы
 * 
 * @param score
 * вес буквы
 * 
 * @return
 * Максимальный счёт среди слов
*/
unsigned int max_score(const std::vector<std::string>& words, const std::vector<char> &letters, const std::vector<unsigned int>& score)
{
    std::vector<char> letters_copy = letters;
    unsigned int res = 0, cnt = 0;
    size_t index;

    if (!words.empty() && !letters.empty())
    {
        for (const std::string word: words)
        {
            for (const char letter: word)
            {
                index = find_in_vector(letter, letters_copy);

                if (index != -1)
                {
                    cnt += score[letter - 97];
                    letters_copy.erase(letters_copy.begin() + index);
                }
            }

            max_num(res, cnt);
            cnt = 0;
            letters_copy = letters; // Восстановление letters для следующего слова
        }
    }

    return res;
}

int main(int, char**)
{
    std::vector<std::string> words = { "apple", "bingo", "respect" };
    std::vector<char> letters = { 'a', 'p', 'p', 'l', 'e', 'e', 'b', 'g', 'o', 'r', 'e', 's', 'p', 'c', 't' };
    std::vector<unsigned int> score(26);

    // Заполнение score рандомными значениями в диапазоне [0;10)
    for (size_t i = 0; i < 26; ++i)
    {
        score[i] = rand() % 10;
    }

    unsigned int max = max_score(words, letters, score);

    return 0;
}