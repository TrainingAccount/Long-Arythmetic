# This file was automatically generated by SWIG (http://www.swig.org).
# Version 2.0.7
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.



from sys import version_info
if version_info >= (2,6,0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_longnumber_cpp', [dirname(__file__)])
        except ImportError:
            import _longnumber_cpp
            return _longnumber_cpp
        if fp is not None:
            try:
                _mod = imp.load_module('_longnumber_cpp', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _longnumber_cpp = swig_import_helper()
    del swig_import_helper
else:
    import _longnumber_cpp
del version_info
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError(name)

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


class LongNum(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LongNum, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LongNum, name)
    __repr__ = _swig_repr
    __swig_destroy__ = _longnumber_cpp.delete_LongNum
    __del__ = lambda self : None;
    def __add__(self, *args): return _longnumber_cpp.LongNum___add__(self, *args)
    def __sub__(self, *args): return _longnumber_cpp.LongNum___sub__(self, *args)
    def __mul__(self, *args): return _longnumber_cpp.LongNum___mul__(self, *args)
    def __div__(self, *args): return _longnumber_cpp.LongNum___div__(self, *args)
    def __mod__(self, *args): return _longnumber_cpp.LongNum___mod__(self, *args)
    def __xor__(self, *args): return _longnumber_cpp.LongNum___xor__(self, *args)
    def __init__(self, *args): 
        this = _longnumber_cpp.new_LongNum(*args)
        try: self.this.append(this)
        except: self.this = this
    def getNumber(self): return _longnumber_cpp.LongNum_getNumber(self)
    def toFile(self, *args): return _longnumber_cpp.LongNum_toFile(self, *args)
LongNum_swigregister = _longnumber_cpp.LongNum_swigregister
LongNum_swigregister(LongNum)

# This file is compatible with both classic and new-style classes.

