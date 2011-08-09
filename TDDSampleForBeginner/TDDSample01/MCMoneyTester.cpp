﻿#include "MCMoneyTester.h"

// 테스트 주도 개발에 있는 예제 따라 가기

// ToDo 정리
// 목표
// 1. 통화가 다른 두 금액을 더해서 주어진 환율에 맞게 변한 금액을 결과로 얻을 수 있어야 한다.
// 2. 어떤 금액(주가)을 어떤 수(주식의 수)에 곱한 금액을 결과로 얻을 수 있어야 한다.

// ToDo
// $5 + 10Chf = $10(환율이 2:1)
// $5 * 2 = $10
// amount 노출 제거(private으로 전환)
// Times 함수 변경

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

    int Times(int iMul);

private:
    int amount; 
};

CDollar::CDollar(int iAmount) : amount(0)
{
    amount = iAmount;
}

int CDollar::Times(int iMul)
{
    return amount *= iMul;
}

TEST_F(CMCMoneyTester, TestMultiplication)
{
    // 5 * 2 = 10
    CDollar* pFive = new CDollar(5);
    int iResult = pFive->Times(2);
    ASSERT_EQ(10, iResult);
}
