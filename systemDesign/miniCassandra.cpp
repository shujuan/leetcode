/**
 * Definition of Column:
 * class Column {
 * public:
 *     int key;
 *     String value;
 *     Column(int key, string value) {
 *         this->key = key;
 *         this->value = value;
 *    }
 * }
 */


class MiniCassandra {
public:
    unordered_map<string, map<int,string>>info;
    MiniCassandra() {
        // do intialization if necessary
    }

    /*
     * @param row_key: a string
     * @param column_key: An integer
     * @param value: a string
     * @return: nothing
     */
    void insert(string &row_key, int column_key, string &value) {
        // write your code here
       
        info[row_key][column_key] = value;
        
    }

    /*
     * @param raw_key: a string
     * @param column_start: An integer
     * @param column_end: An integer
     * @return: a list of Columns
     */
    vector<Column> query(string &row_key, int column_start, int column_end) {
        // write your code here
       
        vector<Column>res;
        for(auto it = info[row_key].lower_bound(column_start); it != info[row_key].end() && it->first <=column_end; it++) {
            
            res.push_back(Column(it->first, it->second));
        }
        return res;
        
        
    }
};
