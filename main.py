def appendAndDelete(s, t, k):
    # Write your code here
    index=0
    if len(s)>len(t):
        for i in range(0,len(t)):
            if(s[i]==t[i]):
                index+=1
        if (2*(len(t)-index)+len(s)-len(t))<=k:
            return 'Yes'
        else:
            return 'No'
    else:
        for i in range(0,len(s)):
            if(s[i]==t[i]):
                index+=1
                
        print(index)
        if (len(t)-index+len(t)-index)<=k:
            return 'Yes'
        else:
            return 'No'

print(appendAndDelete(input(),input(),int(input())))