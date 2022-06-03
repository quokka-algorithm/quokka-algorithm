# 기본 수학 01
# 찾고자 하는 수
a = int(input())
# 처음 시작 1과 같으면 1개
if a==1: 
  print(1)
else:
# 중앙에서 감싸고 있는 껍질 층 수(원자껍질)와 동일하므로
# 1층은 1개 2층은 1+6개 3층은 1+6+12개...
# 찾고자 하는 a는 몇 번째 껍질 안에 포함되어 있는지 계산
  result = 1
  for i in range(1,a):
# 벌집은 6의 배수만큼씩 늘어난다.
    result += 6*i
# 벌집의 껍질 범위에 포함될 경우 해당 껍질 층을 return
    if a <= result: 
      print (i+1)
      break