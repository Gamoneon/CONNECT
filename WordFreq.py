import re
str1 = input('Enter your paragraph:\n')
char = ['[,]','[.]','["]',"[']",'[""]',"['']",'[!]']

for c in char:
    str1 = re.sub(c,' ',str1).lower()

dict={}
str=str1.split()

for i in range(0,len(str)):
    x=str[i]
    if x in dict.keys():
        cnt = dict[x]
        cnt+=1
        dict[x] = cnt
    else:
        dict[x]=1

print(dict)
