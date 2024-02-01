class q3:
    def pow(self,x,n):
        if n == 0: 
            return 1
        res = 1
        while n > 0:
            res *= x
            n = n -1
        return res
    
if __name__ == '__main__':
    qq3 = q3()
    res = qq3.pow(6,3)
    print(res)