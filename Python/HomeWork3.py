"""
Home Work 3
Yaron Gurevich, 311429971
"""
from functools import reduce
from operator import add
from math import sqrt

"""
חלק א'                 
                 שאלה 1
"""
#---------------level 1--------------------#
def make_rectangle(x,y,length,width):
    '''
    function simulate a rectangle with lower left corner (x,y)
     and the width and length of it.
    :param x:
    :param y:
    :param length:
    :param width:
    :return: dispatch function
    '''

    def dispatch(massage):
        if massage == 'x':
            return x
        elif massage == 'y':
            return y
        elif massage == 'length':
            return length
        elif massage == 'width':
            return width

    return dispatch

#---------------level 2--------------------#
def x(rectangle):
    '''
    high order function to get the value of x
    :param rectangle:
    :return: passing of a massage ('x') to dispatch
    '''
    return rectangle('x')

def y(rectangle):
    '''
    high order function to get the value of y
    :param rectangle:
    :return: passing of a massage ('y') to dispatch
    '''
    return rectangle('y')

def length(rectangle):
    '''
    high order function to get the value of length
    :param rectangle:
    :return: passing of a massage ('length') to dispatch
    '''
    return rectangle('length')

def width(rectangle):
    '''
    high order function to get the value of width
    :param rectangle:
    :return: passing of a massage ('width') to dispatch
    '''
    return rectangle('width')

def diagonal(rectangle):
    '''
    calculate diagonal of rectangle
    :param rectangle:
    :return: float
    '''
    return sqrt(rectangle('length')**2 + rectangle('width')**2)

def print_rectangle(rectangle):
    '''
    outputs rectangle ot screen in format
    :param rectangle:
    :return: none
    '''
    print('rectangle: point=({0},{1}); size = {2}x{3}'.format(rectangle('x'), rectangle('y'), rectangle('length'), rectangle('width')))

def center(rectangle):
    '''
    calculate center point of rectangle
    :param rectangle:
    :return: tuple of x and y of center point
    '''
    return (rectangle('length')/2 +rectangle('x'), rectangle('width')/2 + rectangle('y'))#'({0}, {1})'.format(rectangle('length')/2 +rectangle('x'), rectangle('width')/2 + rectangle('y'))

def distance(r1, r2):
    '''
    calculate distance between two
    center points of two rectangles
    :param r1: rectangle
    :param r2: rectangle
    :return: float
    '''
    cr1= center(r1)
    cr2= center(r2)
    return sqrt(((cr2[0])-(cr1[0]))**2 + ((cr2[1])-(cr1[1]))**2)

def move(r, dx, dy):
    '''
    creat new rectangle with modified location
    :param r: rectangle
    :param dx: (int) where to move x
    :param dy: (int) where to move y
    :return: new rectangle
    '''
    return make_rectangle(r('x')+dx,r('y')+dy,r('length'),r('width'))

def resize(r, res_fact):
    '''
    creat new rectangle with modified size
    :param r: rectangle
    :param res_fact: number
    :return: new rectangle
    '''
    return make_rectangle(r('x'),r('y'),r('length')*res_fact,r('width')*res_fact)

def my_avg(x, y): #my helper function
    return (x+y)/2

def average_rectangle(r1, r2):
    '''
    creat new rectangle exactly between two rectangles
    :param r1: rectangle
    :param r2: rectangle
    :return: new rectangle
    '''
    return make_rectangle(my_avg(r1('x'), r2('x')), my_avg(r1('y'),r2('y')), my_avg(r1('length'),r2('length')), my_avg(r1('width'),r2('width')))



"""שאלה 2"""
#---------------level 1--------------------#
def make_vector(size,list):
    '''
    function simulate behavior of vector
    :param size: number
    :param list: list
    :return: dispatch function
    '''
    def dispatch(massage):
        if massage == 0:
            return size
        elif massage == 1:
            return list
    return dispatch

#---------------level 2--------------------#
def size(vector):
    '''
    gat size of vector (number)
    :param vector:
    :return: passing of a massage (0) to dispatch , returns value of size
    '''
    return vector(0)

def values(vector):
    '''
    gat vector (list of numbers)
    :param vector:
    :return: passing of a massage (1) to dispatch , returns a list
    '''
    return vector(1)

def print_vector(vector):
    '''
    output vector to screen in format
    :param vector:
    :return: none
    '''
    print('size = {0}; values ={1}'.format(vector(0), vector(1)))

def value_at(vector, i):
    '''
    gat value of item in list(vector)
    :param vector:
    :param i: index
    :return: passing of a massage (1) to dispatch, return item from list in i location
    '''
    if i >= vector(0):
        return None
    return vector(1)[i]

def reverse(vector):
    '''
    create new vector with reversed list of values
    :param vector:
    :return: new vector
    '''
    return make_vector(vector(0), vector(1)[::-1])

def norm1(vector):
    '''
    gat sum of absolute values in vector
    :param vector:
    :return: int
    '''
    my_abs = lambda k: k if k > 0 else k * -1
    return sum(my_abs(k) for k in vector(1))

def norm2(vector):
    '''
    square root of sum of squared values in vector
    :param vector:
    :return: float
    '''
    pow2 =lambda h:h**2
    return sqrt(sum(pow2(l) for l in vector(1)))

def insert(vector, n):
    '''
    add value to list in vector
    :param vector:
    :param n: values
    :return: new vector
    '''
    temp = list(vector(1))
    temp.extend([n])
    return make_vector(vector(0) + 1, tuple(temp))

def delete(vector, i):
    '''
    delete value from list of values in vector
    :param vector:
    :param i: index
    :return: new vector
    '''
    if i >= vector(0):
        return vector
    temp = list(vector(1))
    del temp[i]
    return make_vector(vector(0)-1,tuple(temp))

def sort_vector(vector):
    '''
    sort values of vector from smallest to largest
    :param vector:
    :return: new vector
    '''
    l = list(vector(1))
    for _ in range(len(l)):
        for x in range(len(l)-1):
            if l[x] > l[x+1]:
                l[x], l[x+1] = l[x+1], l[x]
    return make_vector(vector(0), tuple(l))

def add_vector(v1, v2):
    '''
    add values of two vectors
    :param v1: vector
    :param v2: vector
    :return: new vector
    '''
    min_vect = min(len(v1(1)), len(v2(1)))
    tmp =[]
    def max_vect(v1, v2):
        return v1 if len(v1(1)) > len(v2(1)) else v2
    for i in range(min_vect):
        tmp.append(v1(1)[i] + v2(1)[i])
    if min_vect < len(max_vect(v1, v2)(1)):
        for j in range(min_vect, len(max_vect(v1, v2)(1))):
            tmp.append(max_vect(v1, v2)(1)[j])
    return make_vector(len(tmp), tuple(tmp))

def mult_scalar(vector, s):
    '''
    multiply values of a vector with scalar
    :param vector:
    :param s: scalar
    :return: new vector
    '''
    tmp = list(vector(1))
    for i in range(len(tmp)):
        tmp[i] = tmp[i] * s
    return make_vector(vector(0), tuple(tmp))


"""
חלק ב'                 
                 שאלה 3
"""


def avg_grades(list_cours):
    '''
    display average of grades in courses in a tuple
    :param list_cours:
    :return: tuple
    '''
    return tuple(map(lambda x : (x[0], reduce(add, x[1])/len(x[1])), list_cours))

def add_factors(avg,fact):
    '''
    add factors to grades average
    :param avg: tuple
    :param fact: tuple
    :return: tuple
    '''
    def add_f(l):
        for j in fact:
            if l[0] == j[0]:
                return (l[0],l[1] + j[1])
        return (l[0],l[1])
    return tuple(map(add_f, avg))

def total_average(courses, credits):
    '''
    calculate the total average of all courses
    :param courses: tuple
    :param credits: tuple
    :return: int
    '''
    def total(l):
        for j in credits:
            if l[0] == j[0]:
                return (l[0],l[1] * j[1])
        return (l[0],l[1])
    def creds(c):
        res = 0
        for x in c:
            res += x[1]
        return res

    return reduce(add, map(lambda a: a[1], map(total, courses))) / creds(credits)



"""
חלק ג'                 
                 שאלה 4
"""


def make_warehouse(courses_dict, credits_dict, types):
    '''
    crate data base of courses and there credits worth
    :param courses_dict: dictionary
    :param credits_dict: dictionary
    :param types: dictionary
    :return: dictionary
    '''
    def min_credits():
        '''
        gat grade of curse with lowest credit score
        :return: int
        '''
        min_k = min(credits_dict, key=credits_dict.get)
        return courses_dict[min_k]

    def max_credits():
        '''
        gat grade of curse with highest credit score
        :return: int
        '''
        max_k = max(credits_dict, key=credits_dict.get)
        return courses_dict[max_k]

    def min_course(t):
        '''
        gat minimum grade of curse from type
        :param t: dictionary
        :return: int
        '''
        min_c = courses_dict[types[t][0]]
        for i in types[t]:
            if courses_dict[i] < min_c:
                min_c = courses_dict[i]
        return min_c


    def max_course(t):
        '''
        gat maximum grade of curse from type
        :param t: dictionary
        :return: int
        '''
        max_c = courses_dict[types[t][0]]
        for i in types[t]:
            if courses_dict[i] > max_c:
                max_c = courses_dict[i]
        return max_c

    def avg_course(t):
        '''
        gat average of grades of curses from type
        :param t: dictionary
        :return: float
        '''
        avg_c = 0
        for i in types[t]:
            avg_c += courses_dict[i]
        return avg_c/len(types[t])

    def add_course(k, n, t):
        '''
        add a course to dictionary and to type
        :param k: key(char)
        :param n: value(int)
        :param t: dictionary
        :return: none
        '''
        courses_dict[k] = n
        tmp = list(types[t])
        tmp.append(k)
        types[t] = tuple(tmp)

    return {'min_credits':min_credits, 'max_credits':max_credits, 'min_course':min_course, 'max_course':max_course,'avg_course':avg_course, 'add_course':add_course}



"""
חלק ג'                 
                 שאלה 5
"""


def make_sequence(sequence):
    '''
    crate a sequence type
    :param sequence: tuple
    :return: dictionary
    '''
    def filter(func = True):
        '''
        filter out values from sequence
        according to function given
        :param func: function
        :return: tuple
        '''
        if type(func) == type(True) and func == True:
            return tuple(sequence)
        res = []
        for i in sequence:
            if func(i):
                res.append(i)
        return tuple(res)

    ''' לא הצלחתי לממש את הפונקציול הבאות בזמן לכן הן בהערה.
    def filter_iterator(func):
        iterator = 0
        def abs(x):
            return sqrt(x**2)
        if not func(abs(iterator)):
            iterator = 0
            return iterator
        return iterator

        
        def next():
        def reverse():
       
    def extend(s):
    '''
    return {'filter':filter} #, 'filter_iterator':filter_iterator, 'next':next, 'reverse':reverse}


