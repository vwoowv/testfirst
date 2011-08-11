#include "MCMoneyTester.h"

// 테스트 주도 개발에 있는 예제 따라 가기

// ToDo 정리
// 목표
// 1. 통화가 다른 두 금액을 더해서 주어진 환율에 맞게 변한 금액을 결과로 얻을 수 있어야 한다.
// 2. 어떤 금액(주가)을 어떤 수(주식의 수)에 곱한 금액을 결과로 얻을 수 있어야 한다.

// ToDo
// $5 + 10Chf = $10(환율이 2:1)
// $5 * 2 = $10
// amount 노출 제거(private으로 전환)
// Times 함수 변경. 결과의 객체화
// 객체끼리의 비교

CMCMoneyTester::CMCMoneyTester(void)
{
}

CMCMoneyTester::~CMCMoneyTester(void)
{
}

class CDollar
{
public:
    CDollar(int iAmount);
    virtual ~CDollar(void) {}

    CDollar Times(int iMul);
    bool Equal(CDollar& rValue);

private:
    int amount; 
};

CDollar::CDollar(int iAmount) : amount(0)
{
    amount = iAmount;
}

CDollar CDollar::Times(int iMul)
{
    CDollar mutiValue(amount * iMul);
    return mutiValue;
}

bool CDollar::Equal(CDollar& rValue)
{
    return true;
}

TEST_F(CMCMoneyTester, TestMultiplication)
{
    // 5 * 2 = 10
    CDollar Five(5);
    CDollar Result = Five.Times(2);
    CDollar Ten(10);
    ASSERT_EQ(true, Ten.Equal(Result));
}
