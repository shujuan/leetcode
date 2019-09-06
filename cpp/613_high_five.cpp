/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
 bool cmp(Record& a, Record& b) {
     return a.id < b.id||(a.id == b.id && a.score> b.score);
 }
class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        // Write your code here
        sort(results.begin(), results.end(), cmp);
        map<int, double>mp;
        int sum = 0, cnt=0;
        for(int i=0; i<results.size(); i++) {
            if(!mp.count(results[i].id) ){
                sum += results[i].score;
                cnt++;
                if(cnt ==5) {
                    mp[results[i].id] = sum/5.0;
                    cnt =0;
                    sum = 0;
                }
            }
        }
        return mp;
    }
};
