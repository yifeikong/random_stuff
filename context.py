#!/usr/bin/env python
# coding: utf-8


from contextlib import contextmanager


@contextmanager
def open_many(files=None, mode='r'):
    if files is None:
        files = []
    try:
        fds = []
        for f in files:
            fds.append(open(f, mode))
        yield fds
    except ValueError as e:
        print(e)
    finally:
        for fd in fds:
            fd.close()


if __name__ == '__main__':
    with open_many(['a.txt', 'b.txt'], 'r') as files:
        for f in files:
            print(f.read())
