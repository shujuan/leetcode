/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 */
class AnagramMapper: public Mapper {
public:
    void Map(Input<string>* input) {
        // Write your code here
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, string& value);
        while(!input->done()) {
            string words = input->value();
            istringstream in(words);
            string tmp;
            while(in >> tmp) {
                string key = tmp;
                sort(key.begin(), key.end());
                output(key, tmp);
            }
            input->next();
        }
    }
};


class AnagramReducer: public Reducer {
public:
    void Reduce(string &key, Input<string>* input) {
        // Write your code here
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, vector<string>& value);
        vector<string> val;
        while(!input->done()){
            string tmp = input->value();
            val.push_back(tmp);
            input->next();
        }
        output(key, val);
        
    }
};
