# 기본 수학 01
def main():
# 띄어쓰기로 정수 3개 받기
  A, B, C = map(int,input().split())
# 손익분기점은 이익이 넘으면 되므로
# 순이익을 계산
  plusPrice = C - B
# 순이익이 애초에 나지 않으면 손익 분기점은 없다
  if plusPrice > 0:
    # 남은 금액 / 순이익이 손익 분기점이므로 1을 추가
    return int(A/(C-B)+1)
  else: return "-1"

if __name__ == "__main__":
  print(main())
  