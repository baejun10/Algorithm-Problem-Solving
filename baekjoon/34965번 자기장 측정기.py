import sys

input = sys.stdin.readline

x0, y0 = map(int, input().split())
cmd = input().strip()

dir = 0
x = y = 0


def dist2(px, py):
    return (px - x0) ** 2 + (py - y0) ** 2


def clamp(v, a, b):
    lo = min(a, b)
    hi = max(a, b)
    if v < lo:
        return lo
    if v > hi:
        return hi
    return v


def parse(s):
    i = 0
    res = []
    while i < len(s):
        j = i + 1
        while j < len(s) and s[j].isdigit():
            j += 1
        res.append((s[i], int(s[i + 1 : j])))
        i = j
    return res


# 시작점 도선 통과 검사
if x0 == 0 and y0 == 0:
    print(-1)
    sys.exit(0)

best = dist2(0, 0)
ans = (0, 0)

for inst, amt in parse(cmd):
    if inst == "T":
        dir = (dir + amt) % 4
        continue

    sx, sy = x, y

    if dir == 0:
        x += amt
    elif dir == 1:
        y += amt
    elif dir == 2:
        x -= amt
    else:
        y -= amt

    ex, ey = x, y

    # 선분 도선 통과 검사
    if sx == ex:
        if sx == x0 and min(sy, ey) <= y0 <= max(sy, ey):
            print(-1)
            sys.exit(0)
        cx = sx
        cy = clamp(y0, sy, ey)
    else:
        if sy == y0 and min(sx, ex) <= x0 <= max(sx, ex):
            print(-1)
            sys.exit(0)
        cy = sy
        cx = clamp(x0, sx, ex)

    for px, py in [(sx, sy), (cx, cy), (ex, ey)]:
        d = dist2(px, py)
        if d < best:
            best = d
            ans = (px, py)

# 마지막 위치 보장
d = dist2(x, y)
if d < best:
    ans = (x, y)

print(ans[0], ans[1])
