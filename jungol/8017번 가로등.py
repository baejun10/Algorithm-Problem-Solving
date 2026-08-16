import sys

input = sys.stdin.readline

l, n, k = map(int, input().split())

lights = list(map(int, input().split()))

# 위치 범위가 10^18 이라서 전부 계산이 불가능함

# 밝기를 구하려면 가장 가까운 가로등과의 거리를 알아야함.
# 가로등은 30만개의 좌표로 주어짐
# 출력은 밝은 순서대로 밝기 값을 출력해야함. <- 이게 포인트인듯? 가로등 기준으로만 밝기 계산

# 밝기별로 개수를 높은거부터 카운팅하기? 출력 개수가 500,000 이라서 가능할듯
cnt = 0
brightness = 0
used_set = set() # 이전 밝기에서 사용된 좌표 제외 용
bright_set = set() # 같은 좌표는 set으로 제거

while cnt < k: # 거리 0부터 최대 500000까지 밝기 계산
    bright_set.clear()
    for light_pos in lights:
        if (light_pos + brightness) not in used_set:
            bright_set.add(light_pos + brightness)
            used_set.add(light_pos + brightness)
        if (light_pos - brightness) not in used_set:
            bright_set.add(light_pos - brightness)
            used_set.add(light_pos - brightness)

    # 해당 밝기 개수만큼 출력
    for i in range(len(bright_set)):
        if cnt >= k: # 출력 범위가 끝나면 종료
                        break
        print(f"{brightness}")
        cnt += 1
            
        
    brightness += 1