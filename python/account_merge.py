class Solution:
    """
    @param accounts: List[List[str]]
    @return: return a List[List[str]]
    """
    
    
    def get_id_to_email_set(self, accounts):
        id_to_email_set = {}
        for user_id, account in enumerate(accounts):
            root_user_id = self.find(user_id)
            email_set = id_to_email_set.get(root_user_id, set())
            for email in account[1:]:
                email_set.add(email)
            id_to_email_set[root_user_id] = email_set
        return id_to_email_set
        
    def initialize(self, n) :
        self.father = {}
        for i in range(n):
            self.father[i] = i
            
    
    def connect(self, a, b) :
        self.father[self.find(a)] = self.find(b)
        
    def find(self, a) :
        path = []
        while a!=self.father[a] :
            path.append(a)
            a = self.father[a]
            
        for u in path:
            self.father[u] = a
        return a
        
        
    def accountsMerge(self, accounts):
        # write your code here
        self.initialize(len(accounts))
        email_to_index = {}
        n = len(accounts)
        for i, account in enumerate(accounts):
            for a in account[1:]:
                if a in email_to_index:
                    self.connect(i, email_to_index[a])
                else:
                    email_to_index[a] = i
        
                 
        merged_accounts = {}
      
        for i in range(n):
            k = self.find(i)
            email_set = merged_accounts.get(k,set())
            for email in accounts[i][1:]:
                email_set.add(email)
            merged_accounts[k] = email_set
        
  
        res = []   
        for user_id, email_set in merged_accounts.items():
            res.append([accounts[user_id][0], *sorted(email_set)])
            
        return res
        


