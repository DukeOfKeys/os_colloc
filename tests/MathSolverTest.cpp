#include "gtest/gtest.h"
#include "../include/MathSolver.h"

ListNode *createList(const std::vector<int> &values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void deleteList(ListNode *head)
{
    ListNode *current = head;
    while (current)
    {
        ListNode *next = current->next;
        delete current;
        current = next;
    }
}

TEST(FibonacciTest, BaseAndEdgeCases)
{
    MathSolver solver;

    EXPECT_TRUE(solver.generateFibonacci(0).empty());

    EXPECT_EQ((std::vector<long long>{0}), solver.generateFibonacci(1));

    EXPECT_EQ((std::vector<long long>{0, 1}), solver.generateFibonacci(2));
}

TEST(FibonacciTest, StandardSequence)
{
    MathSolver solver;
    std::vector<long long> expected = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    EXPECT_EQ(expected, solver.generateFibonacci(10));
}

TEST(FibonacciTest, LargeNumberCheck)
{
    MathSolver solver;
    std::vector<long long> result = solver.generateFibonacci(25);
    EXPECT_EQ(46368, result[24]);
}

TEST(PalindromeTest, SingleDigitAndZero)
{
    MathSolver solver;
    ASSERT_TRUE(solver.isPalindrome(0));
    ASSERT_TRUE(solver.isPalindrome(5));
}

TEST(PalindromeTest, PositiveCases)
{
    MathSolver solver;

    ASSERT_TRUE(solver.isPalindrome(1221));
    ASSERT_TRUE(solver.isPalindrome(9009));

    ASSERT_TRUE(solver.isPalindrome(121));
    ASSERT_TRUE(solver.isPalindrome(10101));
}

TEST(PalindromeTest, NegativeAndNonPalindromeCases)
{
    MathSolver solver;

    ASSERT_FALSE(solver.isPalindrome(-121));
    ASSERT_FALSE(solver.isPalindrome(-1));

    ASSERT_FALSE(solver.isPalindrome(123));
    ASSERT_FALSE(solver.isPalindrome(10)); // 01
}

TEST(PalindromeTest, LargeNumbers)
{
    MathSolver solver;
    ASSERT_TRUE(solver.isPalindrome(2147447412));
    ASSERT_FALSE(solver.isPalindrome(2147483647));
}

TEST(ReverseListTest, EmptyList)
{
    MathSolver solver;
    ListNode *head = nullptr;

    EXPECT_EQ(nullptr, solver.reverseList(head));
}

TEST(ReverseListTest, SingleNode)
{
    MathSolver solver;
    ListNode *head = createList({5});

    ListNode *reversed_head = solver.reverseList(head);
    std::vector<int> expected = {5};
    EXPECT_EQ(expected, solver.listToVector(reversed_head));
    deleteList(reversed_head);
}

TEST(ReverseListTest, StandardCase)
{
    MathSolver solver;
    ListNode *head = createList({1, 2, 3, 4, 5});

    ListNode *reversed_head = solver.reverseList(head);

    std::vector<int> expected = {5, 4, 3, 2, 1};
    EXPECT_EQ(expected, solver.listToVector(reversed_head));
    deleteList(reversed_head);
}

TEST(ReverseListTest, TwoNodes)
{
    MathSolver solver;
    ListNode *head = createList({10, 20});

    ListNode *reversed_head = solver.reverseList(head);
    std::vector<int> expected = {20, 10};
    EXPECT_EQ(expected, solver.listToVector(reversed_head));
    deleteList(reversed_head);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}