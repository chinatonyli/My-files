import sys
from PyQt4 import QtCore, QtGui
from PyQt4.QtCore import Qt


class PixmapLayoutItem(QtGui.QGraphicsLayoutItem):

    def __init__(self, image, parent=None):
        super(PixmapLayoutItem, self).__init__(parent)
        self.pixmapItem = QtGui.QGraphicsPixmapItem()
        self.pixmapItem.setPixmap(QtGui.QPixmap(image))
        self.setGraphicsItem(self.pixmapItem)
        print(self.pixmapItem.boundingRect().size(),
              self.pixmapItem.pixmap().size())

    def sizeHint(self, which, constraint=QtCore.QSizeF()):
        return self.pixmapItem.boundingRect().size()

    def setGeometry(self, rect):
        self.pixmapItem.setPos(rect.topLeft())


class TextLayoutItem(QtGui.QGraphicsLayoutItem):

    def __init__(self, text, parent=None):
        super(TextLayoutItem, self).__init__(parent)
        self.textItem = QtGui.QGraphicsTextItem()
        self.textItem.setHtml(text)
        self.setGraphicsItem(self.textItem)
        print(self.textItem.boundingRect().size())

    def sizeHint(self, which, constraint=QtCore.QSizeF()):
        return self.textItem.boundingRect().size()

    def setGeometry(self, rect):
        self.textItem.setPos(rect.topLeft())


class MainWindow(QtGui.QGraphicsView):

    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)

        mainLayout = QtGui.QGraphicsLinearLayout()
        mainLayout.setSpacing(0)

        avatar = self._avatar()
        mainLayout.addItem(avatar)
        mainLayout.setAlignment(avatar, Qt.AlignCenter)

        text = self._text()
        mainLayout.addItem(text)
        mainLayout.setAlignment(text, Qt.AlignCenter)

        mainWidget = QtGui.QGraphicsWidget()
        mainWidget.setLayout(mainLayout)
        
        scene = QtGui.QGraphicsScene()
        scene.addItem(mainWidget)
        self.setScene(scene)

    @staticmethod
    def _avatar():
        pixmap = PixmapLayoutItem("./avatar.jpg")
        text = TextLayoutItem("Hello, world!")

        avatarLayout = QtGui.QGraphicsLinearLayout()
        avatarLayout.setOrientation(Qt.Vertical)
        avatarLayout.setSpacing(0)

        avatarLayout.addItem(pixmap)
        avatarLayout.setAlignment(pixmap, Qt.AlignCenter)

        avatarLayout.addItem(text)
        avatarLayout.setAlignment(text, Qt.AlignCenter)

        avatarWidget = QtGui.QGraphicsWidget()
        avatarWidget.setWindowFrameMargins(0, 0, 0, 0)
        avatarWidget.setContentsMargins(0, 0, 0, 0)
        avatarWidget.setLayout(avatarLayout)

        return avatarWidget

    @staticmethod
    def _text():
        text = TextLayoutItem("UNIX - Where is a shell, where is a way.")
        return text


if __name__ == "__main__":
    App = QtGui.QApplication(sys.argv)
    main = MainWindow()
    main.show()
    App.exec()