#include "MCMoneyTester.h"

// �׽�Ʈ �ֵ� ���߿� �ִ� ���� ���� ����

// ToDo ����
// ��ǥ
// 1. ��ȭ�� �ٸ� �� �ݾ��� ���ؼ� �־��� ȯ���� �°� ���� �ݾ��� ����� ���� �� �־�� �Ѵ�.
// 2. � �ݾ�(�ְ�)�� � ��(�ֽ��� ��)�� ���� �ݾ��� ����� ���� �� �־�� �Ѵ�.

// ToDo
// $5 + 10Chf = $10(ȯ���� 2:1)
// $5 * 2 = $10

CMCMoneyTester::CMCMoneyTester(void)
{
}

CMCMoneyTester::~CMCMoneyTester(void)
{
}

TEST_F(CMCMoneyTester, TestMultiplication)
{
    // 5 * 2 = 10
    CDollar* pFive = new CDollar(5);
    pFive->Times(2);
    ASSERT_EQ(10, pFive->amount);
}
