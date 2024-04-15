#include <iostream>
#include <set>
#include <map>
using namespace std;

/**
 * end: loop
 * start: when set.size > 2 start = last_update
 * last_update: when current.val != last_current.val, then last_update = end;
 * current_size = end - start + 1;
 * max = max > current_size ? max: current_size;
 */
// [0,1,6,6,4,4,6]
// [3,3,3,1,2,1,1,2,3,3,4]

class Solution
{
public:
    // fix :
    // 1. init lastupdate  = start
    // 2. when the current value and last value dont match, then update the lastupdate
    /**
     * if fruits.size <=2:
     *      1. start don't change
     *      2. end ++
     *      3. curr_size ++;
     *      4. last_update dont change
     *      5. max will be changed after the loop
     * else:
     *      1. curr_size = end - start + 1
     *      2. update max < curr_size ? curr_size: max;
     *      3. start = last_update
     *      4. last_update = end;
     *      5. end ++
     */
    int totalFruit(vector<int> &fruits)
    {
        // if the fruits.size is 0, then return 0;
        if (fruits.size() == 0)
        {
            return 0;
        }
        int start = 0;
        int end = 1;
        set<int> set;
        set.insert(fruits[start]);
        int curr_size = 1;
        int max = -1;
        int last_update = start;

        while (end < fruits.size())
        {
            set.insert(fruits[end]);

            if (set.size() <= 2)
            {
                // curr_size++;
                curr_size ++;
            }
            else
            {
                // there are at least 3 element inside the set, stop and do
                //    1. curr_size = end - start + 1
                //    2. update max < curr_size ? curr_size: max;
                //    3. start = last_update
                //    4. last_update = end;
                //    5. end ++
                // 1. get the current size and update max
                curr_size = end - start + 1;
                if (max < curr_size)
                {
                    max = curr_size;
                }
                start = last_update;
                last_update = end;
                set.clear();
                set.insert(fruits[start]);
                set.insert(fruits[end]);
                curr_size = end - start + 1;
            }
            if (fruits[end - 1] != fruits[end])
            {
                last_update = end;
            }
            end++;
        }
        if (max < curr_size)
        {
            max = curr_size;
        }

        return max;
    }
};

int main()
{
    vector<int> test1;
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(1);

    vector<int> test2;
    test2.push_back(0);
    test2.push_back(1);
    test2.push_back(2);
    test2.push_back(2);

    vector<int> test3;
    test3.push_back(1);
    test3.push_back(2);
    test3.push_back(3);
    test3.push_back(2);
    test3.push_back(2);

    //[3,3,3,1,2,1,1,2,3,3,4]
    vector<int> test4;
    test4.push_back(3);
    test4.push_back(3);
    test4.push_back(3);
    test4.push_back(1);
    test4.push_back(2);
    test4.push_back(1);
    test4.push_back(1);
    test4.push_back(2);
    test4.push_back(3);
    test4.push_back(3);
    test4.push_back(4);

    // [0,1,6,6,4,4,6]
    vector<int> test5;
    test5.push_back(0);
    test5.push_back(1);
    test5.push_back(6);
    test5.push_back(6);
    test5.push_back(4);
    test5.push_back(4);
    test5.push_back(6);

    Solution s;
    int res = s.totalFruit(test1);
    cout << " ============== test1 the output is : " << res << endl;
    cout << "=======================================\n=====================" << endl;
    int res2 = s.totalFruit(test2);
    cout << " test2 the output is : " << res2 << endl;
    cout << "=======================================\n=====================" << endl;
    int res3 = s.totalFruit(test3);
    cout << " test3 the output is : " << res3 << endl;
    cout << "=======================================\n=====================" << endl;
    int res4 = s.totalFruit(test4);
    cout << " test4 the output is : " << res4 << endl;
    cout << "=======================================\n=====================" << endl;
    int res5 = s.totalFruit(test5);

    cout << " test5 the output is : " << res5 << endl;
    return 1;
}
