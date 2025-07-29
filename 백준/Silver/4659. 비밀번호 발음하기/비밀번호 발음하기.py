vowel=['a','e','i','o','u']
while True:
    word = input().strip()
    if word=='end':
        break

    has_Vowel=False
    valid=True
    v_cnt=0
    c_cnt=0

    for i in range(len(word)):
        ch = word[i]
        # 모음 포함 확인 & 모음 자음 카운팅
        if ch in vowel:
            has_Vowel=True
            v_cnt+=1
            c_cnt=0
        else:
            v_cnt=0
            c_cnt+=1

        # 모음 또는 자음 연속된 3글자 X
        if v_cnt==3 or c_cnt==3:
            valid=False
            break

        # 같은 글자 연속 2개 X, ee와 oo 허용
        if i>=1 and word[i]==word[i-1]:
            if word[i] in ['e','o']:
                continue
            else:
                valid=False

    if has_Vowel and valid:
        print(f"<{word}> is acceptable.")
    else:
        print(f"<{word}> is not acceptable.")