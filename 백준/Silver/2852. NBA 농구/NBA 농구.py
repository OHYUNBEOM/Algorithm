n=int(input())
t1=t2=t1_lead=t2_lead=0
prev_time=0
total_time=48*60

for _ in range(n):
    line=input().split()
    team=int(line[0])
    mm,ss=map(int,line[1].split(":"))
    cur_time=mm*60+ss

    if t1>t2:
        t1_lead+=cur_time-prev_time
    elif t2>t1:
        t2_lead+=cur_time-prev_time

    if team==1:
        t1+=1
    else:
        t2+=1

    prev_time=cur_time

if t1>t2:
    t1_lead+=total_time-prev_time
elif t2>t1:
    t2_lead+=total_time-prev_time

print(f"{t1_lead // 60:02}:{t1_lead % 60:02}")
print(f"{t2_lead // 60:02}:{t2_lead % 60:02}")