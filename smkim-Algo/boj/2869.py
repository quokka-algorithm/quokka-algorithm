import math 
A,B,V = map(int,input().split())

# 올림함수 사용 시 코드
x=math.ceil((V-A)/(A-B))
if A>=V:
  print(1)
else:
  print(x+1)
 
/*
# 올림함수 사용 안하고 계산하려 했으나 안됨. 왜인지 찾고 싶음
x=(V-A)/(A-B)
if x>0 and x<1:
  print(int(x+2))
else:
  print(int(x+1))
*/
