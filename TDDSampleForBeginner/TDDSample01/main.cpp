#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(TestCastTest, Test01)
{
    ASSERT_TRUE(true);
}

int main(int argc, char **argv)
{
   ::testing::GTEST_FLAG(print_time) = true;

	testing::InitGoogleMock(&argc, argv);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

using std::wstring;
unsigned int CharToNumber(const wchar_t strChar);
wchar_t NumberToChar(unsigned int uiNumber);

unsigned int TextToNumber(const wstring& strText)
{
    unsigned int uiCurrentNumber = 0;
    unsigned int uiResultNumber = 0;
    unsigned int uiMul = 1;
    for (unsigned int ui = 0 ; ui < strText.length() ; ui++)
    {
        unsigned int uiCurrentPosition = strText.length() - ui - 1;
        uiCurrentNumber = CharToNumber(strText.at(uiCurrentPosition));

        uiResultNumber += uiCurrentNumber * uiMul;
        uiMul *= 10;
    }

    return uiResultNumber;
}

wstring NumberToText(unsigned int uiNumber)
{
    unsigned int uiDigit = 0;
    unsigned int uiMul = 1;
    unsigned int uiCurrentNumber = uiNumber;
    while (uiCurrentNumber)
    {
        uiCurrentNumber /= 10;
        uiDigit++;
        uiMul *= 10;
    }

    unsigned int uiDiv = uiNumber;
    wstring strResult;
    for (unsigned int ui = uiDigit ; ui > 0 ; ui--)
    {
        uiMul /= 10;

        uiCurrentNumber = uiDiv / uiMul;
        uiDiv -= (uiCurrentNumber * uiMul);
        strResult += NumberToChar(uiCurrentNumber);
    }

    return strResult;
}

wstring AddTwoText(const wstring& strArg1, const wstring& strArg2)
{
    unsigned int uiArg1 = TextToNumber(strArg1);
    unsigned int uiArg2 = TextToNumber(strArg2);
    unsigned int uiResult = uiArg1 + uiArg2;
    return NumberToText(uiResult);
}

unsigned int CharToNumber(const wchar_t strChar)
{
    if (strChar == L'D')
        return 1;
    else if (strChar == L'E')
        return 2;
    else if (strChar == L'N')
        return 3;
    else if (strChar == L'R')
        return 4;
    else if (strChar == L'Y')
        return 5;

    return 0;
}

wchar_t NumberToChar(unsigned int uiNumber)
{
    if (uiNumber == 1)
        return L'D';
    else if (uiNumber == 2)
        return L'E';
    else if (uiNumber == 3)
        return L'N';
    else if (uiNumber == 4)
        return L'R';
    else if (uiNumber == 5)
        return L'Y';

    return L'';
}

TEST(AddedText_Tester, test01)
{
    //// SEND + MORE = MONEY(M > 0)
    //int iNumber = GetNumberFromChar('s');
    //char strText = GetCharFromNumber(iNumber);

    wstring strResult = AddTwoText(L"D", L"E");
    EXPECT_STREQ(L"Y", strResult.c_str());

    strResult = AddTwoText(L"ND", L"RE");
    EXPECT_STREQ(L"EY", strResult.c_str());
}
