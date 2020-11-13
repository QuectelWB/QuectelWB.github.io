'''
https://blog.csdn.net/qq_43017750/article/details/96714797
'''

from lxml import etree
import requests

main_url = 'http://pic.netbian.com'    #主url，用于后期补齐图片url。

main_page_url = 'http://pic.netbian.com/e/search/result/index.php?page={}&searchid=1997'
#main_page_url = 'http://pic.netbian.com/e/search/result/?searchid=14984'
#mian_page_url 主页面url，用于解析获取图片详情页的url，
#其中{}的作用是使用format函数将内容以字符串的形式添加到{}的位置

header = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:66.0) Gecko/20100101 Firefox/66.0',}
#请求头，用于后期访问网页，下载图片


def get_html(url):
    """定义一个用于获取网页代码的函数，调用时需要传递目标url"""
    return requests.get(url,headers=header).content.decode('gbk')



def get_sub_url(html):
    """从主页面的源码中提取子页面的url"""
    html_etree = etree.HTML(html)
    sub_url = html_etree.xpath('//ul[@class="clearfix"]/li/a/@href')
    return sub_url


def get_img_info(html):
    """从子页面的源码中提取图片url"""
    html_etree = etree.HTML(html)
    img_url = html_etree.xpath('//div[@class="photo-pic"]/a/img/@src')[0]
    img_title = html_etree.xpath('//div[@class="photo-pic"]/a/img/@title')[0].replace(' ','').replace('《','').replace('》','').replace("(","").replace(")","").replace(":","").replace("：",'')
    return img_url,img_title


def save(url,title):
    """下载并保存图片"""
    img = requests.get(url,headers=header).content
#    img_name = 'imgs/'+title+'.jpg'
    img_name = 'yn/'+title+'.jpg'
    with open (img_name,'wb') as save_object:
        save_object.write(img)

for number in range(533):
    html = get_html(main_page_url.format(number))
    print ("[+]正在爬取第{}页".format(number))
    urls = get_sub_url(html)
    for url in urls:
        sub_page_url = main_url+url
        sub_html = get_html(sub_page_url)
        img_url,img_title = get_img_info(sub_html)
        full_img_url = main_url + img_url
        save(full_img_url,img_title) 
