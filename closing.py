#!/usr/bin/env python
# coding: utf-8


from contextlib import closing


class Connection:

    def open(self):
        print('opened')

    def close(self):
        print('closed')


if __name__ == '__main__':
    with closing(Connection()) as con:
        con.open()
        # do stuff with con
