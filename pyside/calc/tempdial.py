import sys
from PySide2.QtWidgets import QApplication, QWidget, QSizePolicy, QDial, QVBoxLayout
from PySide2 import QtCore, QtGui, QtWidgets

from typing import Union, List, Any
from typing_extensions import Literal


class QEvent_(QtCore.QEvent): ...  # Typing


AllowedColorType = Literal['aliceblue', 'antiquewhite', 'aqua', 'aquamarine', 'azure',
                           'beige', 'bisque', 'black', 'blanchedalmond', 'blue', 'blueviolet', 'brown', 'burlywood',
                           'cadetblue', 'chartreuse', 'chocolate', 'coral', 'cornflowerblue', 'cornsilk', 'crimson', 'cyan',
                           'darkblue', 'darkcyan', 'darkgoldenrod', 'darkgray', 'darkgreen', 'darkgrey', 'darkkhaki',
                           'darkmagenta', 'darkolivegreen', 'darkorange', 'darkorchid', 'darkred', 'darksalmon',
                           'darkseagreen', 'darkslateblue', 'darkslategray', 'darkslategrey', 'darkturquoise', 'darkviolet',
                           'deeppink', 'deepskyblue', 'dimgray', 'dimgrey', 'dodgerblue',
                           'firebrick', 'floralwhite', 'forestgreen', 'fuchsia',
                           'gainsboro', 'ghostwhite', 'gold', 'goldenrod', 'gray', 'green', 'greenyellow', 'grey',
                           'honeydew', 'hotpink', 'indianred', 'indigo', 'ivory', 'khaki',
                           'lavender', 'lavenderblush', 'lawngreen', 'lemonchiffon',
                           'lightblue', 'lightcoral', 'lightcyan', 'lightgoldenrodyellow', 'lightgray', 'lightgreen',
                           'lightgrey', 'lightpink', 'lightsalmon', 'lightseagreen', 'lightskyblue', 'lightslategray',
                           'lightslategrey', 'lightsteelblue', 'lightyellow', 'lime', 'limegreen', 'linen',
                           'magenta', 'maroon', 'mediumaquamarine', 'mediumblue', 'mediumorchid', 'mediumpurple',
                           'mediumseagreen', 'mediumslateblue', 'mediumspringgreen', 'mediumturquoise', 'mediumvioletred',
                           'midnightblue', 'mintcream', 'mistyrose', 'moccasin', 'navajowhite', 'navy',
                           'oldlace', 'olive', 'olivedrab', 'orange', 'orangered', 'orchid',
                           'palegoldenrod', 'palegreen', 'paleturquoise', 'palevioletred', 'papayawhip', 'peachpuff', 'peru',
                           'pink', 'plum', 'powderblue', 'purple',
                           'red', 'rosybrown', 'royalblue', 'saddlebrown',
                           'salmon', 'sandybrown', 'seagreen', 'seashell', 'sienna', 'silver', 'skyblue',
                           'slateblue', 'slategray', 'slategrey', 'snow', 'springgreen', 'steelblue',
                           'tan', 'teal', 'thistle', 'tomato', 'turquoise',
                           'violet', 'wheat', 'white', 'whitesmoke', 'yellow', 'yellowgreen']


class _Bar(QWidget):
    """Sub-widget to hold bar part of the powerbar"""
    clickedValue = QtCore.Signal(int)

    def __init__(self, steps: Union[int, List[AllowedColorType]]) -> None:
        super().__init__()

        self.setSizePolicy(
            QSizePolicy.MinimumExpanding,
            QSizePolicy.MinimumExpanding
        )

        if isinstance(steps, list):
            # list of colours.
            self.n_steps = len(steps)
            self.steps = steps

        elif isinstance(steps, int):
            # int number of bars, defaults to red.
            self.n_steps = steps
            self.steps = ['red'] * steps

        else:
            raise TypeError('steps must be a list or int')

        self._bar_solid_percent = 0.8
        self._background_color = QtGui.QColor('black')
        self._padding = 4.0  # n-pixel gap around edge.

    def paintEvent(self, event: QEvent_) -> None:
        painter = QtGui.QPainter(self)

        brush = QtGui.QBrush()
        brush.setColor(self._background_color)
        brush.setStyle(QtCore.Qt.SolidPattern)
        rect = QtCore.QRect(0, 0, painter.device().width(), painter.device().height())
        painter.fillRect(rect, brush)

        # Get current state.
        parent = self.parent()
        vmin, vmax = parent.minimum(), parent.maximum()
        value = parent.value()

        # Define our canvas.
        d_height = painter.device().height() - (self._padding * 2)
        d_width = painter.device().width() - (self._padding * 2)

        # Draw the bars.
        step_size = d_height / self.n_steps
        bar_height = step_size * self._bar_solid_percent
        bar_spacer = step_size * (1 - self._bar_solid_percent) / 2

        # Calculate the y-stop position, from the value in range.
        pc = (value - vmin) / (vmax - vmin)
        n_steps_to_draw = int(pc * self.n_steps)

        for n in range(n_steps_to_draw):
            brush.setColor(QtGui.QColor(self.steps[n]))
            rect = QtCore.QRect(
                self._padding,
                self._padding + d_height - ((1 + n) * step_size) + bar_spacer,
                d_width,
                bar_height
            )
            painter.fillRect(rect, brush)

        painter.end()

    def sizeHint(self) -> QtCore.QSize:
        return QtCore.QSize(40, 120)

    def _trigger_refresh(self) -> None:
        self.update()

    def _calculate_clicked_value(self, event: 'QtWidgets.QGraphicsSceneMouseEvent') -> None:
        parent = self.parent()
        vmin, vmax = parent.minimum(), parent.maximum()
        d_height = self.size().height() + (self._padding * 2)
        step_size = d_height / self.n_steps
        click_y = event.y() - self._padding - step_size / 2

        pc = (d_height - click_y) / d_height
        value = vmin + pc * (vmax - vmin)
        self.clickedValue.emit(value)

    def mouseMoveEvent(self, event: 'QtWidgets.QGraphicsSceneMouseEvent') -> None:
        self._calculate_clicked_value(event)

    def mousePressEvent(self, event: 'QtWidgets.QGraphicsSceneMouseEvent') -> None:
        self._calculate_clicked_value(event)


class PowerBar(QWidget):
    """Custom Qt Widget to show a power bar and dial.
    Left-clicking the button shows the color-chooser, while
    right-clicking resets the color to None (no-color)."""

    colorChanged = QtCore.Signal()

    def __init__(self, steps: Union[int, List[AllowedColorType]] = 5) -> None:
        super().__init__()

        layout = QVBoxLayout()
        self._bar = _Bar(steps)
        layout.addWidget(self._bar)

        # Create the QDial widget and set up defaults.
        # - we provide accessors on this class to override.
        self._dial = QDial()
        self._dial.setNotchesVisible(True)
        self._dial.setWrapping(False)
        self._dial.valueChanged.connect(self._bar._trigger_refresh)

        # Take feedback from click events on the meter.
        self._bar.clickedValue.connect(self._dial.setValue)

        layout.addWidget(self._dial)
        self.setLayout(layout)

    def __getattr__(self, name: str) -> Any:
        if name in self.__dict__:
            return self[name]
        else:
            return getattr(self._dial, name)

    def setColor(self, color: AllowedColorType) -> None:
        self._bar.steps = [color] * self._bar.n_steps
        self._bar.update()

    def setColors(self, colors: List[AllowedColorType]) -> None:
        self._bar.n_steps = len(colors)
        self._bar.steps = colors
        self._bar.update()

    def setBarPadding(self, i: float) -> None:
        self._bar._padding = int(i)
        self._bar.update()

    def setBarSolidPercent(self, f: float) -> None:
        self._bar._bar_solid_percent = float(f)
        self._bar.update()

    def setBackgroundColor(self, color: AllowedColorType) -> None:
        self._bar._background_color = QtGui.QColor(color)
        self._bar.update()


def main() -> None:
    """Main function."""
    pycalc = QApplication(sys.argv)
    colors: List[AllowedColorType] = ['aliceblue', 'fuchsia', QtCore.Qt.GlobalColor.yellow,
                                      'mediumspringgreen', 'palegoldenrod', 'purple']
    calc = PowerBar(colors)
    calc.show()
    sys.exit(pycalc.exec_())


if __name__ == '__main__':
    main()
