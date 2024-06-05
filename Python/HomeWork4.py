"""
Home Work 4
Yaron Gurevich, 311429971
"""
import datetime
from functools import reduce
from math import gcd
from math import atan2, sin, cos, pi, pow
from operator import mul, add
from itertools import cycle


##  שאלה 1


# class Date:
#     '''
#     date class, set to initiate current date if no parameters are given
#     in form "day/month/year"
#     '''
#     def __init__(self, day=datetime.datetime.now().day, month=datetime.datetime.now().month,
#                  year=datetime.datetime.now().year):
#         '''
#         constructor
#         :param day: default for current day
#         :param month: default for current month
#         :param year: default for current year
#         '''
#         self.day = day
#         self.month = month
#         self.year = year
#
#
#     def __str__(self):
#         '''
#         :return: string in format day/month/year
#         '''
#         return '{:02d}/{:02d}/{:04d}'.format(self.day, self.month, self.year)
#
#
# class Temperature(Date):
#     '''
#     Temperature class inherits from Date class data type to store Temperature measurement
#     at given or default current date
#     '''
#     def __init__(self, temp, day=None, month=None, year=None):
#         '''
#         constructor, will set day, mont and year to default values if not given
#         :param temp: number, this parameter is required
#         :param day: parameter is not required
#         :param month: parameter is not required
#         :param year: parameter is not required
#         '''
#         if day == month == year == None:
#             super().__init__()
#         else:
#             super().__init__(day, month, year)
#         self.temp = float(temp)
#
#
#     def compareTemp(self, other):
#         '''
#         method compare temperature of two objects
#         :param other: temperature object
#         :return: temperature object with highest temp value
#         '''
#         if self.temp > other.temp:
#             return self
#         return other
#
#     def __str__(self):
#         '''
#         :return: string in format 'self.temp'°C:day/month/year
#         '''
#         if self.temp > 0:
#             return '+{0}°C:'.format(self.temp) + Date.__str__(self)
#         return '{0}°C:'.format(self.temp) + Date.__str__(self)
#
#
# class Location:
#     '''
#     Location class data type to assign temperature measurements to a location
#     '''
#     def __init__(self, loc):
#         self.loc = loc
#         self.measurements = None
#
#     def addTemp(self, *args):
#         '''
#         method to add temperature measurements
#         :param args: multiple temperature type
#         :return: list
#         '''
#         self.measurements = [item for item in args]
#
#
#     def printLocation(self):
#         '''
#         method prints location and its list of measurements in temperature format
#         :return: None
#         '''
#         print(self.loc)
#         if self.measurements is None:
#             print("no temperature measurements available")
#         else:
#             for item in self.measurements:
#                 print(item, end=' ')
#
#
#     def getAverage(self):
#         '''
#         method measures average temperature
#         :return: float
#         '''
#         return sum(map(lambda x:x.temp, self.measurements))/len(self.measurements)
#
#
#     def getMaxTemp(self):
#         '''
#         method gat maximum temperature at location
#         :return: Temperature type
#         '''
#         return reduce(Temperature.compareTemp, map(lambda x:x,self.measurements))
#
#
#     def compareLocation(self, other):
#         '''
#         method compare average temperature of two locations
#         :param other: Location type
#         :return: Location type
#         '''
#         if self.getAverage() > other.getAverage():
#             return self
#         return other


## שאלה 2


### Our custom OOP
def make_class(class_name, attrs, base=None):
    """Return a new class (a dispatch dictionary) with given class attributes"""

    # Getter: class attribute (looks in this class, then base)
    def get(name):
        if name in attrs:
            return attrs[name]
        elif base:
            return base['get'](name)

    # Setter: class attribute (always sets in this class)
    def set(name, value):
        attrs[name] = value

    # Return a new initialized object instance (a dispatch dictionary)
    def new(*args):
        # instance attributes (hides encapsulating function's attrs)
        attrs = {}

        # Getter: instance attribute (looks in object, then class (binds self if callable))
        def get(name):
            if name in attrs:
                return attrs[name]
            else:
                value = cls['get'](name)
                if callable(value):
                    return lambda *args: value(obj, *args)
                else:
                    return value

        # Setter: instance attribute (always sets in object)
        def set(name, value):
            attrs[name] = value

        # instance dictionary
        obj = {'get': get, 'set': set, 'name': name}

        # calls constructor if present
        init = get('__init__')
        if init: init(*args)

        return obj

    ## # שאלה 3 חלק ב'--------------#
    def class_path():
        if base is None:
            return cls['get']('name')
        else:
            return cls['get']('name') + '::' + base['get']('name')

    # -----------------------------

    # class dictionary
    cls = {'get': get, 'set': set, 'new': new, 'class_path': class_path}
    ## #שאלה 3 חלק א'--------------
    cls['set']('name', class_name)
    # -----------------------------
    return cls


#
#
# def make_date_class():
#     def __init__(self, day=datetime.datetime.now().day, month=datetime.datetime.now().month,
#                  year=datetime.datetime.now().year):
#         self['set']('day', day)
#         self['set']('month', month)
#         self['set']('year', year)
#
#
#     def str(self):
#         return '{:02d}/{:02d}/{:04d}'.format(self['get']('day'), self['get']('month'), self['get']('year'))
#
#     return make_class(locals())
#
#
#
# def make_temperature_class():
#     def __init__(self, temp, day=None, month=None, year=None):
#         self['set']('temp', float(temp))
#         if day == month == year == None:
#             self['set']('date', Date['new']())
#         else:
#             self['set']('date', Date['new'](day, month, year))
#
#
#     def compareTemp(self, other):
#         if self['get']('temp') > other['get']('temp'):
#             return self
#         return other
#
#     def str(self):
#         if self['get']('temp') > 0:
#             return '+{0}°C:'.format(self['get']('temp')) + Date['get']('str')(self['get']('date'))
#         return '{0}°C:'.format(self['get']('temp')) + Date['get']('str')(self['get']('date'))
#
#     return make_class(locals(), Date)
#
#
# def make_location_class():
#     def __init__(self, loc):
#         self['set']('loc', loc)
#         self['set']('measurements', None)
#
#     def addTemp(self, *args):
#         self['set']('measurements', [item for item in args])
#
#     def printLocation(self):
#         print(self['get']('loc'))
#         if self['get']('measurements') is None:
#             print("no temperature measurements available")
#         else:
#             for item in self['get']('measurements'):
#                 print(item['get']('str')(), end=' ')
#
#     def getAverage(self):
#         return sum(map(lambda x: x['get']('temp'), self['get']('measurements'))) / len(self['get']('measurements'))
#
#     def getMaxTemp(self):
#         return reduce(Temperature['get']('compareTemp'), map(lambda x: x, self['get']('measurements')))
#
#     def compareLocation(self, other):
#         if self['get']('getAverage')() > other['get']('getAverage')():
#             return self
#         return other
#
#
#     return make_class(locals())


def make_account_class():
    return make_class('Account', {'interest': 0.05})


def make_save_account_class():
    def init(self, owner):
        self['set']('owner', owner)
        self['set']('balance', 0)

    return make_class('SaveAccount', {'__init__': init, 'interest': 0.03}, Account)


Account = make_account_class()
SaveAccount = make_save_account_class()


# שאלה 4 #


####################
# Rational numbers #
####################

def add_rational(x, y):
    """Add rational numbers x and y."""
    nx, dx = x.numer, x.denom
    ny, dy = y.numer, y.denom
    return Rational(nx * dy + ny * dx, dx * dy)


def mul_rational(x, y):
    """Multiply rational numbers x and y."""
    return Rational(x.numer * y.numer, x.denom * y.denom)


class Rational(object):
    """A rational number represented as a numerator and denominator.
    All rational numbers are represented in lowest terms."""

    def __init__(self, numer, denom):
        g = gcd(numer, denom)
        self.numer = numer // g
        self.denom = denom // g

    def __repr__(self):
        return 'Rational({0}, {1})'.format(self.numer, self.denom)

    def __str__(self):
        return '{0}/{1}'.format(self.numer, self.denom)


###################
# Complex numbers #
###################

def add_complex(z1, z2):
    """Return a complex number z1 + z2"""
    return ComplexRI(z1.real + z2.real, z1.imag + z2.imag)


def mul_complex(z1, z2):
    """Return a complex number z1 * z2"""
    return ComplexMA(z1.magnitude * z2.magnitude, z1.angle + z2.angle)


class ComplexRI(object):
    """A rectangular representation of a complex number."""

    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    @property
    def magnitude(self):
        return (self.real ** 2 + self.imag ** 2) ** 0.5

    @property
    def angle(self):
        return atan2(self.imag, self.real)

    def __repr__(self):
        return 'ComplexRI({0}, {1})'.format(self.real, self.imag)


class ComplexMA(object):
    """A polar representation of a complex number."""

    def __init__(self, magnitude, angle):
        self.magnitude = magnitude
        self.angle = angle

    @property
    def real(self):
        return self.magnitude * cos(self.angle)

    @property
    def imag(self):
        return self.magnitude * sin(self.angle)

    def __repr__(self):
        return 'ComplexMA({0}, {1})'.format(self.magnitude, self.angle)


######################
# exponential number #
######################

def add_exponential(e1, e2):
    if e1.exp < e2.exp:
        return Exponential(e1.base * 10 ** (abs(e2.exp) - abs(e1.exp)) + e2.base, e2.exp)
    elif e1.exp > e2.exp:
        return Exponential(e2.base * 10 ** (abs(e1.exp) - abs(e2.exp)) + e1.base, e1.exp)
    return Exponential(e1.base + e2.base, e1.exp)


def mul_exponential(e1, e2):
    return Exponential(e1.base * e2.base, e1.exp + e2.exp)


class Exponential:
    def __init__(self, base, exp):
        self.base = base
        self.exp = exp

    @property
    def exp_number(self):
        return self.base * pow(10, self.exp)

    def __repr__(self):
        return 'Exponential({0}, {1})'.format(self.base, self.exp)


##############################
# Tag-based type dispatching #
##############################

def type_tag(x):
    """Return the tag associated with the type of x."""
    return type_tag.tags[type(x)]


type_tag.tags = {ComplexRI: 'com', ComplexMA: 'com', Rational: 'rat', Exponential: 'exp'}


def gen_add(z1, z2):
    """Add z1 and z2, which may be complex , rational or exponential."""
    types = (type_tag(z1), type_tag(z2))
    return gen_add.implementations[types](z1, z2)


def gen_mul(z1, z2):
    """mul z1 and z2, which may be complex , rational or exponential."""
    types = (type_tag(z1), type_tag(z2))
    return gen_mul.implementations[types](z1, z2)


def add_complex_and_rational(z, r):
    return ComplexRI(z.real + float(r.numer) / r.denom, z.imag)


add_rational_and_complex = lambda r, z: add_complex_and_rational(z, r)


def add_exponential_and_complex(e, z):
    return ComplexRI(e.exp_number + z.real, z.imag)


add_complex_and_exponential = lambda z, e: add_exponential_and_rational(e, z)


def add_exponential_and_rational(e, r):
    return ComplexRI((e.exp_number + float(r.numer) / r.denom), 0)


add_rational_and_exponential = lambda r, e: add_exponential_and_rational(e, r)


def mul_exponential_and_complex(e, z):
    return ComplexMA(e.exp_number * z.magnitude, z.angle)


mul_complex_and_exponential = lambda z, e: mul_exponential_and_complex(e, z)


def mul_exponential_and_rational(e, r):
    return Exponential(e.base * r.numer / r.denom, e.exp)


mul_rational_and_exponential = lambda r, e: mul_exponential_and_rational(e, r)

gen_add.implementations = {}
gen_add.implementations[('com', 'com')] = add_complex
gen_add.implementations[('rat', 'rat')] = add_rational
gen_add.implementations[('com', 'rat')] = add_complex_and_rational
gen_add.implementations[('rat', 'com')] = add_rational_and_complex
gen_add.implementations[('exp', 'exp')] = add_exponential
gen_add.implementations[('exp', 'com')] = add_exponential_and_complex
gen_add.implementations[('com', 'exp')] = add_complex_and_exponential
gen_add.implementations[('rat', 'exp')] = add_rational_and_exponential
gen_add.implementations[('exp', 'rat')] = add_exponential_and_rational
gen_mul.implementations = {}
gen_mul.implementations[('com', 'com')] = mul_complex
gen_mul.implementations[('rat', 'rat')] = mul_rational
gen_mul.implementations[('exp', 'exp')] = mul_exponential
gen_mul.implementations[('exp', 'com')] = mul_exponential_and_complex
gen_mul.implementations[('com', 'exp')] = mul_complex_and_exponential
gen_mul.implementations[('rat', 'exp')] = mul_rational_and_exponential
gen_mul.implementations[('exp', 'rat')] = mul_exponential_and_rational


###שאלה 4 #

def apply(operator_name, x, y):
    if operator_name == 'add':
        return gen_add(x, y)
    elif operator_name == 'mul':
        return gen_mul(x, y)


############
# Coercion #
############

def exponential_to_complex(x):
    return ComplexRI(x.exp_number, 0)


def rational_to_complex(x):
    return ComplexRI(x.numer / x.denom, 0)


coercions = {('rat', 'com'): rational_to_complex, ('exp', 'com'): exponential_to_complex}


###שאלה 5 #

def coerce_apply(operator_name, x, y):
    """Apply an operation ('add' or 'mul') to x and y."""
    tx, ty = type_tag(x), type_tag(y)
    if tx != ty:
        if (tx, ty) in coercions:
            tx, x = ty, coercions[(tx, ty)](x)
        elif (ty, tx) in coercions:
            ty, y = tx, coercions[(ty, tx)](y)
        else:
            x, y = coercions[(tx, 'com')](x), coercions[(ty, 'com')](y)
            tx, ty = type_tag(x), type_tag(y)
    elif tx or ty != 'com':
        x, y = coercions[(tx, 'com')](x), coercions[(ty, 'com')](y)
        tx, ty = type_tag(x), type_tag(y)

    assert tx == ty
    key = (operator_name, tx)
    return coerce_apply.implementations[key](x, y)


coerce_apply.implementations = {('mul', 'com'): mul_complex,
                                ('add', 'com'): add_complex,
                                ('add', 'exp'): add_complex,
                                ('mul', 'exp'): mul_complex}


###שאלה 6 #


def make_sequence(lst):
    try:
        if lst is nul:
            raise TypeError
        if type(ist) not in (tuple, list):
            raise TypeError
        def filter_list(p=lambda x: True):
            return tuple(filter(p,lst))
        def extend(lst2):
             nonlocal lst
             lst = lst + lst2
        def reverse():
            return tuple(lst[::-1])
        def get_filter_iterator(p=lambda x: True):
            ind = 0
            def next():
                nonlocal ind
                try:
                    item = lst[ind]
                    ind=(ind+1)%len(lst)
                    if p(item):
                        return item
                    else:
                        return next()
                except(ArithmeticError, ValueError, TypeError) as err:
                    ind=(ind+1)%len(lst)
                    return next()
            def reverse():
                nonlocal ind
                try:
                    ind=ind-1
                    if ind<0:
                        ind=len(lst)-1
                    item = lst[ind]
                    if p(item):
                        return item
                    else:
                        return reverse()
                except(ArithmeticError, ValueError, TypeError) as err:
                    ind-=1
                    if ind<0:
                        ind=len(lst)-1
                    return reverse()
            return {'next':next, 'reverse':reverse}
        return {'filter_iterator':get_filter_iterator, 'filter': filter_list, 'extend': extend, 'reverse': reverse}
    except TypeError:
        print('no sequence argument')


s1 = make_sequence()
s1=make_sequence((1,2,3,4,5))
p1=s1['filter_iterator'](lambda x: x<4)
for _ in range(6):
    print(p1['next']())




###שאלה 7 #

class Tree():
    def __init__(self, value, nodes=None):
        self.value = value
        self.nodes = nodes

    def __repr__(self):
        if self.nodes:
            return 'Tree({0},{1})'.format(self.value, repr(self.nodes))
        return 'Tree({0})'.format(self.value)


def BuildTree(tree):
    if type(tree) != tuple:
        return Tree(tree)
    hight = 1
    for i in tree:
        if type(i) == tuple:
            hight += 1
    return Tree(hight, list(map(BuildTree, tree)))


def is_AVL_tree(tree):
    return tree.nodes[0].value - tree.nodes[1].value in (1, 0)





###שאלה 8 #

def read_eval_print_loop():
    """Run a read-eval-print loop for calculator."""
    while True:
        try:
            expression_tree = calc_parse(input('calc> '))
            print(calc_eval(expression_tree))
        except (SyntaxError, TypeError, ZeroDivisionError) as err:
            print(type(err).__name__ + ':', err)
        except (KeyboardInterrupt, EOFError):  # <Control>-D, etc. <ctrl-C>
            print('Calculation completed.')
            return


# Eval & Apply

class Exp(object):
    """A call expression in Calculator.

    >>> Exp('add', [1, 2])
    Exp('add', [1, 2])
    >>> str(Exp('add', [1, Exp('mul', [2, 3])]))
    'add(1, mul(2, 3))'
    """

    def __init__(self, operator, operands):
        self.operator = operator
        self.operands = operands

    def __repr__(self):
        return 'Exp({0}, {1})'.format(repr(self.operator), repr(self.operands))

    def __str__(self):
        operand_strs = ', '.join(map(str, self.operands))
        return '{0}({1})'.format(self.operator, operand_strs)


def RepresentsInt(s):
    try:
        int(str(s))
        return True
    except ValueError:
        return False


def calc_eval(exp):
    """Evaluate a Calculator expression.

    >>> calc_eval(Exp('add', [2, Exp('mul', [4, 6])]))
    26
    """
    if type(exp) in (int, float):
        return exp
    if type(exp) == Exp:
        arguments = list(map(calc_eval, exp.operands))
        return calc_apply(exp.operator, arguments)


def calc_apply(operator, args):
    """Apply the named operator to a list of args.

    >>> calc_apply('+', [1, 2, 3])
    6
    >>> calc_apply('-', [10, 1, 2, 3])
    4
    >>> calc_apply('*', [])
    1
    >>> calc_apply('/', [40, 5])
    8.0
    """
    if operator in ('add', '+'):
        return sum(args)
    if operator in ('sub', '-'):
        if len(args) == 0:
            raise TypeError(operator + 'requires at least 1 argument')
        if len(args) == 1:
            return -args[0]
        return sum(args[:1] + [-arg for arg in args[1:]])
    if operator in ('mul', '*'):
        return reduce(mul, args, 1)
    if operator in ('div', '/'):
        if len(args) != 2:
            raise TypeError(operator + ' requires exactly 2 arguments')
        numer, denom = args
        return numer / denom
    if operator in ('compl', '!'):
        if len(args) == 0:
            raise TypeError(operator + 'requires at least 1 argument')
        if len(args) != 1:
            raise TypeError('/compl requires exactly 1 arguments')
        if not RepresentsInt(args[0]):
            raise TypeError(args[0], ' is not <class int>')
        return int(''.join((map(lambda x: str(10 - (int(x) + 1)), list(str(args[0]))))))


# Parsing

def calc_parse(line):
    """Parse a line of calculator input and return an expression tree."""
    tokens = tokenize(line)
    expression_tree = analyze(tokens)
    if len(tokens) > 0:
        raise SyntaxError('Extra token(s): ' + ' '.join(tokens))
    return expression_tree


def tokenize(line):
    """Convert a string into a list of tokens.

    >>> tokenize('add(2, mul(4, 6))')
    ['add', '(', '2', ',', 'mul', '(', '4', ',', '6', ')', ')']
    """
    spaced = line.replace('(', ' ( ').replace(')', ' ) ').replace(',', ' , ')
    return spaced.strip().split()


known_operators = ['add', 'sub', 'mul', 'div', 'compl', '+', '-', '*', '/', '!']


def convert_to_decimal(token):
    bases_helper = {'h': 16, 'q': 8, 'b': 2}
    base = token[-1]
    token = token[:len(token) - 1:]
    return int(token, bases_helper[base])


def analyze(tokens):
    """Create a tree of nested lists from a sequence of tokens.

    Operand expressions can be separated by commas, spaces, or both.

    >>> analyze(tokenize('add(2, mul(4, 6))'))
    Exp('add', [2, Exp('mul', [4, 6])])
    >>> analyze(tokenize('mul(add(2, mul(4, 6)), add(3, 5))'))
    Exp('mul', [Exp('add', [2, Exp('mul', [4, 6])]), Exp('add', [3, 5])])
    """
    assert_non_empty(tokens)
    token = analyze_token(tokens.pop(0))
    if type(token) in (int, float):
        return token
    if token[-1] in ['b', 'q', 'h']:
        return convert_to_decimal(token)
    if token in known_operators:
        if len(tokens) == 0 or tokens.pop(0) != '(':
            raise SyntaxError('expected ( after ' + token)
        return Exp(token, analyze_operands(tokens))
    else:
        raise SyntaxError('unexpected ' + token)


def analyze_operands(tokens):
    """Analyze a sequence of comma-separated operands."""
    assert_non_empty(tokens)
    operands = []
    while tokens[0] != ')':
        if operands and tokens.pop(0) != ',':
            raise SyntaxError('expected ,')
        operands.append(analyze(tokens))
        assert_non_empty(tokens)
    tokens.pop(0)  # Remove )
    return operands


def assert_non_empty(tokens):
    """Raise an exception if tokens is empty."""
    if len(tokens) == 0:
        raise SyntaxError('unexpected end of line')


def analyze_token(token):
    """Return the value of token if it can be analyzed as a number, or token.

    >>> analyze_token('12')
    12
    >>> analyze_token('7.5')
    7.5
    >>> analyze_token('add')
    'add'
    """
    try:
        return int(token)
    except (TypeError, ValueError):
        try:
            return float(token)
        except (TypeError, ValueError):
            return token


def run():
    read_eval_print_loop()

# run()
