#!/usr/bin/env python3

#依然是苦逼却最有效果的穷举法
import sys

def unique(li):#元素唯一化
    res=[]
    for j in li:
        if j not in res:
            res.append(j)
    return res

def main():
    try:
        N = int(sys.argv[1])
        s=[]
        h=(N+N%2)//2
        for a in range(1,h):#b!=0
            for b in range((h-a if h>2*a else a),h):#c!=0
                c = N-a-b
                if (2*b>=N-a) and (2*a<=N-b):
                    #s.append([a,b,c])
                    #print("{},{},{}".format(a,b,c))
                    pass
        
        #for i in s:#排序
        #    i.sort()
        #s.sort()
        #res=unique(s)
        #print ("用{0}根长度相同的火柴，首尾顺次连接摆成一个三角形，\n能摆成的不同的三角形的个数为：\n{1}，\n可能的组合有：".format(N,len(res)))
        #n=0
        #for j in res:
        #    n+=1
        #    print("{}\ta={}\tb={}\tc={}".format(n,j[0],j[1],j[2]))
        
    except IndexError:
        print("usage:{0} [NUM]".format(sys.argv[0]))
    except ValueError:
        print("NOT a number!")
    except KeyboardInterrupt:
        print("Bye-Bye!")

if __name__=='__main__':
    main()
