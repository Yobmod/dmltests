import sys

from PySide2.QtCore import Qt
from PySide2.QtGui import QIcon
from PySide2.QtWidgets import QApplication, QMainWindow, QWidget
from PySide2.QtWidgets import QLabel, QAction, QMessageBox, QCheckBox, QPushButton, QComboBox
from PySide2.QtWidgets import QCalendarWidget, QProgressBar, QFontDialog, QColorDialog, QStyleFactory
from PySide2.QtWidgets import QVBoxLayout  # , QGridLayout
from pycalc import PyCalcUi

# from typing import Union
from typing_extensions import Literal


class Window(QMainWindow):

    def __init__(self) -> None:
        super(Window, self).__init__()
        self.setGeometry(50, 50, 500, 300)
        self.setWindowTitle("PyQT tuts!")
        self.setWindowIcon(QIcon('pythonlogo.png'))

        extractAction = QAction("&GET TO THE CHOPPAH!!!", self)
        extractAction.setShortcut("Ctrl+Q")
        extractAction.setStatusTip('Leave The App')
        extractAction.triggered.connect(self.close_application)

        self.statusBar()

        mainMenu = self.menuBar()
        fileMenu = mainMenu.addMenu('&File')
        fileMenu.addAction(extractAction)

        self._setup()

    def _setup(self) -> None:

        # Set the central widget
        self._centralWidget = QWidget()
        self.setCentralWidget(self._centralWidget)
        self.generalLayoutMaster = QVBoxLayout()
        self._centralWidget.setLayout(self.generalLayoutMaster)

        extractAction = QAction(QIcon('coffeebean.ico'), 'Flee the Scene', self)
        extractAction.triggered.connect(self.close_application)
        self.toolBar = self.addToolBar("Extraction")
        self.toolBar.addAction(extractAction)

        self._font_choice()
        self._font_color()
        self._quit_button()
        self._calender()
        self._calculator()
        self._style_selector()
        self._progressbar_button()
        self._resize_checkbox()

    def _resize_checkbox(self) -> None:
        self.checkBox = QCheckBox('Enlarge Window', self)
        self.checkBox.move(300, 25)
        self.checkBox.stateChanged.connect(self.enlarge_window_with_check)
        # self.checkBox.stateChanged.connect(self.enlarge_window_from_state)  ## useable with multple widgets

    def _progressbar_button(self) -> None:
        self.progress = QProgressBar(self)
        self.progress.setGeometry(200, 80, 250, 20)
        self.generalLayoutMaster.addWidget(self.progress)

        self.btn = QPushButton("Download", self)
        self.btn.move(200, 120)
        self.btn.clicked.connect(self.download)
        self.generalLayoutMaster.addWidget(self.btn)

    def _style_selector(self) -> None:
        # print(self.style().objectName())
        self.styleChoice = QLabel("Windows Vista", self)
        # self.styleChoice.move(50, 150)
        self.generalLayoutMaster.addWidget(self.styleChoice)

        comboBox = QComboBox(self)
        comboBox.addItem("motif")
        comboBox.addItem("Windows")
        comboBox.addItem("cde")
        comboBox.addItem("Plastique")
        comboBox.addItem("Cleanlooks")
        comboBox.addItem("windowsvista")
        # comboBox.move(50, 250)
        comboBox.activated[str].connect(self.style_choice)
        self.generalLayoutMaster.addWidget(comboBox)

    def _calender(self) -> None:
        cal = QCalendarWidget(self)
        #cal.move(500, 200)
        #cal.resize(200, 200)
        cal.setFixedSize(235, 235)
        self.generalLayoutMaster.addWidget(cal)

    def _quit_button(self) -> None:
        btn = QPushButton("Quit", self)
        btn.clicked.connect(self.close_application)
        btn.resize(btn.minimumSizeHint())
        # btn.move(0, 100)
        self.generalLayoutMaster.addWidget(btn)


    def _font_choice(self) -> None:
        fontChoice = QAction('Font', self)
        fontChoice.triggered.connect(self.font_choice)
        #self.toolBar = self.addToolBar("Font")
        self.toolBar.addAction(fontChoice)

    def _font_color(self) -> None:
        fontColor = QAction('Font bg Color', self)
        fontColor.triggered.connect(self.color_picker)

        self.toolBar.addAction(fontColor)

    def _calculator(self) -> None:
        calculator = PyCalcUi(self)
        self.generalLayoutMaster.addWidget(calculator)

    def color_picker(self) -> None:
        color = QColorDialog.getColor()
        self.styleChoice.setStyleSheet("QWidget { background-color: %s}" % color.name())

    def font_choice(self) -> None:
        valid, font = QFontDialog.getFont()
        if valid is True:
            self.styleChoice.setFont(font)

    def style_choice(self, text: str) -> None:
        self.styleChoice.setText(text)
        QApplication.setStyle(QStyleFactory.create(text))

    def download(self) -> None:
        self.completed: float = 0.0

        while self.completed < 100:
            self.completed += 0.0001
            self.progress.setValue(self.completed)

    def enlarge_window_with_check(self) -> None:
        if self.checkBox.isChecked() is True:
            self.setGeometry(50, 50, 1000, 600)
        else:
            self.setGeometry(50, 50, 500, 300)

    def enlarge_window_from_state(self, state: Literal[0, 2]) -> None:
        """gets state from the signal, then can use function with multiple widgets"""
        if state == Qt.Checked:  # == 2
            self.setGeometry(50, 50, 1000, 600)
        else:  # state = 0
            self.setGeometry(50, 50, 500, 300)

    def close_application(self) -> None:
        choice = QMessageBox.question(self, 'Extract!',
                                            "Get into the chopper?",
                                            QMessageBox.Yes | QMessageBox.No)
        if choice == QMessageBox.Yes:
            print("Extracting Naaaaaaoooww!!!!")
            sys.exit()
        else:
            pass


def run() -> None:
    app = QApplication(sys.argv)
    GUI = Window()
    GUI.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    run()
