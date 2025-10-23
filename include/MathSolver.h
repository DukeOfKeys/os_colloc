#pragma once

#include <vector>
#include <algorithm>
#include <cmath>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class MathSolver
{
public:
    std::vector<long long> generateFibonacci(int n);

    bool isPalindrome(int x);

    ListNode *reverseList(ListNode *head);

    std::vector<int> listToVector(ListNode *head);
};