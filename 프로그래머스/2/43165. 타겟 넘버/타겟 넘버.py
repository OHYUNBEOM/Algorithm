global_answer=0
global_numbers=[]
global_target=0

def dfs(idx,total):
    global global_answer,global_numbers,global_target
    
    if idx==len(global_numbers):
        if total==global_target:
            global_answer+=1
        return
    
    dfs(idx+1,total+global_numbers[idx])
    dfs(idx+1,total-global_numbers[idx])

def solution(numbers, target):
    global global_answer,global_numbers,global_target
    
    global_answer=0
    global_numbers=numbers
    global_target=target
    
    dfs(0,0)
    
    return global_answer