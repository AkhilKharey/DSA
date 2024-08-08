#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class InvalidInputException : public runtime_error
{
public:
    InvalidInputException(const string &message) : runtime_error(message) {}
};

class NumberManipulation
{
private:
    int digits[9];

public:
    void extractDigits(const string &number)
    {
        if (number.length() != 9)
        {
            throw InvalidInputException("Invalid Input Exception: ISBN must be exactly 9 digits");
        }

        for (int i = 0; i < 9; ++i)
        {
            if (!isdigit(number[i]))
            {
                throw InvalidInputException("Input must contain only digits");
            }
            digits[i] = number[i] - '0';
        }
    }

    char findLastDigit()
    {
        int sum = 0;
        for (int i = 0; i < 9; ++i)
        {
            sum += digits[i] * (i + 1);
        }

        int checksum = sum % 11;

        if (checksum == 10)
        {
            return 'X';
        }
        else
        {
            return checksum + '0';
        }
    }
};

int main()
{
    string input;
    cin >> input;

    NumberManipulation nm;

    try
    {
        nm.extractDigits(input);
        char lastDigit = nm.findLastDigit();
        string fullISBN = input + lastDigit;
        cout << "ISBN : " << fullISBN << endl;
    }
    catch (const InvalidInputException &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
