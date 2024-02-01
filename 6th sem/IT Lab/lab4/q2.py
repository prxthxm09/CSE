class q2:
    def __init__(self,arr):
        self.arr = arr
    def searchPair(self,sum):
        n = len(self.arr)
        for i in range(n):
            res = []
            res.append(i)
            for j in range(i+1,n):
                res.append(j)
                if self.arr[i] + self.arr[j] == sum:
                    return res
                res.remove(j)
        return []
    
if __name__ == '__main__':
    qq2 = q2([1,2,5,7,8,9,3])
    lst = qq2.searchPair(6)
    print(lst)