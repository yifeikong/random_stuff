#!/usr/bin/env python
# coding: utf-8

i = 0

def foo():
    global i
    print 'foo' + str(i)
    i += 1
    if i < 10:
        bar()

def bar():
    print 'bar'
    foo()

if __name__ == '__main__':
    foo()
