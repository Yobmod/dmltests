"""PyCalc is a simple calculator built using Python and PyQt5."""

import sys
from functools import partial
from pathlib import Path

from PySide2.QtCore import Qt
from PySide2.QtGui import QIcon
from PySide2.QtWidgets import QApplication, QMainWindow
from PySide2.QtWidgets import QWidget, QGridLayout, QVBoxLayout, QPushButton, QLineEdit

from typing import Union, Dict, Tuple, Optional, cast, Protocol


# TODO: add ideal gas subwindw: pressure(barr/psi.pa, temp(oC/K), label showing which R, vol(m3, dm3, cm3), moles <- d, mass, mr)
# TODO: add graph window
# TODO: add opencv image window

class EvalExpressionCallable(Protocol):
    """ == Callable[[str], int]"""
    def __call__(self, expression: str) -> str: ...


class idealGas(QMainWindow):
    """Ideal Gas calculator"""

    def __init__(self, parent: Optional[QMainWindow] = None) -> None:
        super().__init__()


class PyCalcFrame(QMainWindow):

    def __init__(self,
                 win_title: str = 'PyCalc',
                 win_size: Tuple[int, int] = (235, 235),
                 icon_path: Union[Path, str, None] = Path(R'.\coffeebean.ico')
                 ) -> None:
        """View initializer."""
        super().__init__()

        """
        # Set some main window's properties
        self.setWindowTitle(win_title)
        self.setFixedSize(win_size[0], win_size[1])
        if isinstance(icon_path, Path):
            icon_path = str(icon_path.resolve())
        self.setWindowIcon(QIcon(icon_path))
        """

        # Set the central widget
        self._centralWidget = PyCalcUi(win_title="")
        self.setCentralWidget(self._centralWidget)
        self.generalLayout = QVBoxLayout()
        self._centralWidget.setLayout(self.generalLayout)
        self._open_calc()

    def _open_calc(self) -> None:
        calc_view = PyCalcUi()
        # calc_view.show()
        self.calc_widget = PyCalcCtrl(view=calc_view, model=evaluateExpression)



class PyCalcUi(QMainWindow):
    """PyCalc's View (GUI)."""

    def __init__(self,
                 win_title: str = 'PyCalc',
                 win_size: Tuple[int, int] = (235, 235),
                 icon_path: Union[Path, str, None] = Path(R'.\coffeebean.ico')
                 ) -> None:
        """View initializer."""
        super().__init__()

        # Set some main window's properties
        self.setWindowTitle(win_title)
        self.setFixedSize(win_size[0], win_size[1])
        if isinstance(icon_path, Path):
            icon_path = str(icon_path.resolve())
        self.setWindowIcon(QIcon(icon_path))

        # Set the central widget
        self._centralWidget = QWidget(self)
        self.setCentralWidget(self._centralWidget)
        self.generalLayout = QVBoxLayout()
        self._centralWidget.setLayout(self.generalLayout)

        # Create the display and the buttons
        self._createDisplay()
        self._createButtons()

    def _createDisplay(self) -> None:
        """Create the display."""
        # Create the display widget
        self.display = QLineEdit()
        # Set some display's properties
        self.display.setFixedHeight(35)
        self.display.setAlignment(Qt.AlignRight)
        self.display.setReadOnly(True)
        # Add the display to the general layout
        self.generalLayout.addWidget(self.display)

    def _createButtons(self) -> None:
        """Create the buttons."""
        self.buttons: Dict[str, QPushButton] = {}
        buttonsLayout = QGridLayout()
        # Button text | position on the QGridLayout
        buttons: Dict[str, Tuple[int, int]] = {'7': (0, 0), '8': (0, 1), '9': (0, 2),
                                               '/': (0, 3),
                                               'C': (0, 4),
                                               '4': (1, 0), '5': (1, 1), '6': (1, 2),
                                               '*': (1, 3),
                                               '(': (1, 4),
                                               '1': (2, 0), '2': (2, 1), '3': (2, 2),
                                               '-': (2, 3),
                                               ')': (2, 4),
                                               '0': (3, 0), '00': (3, 1), '.': (3, 2),
                                               '+': (3, 3),
                                               '=': (3, 4),
                                               }
        # Create the buttons and add them to the grid layout
        for btnText, pos in buttons.items():
            self.buttons[btnText] = QPushButton(btnText)
            self.buttons[btnText].setFixedSize(40, 40)
            buttonsLayout.addWidget(self.buttons[btnText], pos[0], pos[1])
            # Add buttonsLayout to the general layout
            self.generalLayout.addLayout(buttonsLayout)

    def setDisplayText(self, text: str) -> None:
        """Set display's text."""
        self.display.setText(text)
        self.display.setFocus()

    def displayText(self) -> str:
        """Get display's text."""
        return cast(str, self.display.text())

    def clearDisplay(self) -> None:
        """Clear the display."""
        self.setDisplayText('')


class PyCalcCtrl:
    """PyCalc Controller class."""

    ERROR_MSG = 'ERROR'

    def __init__(self, view: PyCalcUi, model: EvalExpressionCallable) -> None:
        """Controller initializer."""
        self._view = view
        self._evaluate = model

        # Connect signals and slots
        self._connectSignals()

    def _calculateResult(self) -> None:
        """Evaluate expressions."""
        result = self._evaluate(self._view.displayText())
        self._view.setDisplayText(result)

    def _buildExpression(self, sub_exp: str) -> None:
        """Build expression."""
        if self._view.displayText() == self.ERROR_MSG:
            self._view.clearDisplay()

        expression = self._view.displayText() + sub_exp
        self._view.setDisplayText(expression)

    def _connectSignals(self) -> None:
        """Connect signals and slots."""
        for btnText, btn in self._view.buttons.items():
            if btnText not in {'=', 'C'}:
                btn.clicked.connect(partial(self._buildExpression, btnText))

        self._view.buttons['='].clicked.connect(self._calculateResult)
        self._view.display.returnPressed.connect(self._calculateResult)
        self._view.buttons['C'].clicked.connect(self._view.clearDisplay)


def evaluateExpression(expression: str) -> str:
    """Evaluate an expression."""
    try:
        result = str(eval(expression, {}, {}))
    except Exception:
        result = PyCalcCtrl.ERROR_MSG
    finally:
        return result


def main() -> None:
    """Main function."""
    # Create an instance of QApplication
    pycalc = QApplication(sys.argv)
    # Show the calculator's GUI
    view = PyCalcUi(win_title="MyCalc")
    view.show()
    # Create instances of the model and the controller
    PyCalcCtrl(view=view, model=evaluateExpression)

    calc = PyCalcFrame()
    calc.show()
    # Execute the calculator's main loop
    sys.exit(pycalc.exec_())


if __name__ == '__main__':
    main()
