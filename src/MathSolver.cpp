#include "MathSolver.h"
using namespace std;
vector<long long> MathSolver::generateFibonacci(int n)
{
    if (n <= 0)
        return {};
    if (n == 1)
        return {0};

    vector<long long> fib = {0, 1};
    fib.reserve(n + 1);
    for (int i = 2; i < n; ++i)
    {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
    return fib;
}

bool MathSolver::isPalindrome(int x)
{
    if (x < 0)
        return false;
    long long original = x;
    long long reversed = 0;

    while (x != 0)
    {
        reversed = reversed * 10 + (x % 10);
        x /= 10;
    }
    return original == reversed;
}

ListNode *MathSolver::reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

vector<int> MathSolver::listToVector(ListNode *head)
{
    vector<int> vec;
    ListNode *temp = head;
    while (temp)
    {
        vec.push_back(temp->val);
        temp = temp->next;
    }
    return vec;
}