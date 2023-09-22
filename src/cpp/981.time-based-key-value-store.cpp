#include <string>
#include <map>
#include <vector>
#include <algorithm>

/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap
{
private:
    std::map<
        std::string,
        std::vector<
            std::pair<
                std::string,
                int>>>
        store;

public:
    TimeMap()
    {
    }

    void set(std::string key, std::string value, int timestamp)
    {
        store[key].emplace_back(std::make_pair(value, timestamp));
    }

    std::string get(std::string key, int timestamp)
    {
        if (store.find(key) != store.end())
        {
            int left = 0, right = store[key].size() - 1;
            while (left <= right)
            {
                auto middle = left + (right - left) / 2;
                if (store[key][middle].second < timestamp)
                {
                    left = middle + 1;
                }
                else if (store[key][middle].second > timestamp)
                {
                    right = middle - 1;
                }
                else
                {
                    return store[key][middle].first;
                }
            }

            if (right >= 0)
            {
                return store[key][right].first;
            }
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
