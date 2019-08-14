/**
 * Definition of Document:
 * class Document {
 * public:
 *     int id;
 *     string content;
 * }
 */
class Solution {
public:
    /**
     * @param docs a list of documents
     * @return an inverted index
     */
    map<string, vector<int>> invertedIndex(vector<Document>& docs) {
        // Write your code here
        map<string, vector<int>>res;
        for(auto doc : docs) {
            istringstream in(doc.content);
            string tmp;
            while(in>>tmp) {
                if(res.count(tmp) &&res[tmp].back() != doc.id) {
                    res[tmp].push_back(doc.id);
                }else if(!res.count(tmp)) {
                    res[tmp] = vector<int>{doc.id};
                }
            }
        }
        return res;
        
    }
};
