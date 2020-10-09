import random

num = 10
f = open('testData.txt', 'w')
f.close()
while num != 0:
    a = []
    oneOperator = ['sin', 'cos', 'tan', 'ln', 'log']
    operator = ['+', '-', '*', '/', '^']
    b = random.randint(0, 1)
    c = random.randint(6, 20)
    d = 0
    if b == 0:
        a.append('(')
        d += 1
    else:
        a.append(random.random() * 100)
    while c > 0:
        b = random.randint(0, 1)
        if b == 1 and a[len(a) - 1] in operator and a[len(a) - 1] != '^':
            a.append(str(random.randint(0, 30)) + '!')
        if b == 0 and a[len(a) - 1] not in operator and d != 0 and a[len(a) - 1] != '(':
            a.append(')')
            d -= 1
            continue
        if type(a[len(a) - 1]) == str and (a[len(a) - 1] in operator or a[len(a) - 1] == '('):
            b = random.randint(0, 2)
            if b == 0:
                a.append(oneOperator[random.randint(0, len(oneOperator) - 1)] + '(' + str(random.random() * 1000) + ')')
                c -= 1
                continue
            elif b == 1:
                a.append(random.random() * 100)
                c -= 1
                continue
            elif b == 2:
                a.append('(')
                c -= 1
                d += 1
                continue
        else:
            a.append(operator[random.randint(0, len(operator) - 1)])
            c -= 1
            continue
    if type(a[len(a) - 1]) == str and a[len(a) - 1] in operator:
        a.append(random.random())
    if d != 0:
        a.append('+1)' * d)

    f = open('testData.txt', 'a+')

    for x in a:
        print(x, end=' ', file=f)
    print('\n', file=f)

    f.close()
    num -= 1
