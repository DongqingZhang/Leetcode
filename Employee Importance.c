/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        vector<int> subs;
        for(auto a:employees){
            if(a->id == id){
                subs = a->subordinates;
                res += a->importance;
                if(subs.size() == 0) return res;
                for(auto b:subs){
                    res += getImportance(employees, b);
                }
                return res;
            }
        }
        return res;
    }
};