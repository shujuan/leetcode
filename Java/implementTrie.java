class TrieNode{
    boolean isWord;
    TrieNode[] child= new TrieNode[26];
    public TrieNode(){
        isWord = false;
    }
    
}


class Trie {
    TrieNode root;
    /** Initialize your data structure here. */
    public static void main(String[] args) {
        Trie test = new Trie();
        test.insert("apple");
        System.out.println(test.search("apple"));
        System.out.println(test.startsWith("app"));
    }


    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode tmp = root;
        char[] words = word.toCharArray();
        for(int i=0; i<words.length;i++) {
            if(tmp.child[words[i]-'a'] == null){
                tmp.child[words[i]-'a'] = new TrieNode();
            }
            tmp = tmp.child[words[i]-'a'];
        }
        tmp.isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode tmp = root;
        char[] words = word.toCharArray();
        for(int i=0; i<words.length;i++) {
            if(tmp.child[words[i]-'a'] == null){
                return false;
            }
            tmp = tmp.child[words[i]-'a'];
        }
        return tmp.isWord ;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode tmp = root;
        char[] words = prefix.toCharArray();
        for(int i=0; i<words.length;i++) {
            if(tmp.child[words[i]-'a'] == null){
                return false;
            }
            tmp = tmp.child[words[i]-'a'];
        }
        return true;
    }
}

