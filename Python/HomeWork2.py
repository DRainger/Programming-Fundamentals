"""
Home Work 2
Yaron Gurevich, 311429971
"""

import random

def my_filter(f):
    """
    Question 2.1.
    Function returns a function that receives a list
    and filters its items with given function (f).
    Parameters: f (function).
    Return lst_filter (function).
    """
    def lst_filter(l):
        res = []
        for i in range(len(l)):
            if f(l[i]):
                res.append(l[i])
        return res
    return lst_filter






filtered_words = lambda l,n:my_filter(lambda x:len(x)>n)(l)
"""
Question 2.2.
lambda function to filter words in list
that are longer then 'n'.
Parameters: list, integer.
Return list.
"""





def my_map(f):
    """
    Question 2.3.
    Function returns a function that receives a list
    and maps its items by given function (f).
    Parameters: f (function).
    Return lst_map (function).
    """
    def lst_map(lst):
        res = []
        for i in range(len(lst)):
            res.append(f(lst[i]))
        return res

    return lst_map





my_filter_and_map = lambda lst,ff,fm:my_map(fm)(my_filter(ff)(lst))
"""
Question 2.4.
lambda function to filter and map items in list.
Parameters: list, functions (ff,fm).
Return list.
"""






def polynomial(factors):
    """
    Question 3.
    function calculate polynomial functions
    with given x.
    Parameters: list.
    Return function(eval).
    """
    def eval(x):
        result = 0
        for i in range(len(factors)):
            result += factors[i]*(x**(len(factors)-(i+1)))
        return result
    return eval





'''
the pin cracker game!
'''

def code_cracker():
    '''
    Question 4.
    function contains all components for the game
    Parameters: none.
    :return: none.
    '''
    points = 100
    clue = 0  # counter to track how many clues the player got
    code = random.randint(10000, 99999)  # generates a random 5 digit integer

    def last_dig(x):
        return x % 10

    def reduce_num(x):
        return x // 10

    def yes_or_no(f, n):
        '''
        function is used for clues 1 and 2.
        :param f: lambda function
        :param n: integer
        :return: string
        '''
        if f(n):
            return 'Yes'
        else:
            return 'No'

    def print_msg_to_func(msg, f):
        '''
        function is used for clues 3 and 4,
        prints formatted output according to param f.
        :param msg: string
        :param f: lambda function
        :return: none
        '''
        temp = code

        def do(n):
            if n < 10:
                return n
            return f(do(reduce_num(n)), last_dig(n))

        res = do(temp)
        print('{0} : {1}'.format(msg, res))

    def show_string_by_func(msg, f):
        '''
        function used for clues 5 and 6,
        prints formatted output acording to param f
        :param msg: string
        :param f: lambda function
        :return: none
        '''
        x = []
        tmp = code

        for _ in range(5):
            if f(last_dig(tmp)):
                x.insert(0, 'X')
                tmp = reduce_num(tmp)
            else:
                x.insert(0, '-')
                tmp = reduce_num(tmp)

        print('{0} : {1}{2}{3}{4}{5}'.format(msg, x[0], x[1], x[2], x[3], x[4]))

    def clue_generator():
        return random.randint(1,6)

    def driver():
        '''
        game driver function runs the code cracker game.
        :return: none
        '''
        print("Welcome to cracker game!")
        while 1:
            c = clue_generator()  # generates a random integer 1 to 6, randomly give clue to player on every iteration
            nonlocal clue
            nonlocal points
            clue = clue + 1       # increase value of clue by one on every iteration
            points = points - 10  # decrease value of points by 10 on every iteration

            if c == 1:
                print("Clue# ", clue)
                number = int(input("Enter number to check if the code is bigger: "))
                print(yes_or_no(lambda x: x >= code, number))
                print("points left: ", points)

            elif c == 2:
                print("Clue# ", clue)
                number = int(input("Enter number to check if the code is smaller: "))
                print(yes_or_no(lambda x: x <= code, number))
                print("points left: ", points)

            elif c == 3:
                print("Clue# ", clue)
                print_msg_to_func("sum", lambda x, y: x + y)
                print("points left: ", points)

            elif c == 4:
                print("Clue# ", clue)
                print_msg_to_func("sum", lambda x, y: x - y)
                print("points left: ", points)

            elif c == 5:
                print("Clue# ", clue)
                show_string_by_func("odd digits :", lambda n: n % 2 != 0)
                print("points left: ", points)

            elif c == 6:
                print("Clue# ", clue)
                show_string_by_func("digits divided by 3 :", lambda n: n % 3 == 0)
                print("points left: ", points)

            guess = input("guess or press ENTER for exit: ")

            if guess == code:                 # if player guesses correctly break while loop
                print("Yes!, correct!")
                print("points left: ", points)
                break

            elif points == 0 or guess == '':    # if player got to 0 pints break while loop
                print("Wrong!, Bye Bye!")
                print("points left: ", points)
                break

    driver()


code_cracker()





