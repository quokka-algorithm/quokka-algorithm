import math
num=int(input())
for i in range(num):
  H,W,N = map(int,input().split())

  # x: 호 번호, y: 층 수
  x = math.ceil(N/H)
  y = N%H

  # 찾고자 하는 N이 나누어 떨어질 경우, 최고 층수(높이)와 같다
  if y==0:
    y=H

  print('%d%02d' %(y,x))
