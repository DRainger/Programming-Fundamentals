"""
Home Work 1
Yaron Gurevich, 311429971
"""



def Xnor(param1, param2):
    """
    Question 1.
    Function calculate result of Xnor logic gate.
    Parameters: param1, param2.
    Return xnor result.
    """
    if param1 == param2:
        return True
    else:
        return False



help(Xnor)
print(Xnor(True, False))
print(Xnor(9>5, 3<4))
print(Xnor(9<5, 3==4))
print(Xnor(9<5, 3<4))
print(end='\n')



def Digits(number):
    """
    Question 2.
    Function prints message about given number according to terms,
    using help function to determine if digit is odd or even.
    Parameters: number.
    Return none.
    """
    def is_odd_or_even(n):
        if n % 2 == 0:
            return "even"
        return "odd"

    if number < 10:
        print('one digit - {0} ({1})'.format(is_odd_or_even(number),number))
    elif number < 100:
        print('two digits - {0} ({1}+{2}={3})'.format(is_odd_or_even(number // 10 + number % 10), number // 10, number %
                                                      10, number // 10 + number % 10))
    elif number < 1000:
        print('three digits - {0} ({1}+{2}={3})'.format(is_odd_or_even(number // 100 + number % 10), number // 100, number %
                                                      10, number // 100 + number % 10))
    elif number < 10000:
        print('three digits - {0} ({1}+{2}={3})'.format(is_odd_or_even(number // 100 % 10 + number//10 % 10), number // 100 % 10, number//10 % 10,
                                                        number // 100 % 10 + number//10 % 10))
    elif number < 100000:
        print('three digits - {0} ({1})'.format(is_odd_or_even(number // 100 % 10), number // 100 % 10))
    elif number < 1000000:
        print('ERROR!')



help(Digits)
Digits(6)
Digits(63)
Digits(163)
Digits(1653)
Digits(16453)
Digits(123456)
print(end='\n')



def GoodOrder(number):
    """
    Question 3.
    Function checks if all digits are even or odd,
    using function Xnon from question 1 and help function
    to determine if digit is odd or even.
    Parameters: number.
    Return boolean.
    """
    def odd_even(x):
        if x % 2 == 0:
            return 'even'
        return 'odd'
    while number//10 != 0:
        if Xnor(odd_even(number%10),odd_even(number//10%10)) == False:
            return False
        number = number // 10
    return True



help(GoodOrder)
print(GoodOrder(12345))
print(GoodOrder(264))
print(GoodOrder(1573))
print(end='\n')



def Figure(n):
    """
    Question 4.
    Function prints triangle at the size of the given number.
    Parameters: n (single digit integer).
    Return none.
    """
    print(" "*(n-2), 1, end="\n")
    l = 1
    for i in range(2,n):
        for j in range(i,n):
            print(" ",end="")
        print(i,end="")
        for k in range(0,l):
            print(" ",end="")
        print(i,end="")
        print(end="\n")
        l = l + 2
    for i in range(n,1,-1):
        print(i,end="")
    for i in range(1,n+1):
        print(i,end="")



help(Figure)
Figure(7)
print(end="\n")



def Weight(number):
    """
    Question 5.
    Function determines the weight of given number.
    Parameters: number.
    Return result(integer).
    """
    def calc_digits(num):
        if num < 10:
            return 1
        return 1 + calc_digits(num//10)

    def Max(x, y):
        return x if x > y else y

    def max_dig(num):
        if num == 0:
            return 0
        return Max(num%10, max_dig(num//10))
    '''
    return "Weight of {0} is {1} ({2} + {3})".format(number, max_dig(number) + calc_digits(number),max_dig(number),calc_digits(number))
    would look better but not what was demanded...
    '''
    return max_dig(number)+calc_digits(number)



help(Weight)
print(Weight(7145))
print(Weight(15))
print(Weight(351))
print(end="\n")



def IsPrimary(number):
    """
    Question 6.
    Function validates if number is prim or not.
    Parameters: number.
    Return boolean.
    """

    def mySqrt2(x):
        '''
        function contains help functions
        needed to calculate square root
        of given number'''

        def avg(x, y):
            return (x + y) / 2

        def good_enough(g):
            if abs(x - g * g) < 0.0001:
                return True
            return False

        def improve(g):
            return avg(x / g, g)

        def gat_sqt(guess):
            while good_enough(guess) == False:
                guess = improve(guess)
            return guess

        return gat_sqt(1)
    def prime_check(n, sqtn):
        if sqtn == 1:
            return True
        elif n % sqtn == 0:
            return False
        return True and prime_check(n, sqtn -1)
    return prime_check(number,int(mySqrt2(number)))



help(IsPrimary)
print(IsPrimary(23))
print(IsPrimary(21))
print(end='\n')



def Reduce(number):
    """
    Question 7.
    Function removes zeros from given number.
    Parameters: number.
    Return integer.
    """

    if number == 0:
        return 0
    elif number < 0:
        return -1*Reduce(number*-1)
    elif number % 10 == 0:
        return Reduce(number//10)
    return number % 10 + Reduce(number // 10) * 10



help(Reduce)
print(Reduce(-160760))
print(Reduce(1020034000))
print(end='\n')


def Pascal(col,row):
    """
    Question 8.
    Function calculates number in row n and column m.
    Parameters: n, m.
    Return integer.
    """
    if row < col:
        return -1
    if(col == 0) or (col == row):
        return 1
    else:
        return Pascal(col-1,row-1) + Pascal(col,row-1)



help(Pascal)
print(Pascal(2,3))
print(Pascal(4,10))
print(Pascal(3,5))