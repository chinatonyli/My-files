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

        self.mainLayout = QtGui.QGraphicsLinearLayout()
        self.mainLayout.setContentsMargins(0, 0, 0, 0)
        self.mainLayout.setSpacing(0)

        self.avatar = self._avatar()
        self.mainLayout.addItem(self.avatar)
        self.mainLayout.setAlignment(self.avatar, Qt.AlignCenter)

        self.text = self._text()
        self.mainLayout.addItem(self.text)
        self.mainLayout.setAlignment(self.text, Qt.AlignCenter)

        self.mainWidget = QtGui.QGraphicsWidget()
        self.mainWidget.setContentsMargins(0, 0, 0, 0)
        self.mainWidget.setLayout(self.mainLayout)

        self.scene = QtGui.QGraphicsScene(self.mainWidget)
        self.scene.addItem(self.mainWidget)
        self.setScene(self.scene)

    @staticmethod
    def _avatar():
        pixmap = PixmapLayoutItem("./avatar.jpg")
        text = TextLayoutItem("Hello, world!")

        avatarLayout = QtGui.QGraphicsLinearLayout()
        avatarLayout.setContentsMargins(0, 0, 0, 0)
        avatarLayout.setOrientation(Qt.Vertical)
        avatarLayout.setSpacing(0)

        avatarLayout.addItem(pixmap)
        avatarLayout.setAlignment(pixmap, Qt.AlignCenter)

        avatarLayout.addItem(text)
        avatarLayout.setAlignment(text, Qt.AlignCenter)

        avatarWidget = QtGui.QGraout.setContentsMargins(0, 0, 0, 0)
        self.mainLayout.setSpacing(0)

        self.avatar = self._avatar()
        self.mainLayout.addItem(self.avatar)
        self.mainLayout.setAlignment(self.avatar, Qt.AlignCenter)

        self.text = selfphicsWidget()
        avatarWidget.setWindowFrameMargins(0, 0, 0, 0)
        avatarWidget.setContentsMargins(0, 0, 0, 0)
        avatarWidget.setLayout(avatarLayout)

        return avatarWidget

    @staticmethod
    def _text():
        text = TextLayoutItem("UNIX"# - Where there is a shell, "
                              #"there is a way."
                             )
        return text


if __name__ == "__main__":
    App = QtGui.QApplication(sys.argv)
    main = MainWindow()
    main.show()
    App.exec()
