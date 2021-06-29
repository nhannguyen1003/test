# passing and Arbitrary NUm
import header
def doSth(*arr):
    for i in arr:
        print(i)
    return arr
doSth(3,5,7,9)
print(doSth(3,5,9))
#passing an Arbitrary Number first step is initial tuple and after then
#We push list argument to commit tupple
def dicArbitrary(dau,duoi,**dic):
    dic['dau']=dau
    dic['duoi']=duoi
    return dic
print(dicArbitrary('cr7','cc',nhan='dep trai',nhu='xau vc'))
dictionary={'nhan':1,'nhu':5}
dictionary['cr7']=0
print(dictionary)
muldic={
    'nhan':{
        'HP':5,'Dame':10,
        'skill':'chuong'
    },
    'nhu':{
        'HP':1, 'Dame':20,
        'skill':'dam'
    }
}
for key in muldic.keys():
    for key0 in muldic[key].keys():
        print(f"{key}:{key0}:{muldic[key][key0]}")
from header import doSth as ds
print(ds(15))