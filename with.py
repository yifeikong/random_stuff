#!/usr/bin/env python
# coding: utf-8


class open_many:

    def __init__(self, files=None, mode='r'):
        if files is None:
            self._files = []
        else:
            self._files = files
        self.mode = mode
        self.fds = []  # fd is short for file descriptor

    def __enter__(self):
        print('-->enter')
        for f in self._files:
            print('-->opening file')
            self.fds.append(open(f, self.mode))
        return self.fds

    def __exit__(self, exc_type, exc_val, traceback):
        print('-->exit')
        for fd in self.fds:
            print('-->closing file')
            fd.close()
        if exc_type == ValueError:
            print('-->exception: ' + str(exc_val))
            return True


if __name__ == '__main__':
    print('')
    with open_many(['a.txt', 'b.txt'], 'r') as files:
        for f in files:
            print f.read()
    print('')
    with open_many() as files:
        raise ValueError('captured')
    print('')
    with open_many() as files:
        raise Exception('uncaptureable')
