from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

class DumbDialog(QDialog):
    def __init__(self, parent=None):
        super(DumbDialog, self).__init__(parent)
        # self.bottomLayout = QGridLayout()  # 下方布局
        # self.gridLayout = QGridLayout()
        self._title = "Digital Image Processing Program"
        self._diawidth = 500
        self._diaheight = 600
        self.setWindowTitle(self._title)        # 设置界面标题
        self.setMinimumHeight(self._diaheight)  # 设置界面高度
        self.setMinimumWidth(self._diawidth)    # 设置界面宽度
        self.text = QLabel(" ")
        self.imageView = QLabel("add a image file")  # 设置标签
        self.imageView.setAlignment(Qt.AlignCenter)
        self.btn_open = QPushButton("选择一张图片")   # 设置按钮
        self.btn_open.setToolTip("选择一张图片")      # 设置鼠标放置提示
        self.btn_open.clicked.connect(self.on_btn_open_clicked)  # 设置点击按钮事件
        self.button1 = QPushButton("灰度化", self)
        self.button1.setToolTip("将当前彩色图像灰度化")
        self.button1.move(15, 570)              # 设置按钮位置
        self.button1.clicked.connect(self.on_click1)
        self.button2 = QPushButton("直方图", self)     # 下同
        self.button2.setToolTip("绘制灰度直方图")
        self.button2.move(115, 570)
        self.button2.clicked.connect(self.on_click2)
        self.button3 = QPushButton("图像相加", self)
        self.button3.setToolTip("实现将此图片与其旋转180°的两幅相同大小图像相加")
        self.button3.move(215, 570)
        self.button3.clicked.connect(self.on_click3)
        self.button4 = QPushButton("对数变换", self)
        self.button4.setToolTip("实现对数变换")
        self.button4.move(315, 570)
        self.button4.clicked.connect(self.on_click4)
        self.button5 = QPushButton("图像锐化", self)
        self.button5.setToolTip("实现LoG算子图像锐化")
        self.button5.move(415, 570)
        self.button5.clicked.connect(self.on_click5)
        self.button6 = QPushButton("图像分割", self)
        self.button6.setToolTip("实现Otsu图像分割")
        self.button6.move(515, 570)
        self.button6.clicked.connect(self.on_click6)
        self.vlayout = QVBoxLayout()            # 设置页面格式
        self.vlayout.addWidget(self.btn_open)   # 页面最上方为open布局
        self.vlayout.addWidget(self.imageView)  # 页面中间为图片显示布局
        self.vlayout.addWidget(self.text)       # 页面最下方为功能布局
        self.setLayout(self.vlayout)
        self.filename = "apple.bmp"     # 设置默认文件名
        if len(self.filename):          # 将默认图片放置在图片显示区
            self.image = QImage(self.filename)
            self.imageView.setPixmap(QPixmap.fromImage(self.image))
            self.resize(self.image.width(), self.image.height())
        self.show()

    """读入图像"""
    @pyqtSlot(bool)
    def on_btn_open_clicked(self, checked):
        self.filename = QFileDialog.getOpenFileName(self, "OpenFile", ".", "Image Files(*.jpg *.jpeg *.png *.bmp)")[0]     # 选择图片
        if len(self.filename):              # 读入图像并按GUI框架设置的大小调整，以显示在GUI页面中
            self.image = QImage(self.filename)
            self.imageView.setPixmap(QPixmap.fromImage(self.image))
            self.resize(self.image.width(), self.image.height())

    """灰度化"""
    @pyqtSlot()
    def on_click1(self):
        import numpy as np
        import matplotlib.pyplot as plt
        import matplotlib.image as mpimg
        def rgb2gray(rgb):  # RGB到灰度图转换公式
            return np.dot(rgb[..., :3], [0.299, 0.587, 0.114])
        img = mpimg.imread(self.filename)  # 读取图片
        gray = rgb2gray(img)
        plt.imshow(gray, cmap=plt.get_cmap('gray'))
        plt.title("Gray Image")  # 设置图片标题
        plt.show()  # 显示灰度图

    """直方图"""
    def on_click2(self):
        import numpy as np
        import matplotlib.pyplot as plt
        import cv2
        image = cv2.imread(self.filename, cv2.IMREAD_GRAYSCALE)  # 以灰度模式读入图片
        rows, cols = image.shape
        grayHist = np.zeros([256], np.uint64)  # 创建一个一维数组grayHist，长度为255，用其序列表示灰度值
        for r in range(rows):
            for c in range(cols):
                grayHist[image[r][c]] += 1  # 遍历所有元素，把其灰度值所代表的序列指向的数组grayHist累加
        x_range = range(256)  # 画出直方图
        plt.plot(x_range, grayHist, 'r', linewidth=2, c='blue')
        y_maxValue = np.max(grayHist)  # 设置坐标轴范围
        plt.axis([0, 255, 0, y_maxValue])
        plt.xlabel("gray level")  # 设置坐标标签
        plt.ylabel("num of pixles")
        plt.title("Histogram")  # 设置图片标题
        plt.show()  # 显示灰度直方图

    """图像相加"""
    def on_click3(self):
        import cv2
        import imutils
        img1 = cv2.imread(self.filename)  # 读取图片
        img2 = imutils.rotate(img1, 180)  # 对原图片旋转180°作为另一张累加图片
        addimg = img1
        for i in range(img1.shape[0]):
            for j in range(img1.shape[1]):
                for k in range(img1.shape[2]):
                    addimg[i, j, k] = 0.5 * img1[i, j, k] + 0.5 * img2[i, j, k]  # 遍历所有元素，把其两个图像中的各元素对应累加
        cv2.imwrite('Picture Fusion.jpg', addimg)  # 将累加的结果写入新的图片
        cv2.imshow('Picture Fusion.jpg', addimg)  # 显示结果
        if cv2.waitKey(0):  # 停顿
            cv2.destroyAllWindows()

    """对数变换"""
    def on_click4(self):
        import matplotlib.pyplot as plt
        import numpy as np
        import math

        def function(img, c):
            rows, cols, dims = img.shape
            emptyImage = np.zeros((rows, cols, dims), np.uint8)  # 创建一个三维数组emptyImage，用其序列表示重新量化的值
            max1 = img.max()
            for m in range(dims):
                for i in range(rows):
                    for j in range(cols):
                        r = img[i, j, m]  # 重新量化
                        emptyImage[i, j, m] = ((c * math.log(1 + r) - c * math.log(1 + 0)) / (
                                    c * math.log(1 + max1) - c * math.log(
                                1 + 0))) * max1  # 遍历所有元素
            return emptyImage
        img = plt.imread(self.filename)
        result = function(img, 1)
        plt.title("Logarithmic Transformation")  # 设置图片标题
        plt.imshow(result)
        plt.show()  # 显示结果

    """图像锐化"""
    def on_click5(self):
        # 定义卷积函数
        def filter(image, kernel):
            image = np.array(image)
            newImage = np.zeros(image.shape, dtype=np.float)  # 初始化一个相同尺寸的数组
            for i in range(image.shape[0] - kernel.shape[0] + 1):
                for j in range(image.shape[1] - kernel.shape[1] + 1):# 进行卷积操作,实则是对应的窗口覆盖下的矩阵对应元素值相乘,卷积操作
                    newImage[i + 1, j + 1] = abs(np.sum(image[i: i + kernel.shape[0],
                                                        j: j + kernel.shape[1]] * kernel))
            newImage = newImage.clip(0, 255)  # 去掉矩阵乘法后的小于0的和大于255的原值,重置为0和255
            newImage = np.rint(newImage).astype('uint8')  # 将数组整数化
            return newImage

        import cv2
        import numpy as np
        image = cv2.imread(self.filename, 0)  # 加载图像
        kernel_LoG = np.array([  # 5*5 LoG卷积模板
            [0, 0, -1, 0, 0],
            [0, -1, -2, -1, 0],
            [-1, -2, 16, -2, -1],
            [0, -1, -2, -1, 0],
            [0, 0, -1, 0, 0]])
        output = filter(image, kernel_LoG)  # 调用上面定义的卷积函数
        cv2.imshow('LoG Sharpening', output)  # 显示锐化效果
        if cv2.waitKey(0):  # 停顿
            cv2.destroyAllWindows()

    """Otsu"""
    def on_click6(self):
        # coding:utf-8
        import cv2
        import numpy as np
        from matplotlib import pyplot as plt
        import random

        # 将不足8*m位的染色体扩展为8*m位
        def expand(k, m):
            for i in range(len(k)):
                k[i] = k[i][:2] + '0' * (8 * m + 2 - len(k[i])) + k[i][2:len(k[i])]
            return k

        def Hist(image):
            a = [0] * 256
            h = image.shape[0]
            w = image.shape[1]
            MN = h * w
            average = 0.0
            for i in range(w):
                for j in range(h):
                    pixel = int(image[j][i])
                    a[pixel] = a[pixel] + 1
            for i in range(256):
                a[i] = a[i] / float(MN)
                average = average + a[i] * i
            return a, average

        # 解析多阈值基因串
        def getTh(seed, m):
            th = [0, 256]
            seedInt = int(seed, 2)
            for i in range(0, m):
                tmp = seedInt & 255
                if tmp != 0:
                    th.append(tmp)
                seedInt = seedInt >> 8
            th.sort()
            return th

        # 适应度函数 Ostu全局算法
        def fitness(seed, p, average, m):
            Var = [0.0] * len(seed)
            g_muT = 0.0

            for i in range(256):
                g_muT = g_muT + i * p[i]

            for i in range(len(seed)):
                th = getTh(seed[i], m)
                for j in range(len(th) - 1):
                    w = [0.0] * (len(th) - 1)
                    muT = [0.0] * (len(th) - 1)
                    mu = [0.0] * (len(th) - 1)
                    for k in range(th[j], th[j + 1]):
                        w[j] = w[j] + p[k]
                        muT[j] = muT[j] + + p[k] * k
                    if w[j] > 0:
                        mu[j] = muT[j] / w[j]
                        Var[i] = Var[i] + w[j] * pow(mu[j] - g_muT, 2)
            return Var

        # 选择算子轮盘赌选择算法
        def wheel_selection(seed, Var):
            var = [0.0] * len(Var)
            s = 0.0
            n = [''] * len(seed)
            sumV = sum(Var)
            for i in range(len(Var)):
                var[i] = Var[i] / sumV
            for i in range(1, len(Var)):
                var[i] = var[i] + var[i - 1]
            for i in range(len(seed)):
                s = random.random()
                for j in range(len(var)):
                    if s <= var[j]:
                        n[i] = seed[j]
            return n

        # 单点交叉算子
        def Cross(Next, m):
            for i in range(0, len(Next) - 1, 2):
                if random.random() < 0.7:
                    if m > 2:
                        tmp = Next[i][10:]
                        Next[i] = Next[i][:10] + Next[i + 1][10:]
                        Next[i + 1] = Next[i + 1][:10] + tmp
                    else:
                        tmp = Next[i][6:]
                        Next[i] = Next[i][:6] + Next[i + 1][6:]
                        Next[i + 1] = Next[i + 1][:6] + tmp
            return Next

        # 变异算子
        def Variation(Next):
            for i in range(len(Next)):
                if random.random() < 0.06:
                    Next[i] = bin(int(Next[i], 2) + 2)
            return Next

        # 多阈值分割
        def genetic_thres(image, k, m):
            th = image
            for i in range(image.shape[0]):
                for j in range(image.shape[1]):
                    for t in range(1, len(k) - 1):
                        if k[t - 1] <= image[i][j] < k[t]:
                            th[i][j] = int(k[t - 1])
            return th

        # main
        imagesrc = cv2.imread(self.filename)
        gray = cv2.cvtColor(imagesrc, cv2.COLOR_BGR2GRAY)

        m = 3  # 阈值数
        items_x = list(range(0, imagesrc.shape[0]))
        items_y = list(range(0, imagesrc.shape[1]))
        random.shuffle(items_x)
        random.shuffle(items_y)
        x = items_x[0:20 * m]  # 产生随机x坐标
        y = items_y[0:20 * m]  # 产生随机y坐标
        seed = []
        Var = 0.0
        times = 0
        k = 0
        P, average = Hist(gray)  # 计算直方图，P为各灰度的概率的数组，average为均值
        for i in range(0, 20):
            code = int(0)
            for j in range(0, m):
                code = code + gray[x[i * j]][y[i * j]] << j * 8  # 将阈值连起来组成一个8*m比特的基因串
            seed.append(bin(code))  # 生成第一代

        while times < 2000:
            Var = fitness(seed, P, average, m)
            Next = wheel_selection(seed, Var)
            Next = Cross(Next, m)
            Next = expand(Variation(Next), m)
            seed = Next
            times = times + 1

        for j in range(len(Var)):
            if Var[j] == max(Var):
                k = getTh(Next[j], m)
        print(k)
        th1 = genetic_thres(gray, k, m)
        plt.imshow(th1, "gray")
        titleName = ''
        for i in range(1, len(k) - 1):
            titleName = titleName + str(k[i]) + ', '
        titleName = titleName[:len(titleName) - 2]
        plt.title("threshold is " + titleName), plt.xticks([]), plt.yticks([])
        plt.show()

import sys
if __name__ == "__main__":
    app = QApplication(sys.argv)
    dia = DumbDialog()
    dia.show()
    app.exec_()