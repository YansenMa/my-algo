#include<iostream>
#include<set>

using namespace std;

class Solution {
	public:
		int totalFruit(vector<int>& fruits) {
			if(fruits.size() == 0 ){
				return 0 ;
			}

			int max = 0;
			int curr = 0;
			set<int> set;
			set.insert(fruits[0]);
			for(int start = 0; start < fruits.size(); start++ )
			{
				for(int end = start + 1; end < fruits.size(); end ++){
					set.insert(fruits[end]);
					if(set.size() > 2){
						// clear set, update the max and move forward
						if(max < curr){
							max = curr;
						}	
						set.clear();
						continue;
					}
					curr++;
				}
			}
			return max;
		}
};



int main(){
	vector<int> test1; 
	test1.push_back(1);
	test1.push_back(2);
	test1.push_back(1);
	Solution s;
	int res = s.totalFruit(test1);
	cout << " the output is : " << res << endl;
	return 1;
}
