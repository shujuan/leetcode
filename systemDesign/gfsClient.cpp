/* Definition of BaseGFSClient
 * class BaseGFSClient {
 * private: map<string, string> chunk_list;
 * public:
 *     string readChunk(string& filename, int chunkIndex) {
 *         // Read a chunk from GFS
 *     }
 *     void writeChunk(string& filename, int chunkIndex,
 *                     string& content) {
 *         // Write a chunk to GFS     
 *     }
 *  };
 */


class GFSClient : public BaseGFSClient {
    unordered_map<string, int>fileTochunk;
    int chunkSZ;
public:
    /*
    * @param chunkSize: An integer
    */GFSClient(int chunkSize) {
        // do intialization if necessary
        chunkSZ = chunkSize;
    }

    /*
     * @param filename: a file name
     * @return: conetent of the file given from GFS
     */
    string read(string &filename) {
        // write your code here
        string res;
        int n = fileTochunk[filename];
        for(int i=0; i<n; i++){
            res += BaseGFSClient::readChunk(filename, i);
        }
        return res;
    }

    /*
     * @param filename: a file name
     * @param content: a string
     * @return: nothing
     */
    void write(string &filename, string &content) {
        // write your code here
        int n= (content.size()-1)/chunkSZ+1;
        string tmp;
        
        fileTochunk[filename] = n;
        for(int i=0; i<n; i++) {
            tmp = content.substr(i*chunkSZ, chunkSZ);
            BaseGFSClient::writeChunk(filename, i, tmp);
          
        }
       
       
    }
};
