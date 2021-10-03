def nextGreaterElement(n):
    sn = str(n)
    i = len(sn)-1
    q = []
    for s in reversed(sn[1:]):
        if int(s) > int(sn[i-1]):
            heapq.heappush(q,s)
            heapq.heappush(q,sn[i-1])
            first = sn[:i-1]
            last = ''
            flip = True
            while q:
                e = heapq.heappop(q)
                if flip and int(e) > int(sn[i-1]):
                    mid = e
                    flip = False
                else:
                    last+=e
            ans = int(first+mid+last)
            return ans if ans < 2**31 else -1
        heapq.heappush(q,s)
        i-=1
    
    return -1
