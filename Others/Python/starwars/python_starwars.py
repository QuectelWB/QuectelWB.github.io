'''
From 微信公众号 偶尔有点小迷糊

链接: https://pan.baidu.com/s/1_dfdKmmfF1oSprXm7RPdqQ 提取码: m2iu

'''
import cv2                                  # pip install opencv-python -i https://pypi.mirrors.ustc.edu.cn/simple/
from PIL import Image, ImageDraw, ImageFont # pip install pillow -i https://pypi.mirrors.ustc.edu.cn/simple/
import numpy as np                          # pip install numpy -i https://pypi.mirrors.ustc.edu.cn/simple/
import pygame                               # pip install pygame -i https://pypi.mirrors.ustc.edu.cn/simple/


# 输出内容
lstText = ['星  球  大  战', 
            '　',
            ' （滑 稽 解 说）  ',
            '欧比旺初识安纳金，觉得他骨骼惊奇，是个绝地武士的奇才。',
            '然而安纳金长大后受到黑暗原力的诱惑杀死了欧比旺。欧比旺',
            '斥责道：年轻人不讲武德！安纳金不服反问：你在教我做事？',
            '后来他化身黑武士维达，成为邪恶力量的一员。　　　　　　',
            '　',
            '维达曾有一对儿女，被别人抚养，长大后加入帝国反抗军，和',
            '老爸对着干，粉碎了维达的阴谋，正所谓：凭实力坑爹。　　',
            '　',
            '正片放完，UP主要开始哔哔，讲解代码了'
        ]

#字体及大小
fontTitle = ImageFont.truetype('myBold.otf', 100)
font = ImageFont.truetype('myBold.otf', 40)


# 异步播放音乐
def playBgm():
    pygame.mixer.init()
    pygame.mixer.music.load('starwars_bgm.mp3')
    pygame.mixer.music.play(start=0.0)


# 停止播放
def stopBgm():
    pygame.mixer.music.stop()


# 创建透视变换矩阵
def generateTransformMatrix():
    k = 0.3 # 倾斜程度，越大越斜
    src = np.float32([[0, 0],[w, 0],[0, h],[w, h]])
    dst = np.float32([[w*k, h*0.1],[w*(1-k), h*0.1],[0, h],[w, h]])
    return cv2.getPerspectiveTransform(src, dst)


# 正片开始
if __name__ == "__main__":
    #bgm登场
    playBgm()

    # 读取星空背景图片
    imgStars = cv2.imread("starwars_bg.jpg", cv2.IMREAD_COLOR)
    h, w, _ = imgStars.shape

    # 创建透视变换矩阵
    matrix = generateTransformMatrix()

    # 用循环做动画效果
    yTextPos = h
    while cv2.waitKey(20) != ord('q'):
        
        imgTextLayer = Image.new("RGB", (w, h))          # 创建文字图层
        draw = ImageDraw.Draw(imgTextLayer)              # 取得绘图的对象

        for i in range(len(lstText)):                    # 输出多行文字（汉字）
            curFont = (font if (i != 0) else fontTitle)  # 标题和正文用不同的字体
            textW, textH = curFont.getsize(lstText[i])   # 取得字符串的宽、高信息

            xTextPos = (w - textW) >> 1                # 文字居中绘制
            draw.text((xTextPos, yTextPos + i * (textH + 8)), lstText[i], font=curFont, fill=(255, 202, 13))

        # PIL输出中文完毕，交给opencv做透视变换
        im = cv2.cvtColor(np.asarray(imgTextLayer), cv2.COLOR_RGB2BGR)
        imgPerspective = cv2.warpPerspective(im, matrix, (w, h))

        # 变换后的图片和星空背景重叠后显示
        imgAdded = cv2.add(imgPerspective, imgStars)
        cv2.imshow('https://space.bilibili.com/39665558', imgAdded)

        # 下次绘制文字的位置往上挪一点
        yTextPos -= 1

    # 善后事宜
    stopBgm()
    cv2.destroyAllWindows()
