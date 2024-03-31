#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<functional>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //特征归类 --> 哈希表
        unordered_map<int, int> mp;
        for (auto t : nums) {
            mp[t]++;
        }
        int res = 0;
        for (auto t : nums) {
            if (mp[t - 1]) continue; //不是起点直接跳过 枚举起点
            int len = 1;
            while (mp[++t]) len++;
            res = max(res, len);
        }

        return res;
    }
};
//class Solution {
//public:
//    int longestConsecutive(vector<int>& nums) {
//        if (nums.empty())
//            return 0;
//        sort(nums.begin(), nums.end());
//        int max = 1;
//        for (auto it = nums.begin(); it < nums.end(); it++)
//        {
//            int ret = 1;
//            while (*it == *(it + 1) - 1)
//            {
//                ret++;
//                it++;
//            }
//            if (ret > max)
//            {
//                max = ret;
//            }
//            ret = 0;
//        }
//        return max;
//    }
//};
//class Solution {
//public:
//    bool isValidSudoku(vector<vector<char>>& board) {
//        int row[9][10] = { 0 };
//        int col[9][10] = { 0 };
//        int box[9][10] = { 0 };
//        for (int i = 0; i < 9; i++)
//        {
//            for(int j = 0; j < 9; j++) {
//                if (board[i][j] == '.')
//                    continue;
//                int thisnum = board[i][j] - '0';
//                if (row[i][thisnum])return false;
//                if (col[j][thisnum])return false;
//                if (box[i/3*3+j/3][thisnum])return false;
//                row[i][thisnum] = 1;
//                col[j][thisnum] = 1;
//                box[i / 3 * 3 + j / 3][thisnum] = 1;
//            }
//        }
//        return true;
//    }
//class Solution {
//public:
//    bool isValidSudoku(vector<vector<char>>& board) {
//        map<char, int>m1, m2, m3;
//        for (int i = 0; i < 9; i++)
//        {
//            for (int j = 0; j < 9; j++)
//            {
//                if (board[i][j] != '.')
//                {
//                    if (m1[board[i][j]]) return false;
//                }
//                if (board[j][i] != '.')
//                {
//                    if (m2[board[j][i]]) return false;
//                }
//                if (board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3])
//                {
//                    if (m3[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]]) return false;
//                }
//                m1[board[i][j]] = 1;
//                m2[board[j][i]] = 1;
//                m3[board[i/3*3][i%3*3+j%3]] = 1;
//            }
//        }
//        return true;
//    }
//};