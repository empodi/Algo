s, i, cnt = input(), 0, 0
myhash = set(["c=","c-","dz=","d-","lj","nj","s=","z="])
while i < len(s):
    if s[i:i+3] in myhash:
        i += 3
    elif s[i:i+2] in myhash:
        i += 2
    else:
        i += 1
    cnt += 1
print(cnt)