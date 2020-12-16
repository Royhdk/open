import random
a = random.randint(1,1000)
n = 1
while True:
    print('请输入猜测的数字：')
    b = int(input())
    if b>a:
        print('猜大了')
    elif b<a:
        print('猜小了')
    else:
        print('猜对了,猜测了',n,'次')
        break
    n+=1
