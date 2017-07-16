# coding: utf-8

import lxml.html
import re
from urllib.request import urlopen

PAGE = 'http://3g.renren.com/status/getdoing.do?curpage={current_page}&id=xxxxx&sid=xxxxxx'
REPLY_PAGE = 'http://3g.renren.com/status/replystatus.do?curpage={current_page}&doingid={status_id}&id=xxxxxx&sid=xxxxxxx'

def crawl(start):
    for i in range(start, 106):
        print("crawl page {}".format(i))
        page_url = PAGE.format(current_page=i)
        page_content = urlopen(page_url).read()
        page_content = convert_links(page_content, i)
        with open('{}.html'.format(i), 'wb') as html_file:
            html_file.write(page_content)

def convert_links(page, current_page):
    tree = lxml.html.fromstring(page)

    el = tree.xpath('//a[@title="下一页"]')
    if el:
        el[0].attrib['href'] = '{}.html'.format(current_page + 1)

    el = tree.xpath('//a[@title="上一页"]')
    if el:
        el[0].attrib['href'] = '{}.html'.format(current_page - 1)

    reply_els = tree.xpath('//a[text()[contains(., "回复")]]')
    for el in reply_els:
        reply_url = el.attrib['href']
        reply_id = get_reply_id(reply_url)
        crawl_reply(reply_id, 0)
        el.attrib['href'] = 'reply_{}_0.html'.format(reply_id)

    return lxml.html.tostring(tree)

def crawl_reply(status_id, current_page):
    reply_url = REPLY_PAGE.format(status_id=status_id, current_page=current_page)
    print("crawl reply {}".format(reply_url))
    reply_content = urlopen(reply_url).read().decode('utf-8')
    if current_page == 0:
        if '末页' in reply_content:
            page_num = int(re.findall(r'\(第1/(\d+)页\)', reply_content)[0])
            for i in range(1, page_num):
                crawl_reply(status_id, i)
    tree = lxml.html.fromstring(reply_content.encode('utf-8'))
    el = tree.xpath('//a[@title="下一页"]')
    if el:
        el[0].attrib['href'] = 'reply_{}_{}.html'.format(status_id, current_page+1)
    el = tree.xpath('//a[@title="上一页"]')
    if el:
        el[0].attrib['href'] = 'reply_{}_{}.html'.format(status_id, current_page-1)
    with open('reply_{}_{}.html'.format(status_id, current_page), 'wb') as fh:
        fh.write(lxml.html.tostring(tree))


def get_reply_id(reply_url):
    import re
    return re.findall(r'doingid=(\d+)', reply_url)[0]


if __name__ == '__main__':
    import sys
    crawl(int(sys.argv[1]))
