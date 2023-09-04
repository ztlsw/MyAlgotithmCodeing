from typing import List, Tuple
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n<2 :
             return 0
        st : List[tuple]= []
        limst = 0
        while limst<n-1 and height[limst+1]>= height[limst] :
            limst+=1
        st.append((height[limst],1))
        ans = 0
        for i in range(limst,n):
            now : tuple = st[len(st)-1]
            if height[i]<now[0]:
                st.append((height[i],1))
            else:
                if height[i] == now[0]:
                    st.pop()
                    st.append((height[i],now[1]+1))
                    now = st[len(st)-1]
                else :
                    st.pop()
                    if len(st) == 0:
                        st.append((height[i],1))
                    else :
                        now2 : tuple = st[len(st)-1]
                        while len(st)>0:
                            if now2[0]<height[i]:
                                ans+=(now2[0]-now[0])*now[1]
                                now = (now2[0],now[1]+now2[1])
                                st.pop()
                                if len(st) == 0:
                                    st.append((height[i],1))
                                    break
                                now2 = st[len(st)-1]
                                continue

                            if now2[0]>height[i]:
                                ans+=(height[i]-now[0])*now[1]
                                st.append((height[i],now[1]+1))
                                break

                            if now2[0] == height[i]:
                                ans+=(height[i]-now[0])*now[1]
                                st.pop()
                                st.append((height[i],now[1]+now2[1]+1))
                                break
        return ans
                            

              
if __name__ =="__main__":
    s = Solution()
    print(s.trap([0,1,0,2,1,0,1,3,2,1,2,1]))
    print(s.trap([4,2,0,3,2,5]))
    print(s.trap([5,4,1,2]))
    print(s.trap([5,2,1,2,1,5]))
    print(s.trap([5,2,1,2,1,5,2,1,2,1,5]))
    print(s.trap([5,2,1,2,1,5,2,1,2,1,5,2,1,2,1,5]))