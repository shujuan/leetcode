class Stack {
    queue<int>q1;
    
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        // write your code here
        q1.push(x);
        for(int i=0; i<q1.size()-1; i++) {
            auto top = q1.front();
            q1.pop();
            q1.push(top);
        }
    }

    /*
     * @return: nothing
     */
    void pop() {
        // write your code here
        q1.pop();
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        return q1.front();
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        // write your code here
        return q1.empty();
    }
};
