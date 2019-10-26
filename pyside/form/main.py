import sys
import json

from PySide2.QtWidgets import QDialog, QApplication
from PySide2.QtWidgets import QHBoxLayout, QVBoxLayout
from PySide2.QtWidgets import QLineEdit, QLabel, QPushButton

from typing import Optional as Opt


class Form(QDialog):
    """"""

    def __init__(self, parent: Opt[QApplication] = None) -> None:
        """Constructor"""
        super(Form, self).__init__(parent)
        main_layout = QVBoxLayout()

        name_layout = QHBoxLayout()
        lbl = QLabel("Name:")
        self.name = QLineEdit("")
        name_layout.addWidget(lbl)
        name_layout.addWidget(self.name)
        name_layout.setSpacing(20)

        add_layout = QHBoxLayout()
        lbl = QLabel("Address:")
        self.address = QLineEdit("")
        add_layout.addWidget(lbl)
        add_layout.addWidget(self.address)

        phone_layout = QHBoxLayout()
        self.phone = QLineEdit("")
        phone_layout.addWidget(QLabel("Phone:"))
        phone_layout.addWidget(self.phone)
        phone_layout.setSpacing(18)

        self.button = QPushButton(text='Submit')
        self.button.clicked.connect(self.save_entries)

        main_layout.addLayout(name_layout, stretch=1)
        main_layout.addLayout(add_layout, stretch=1)
        main_layout.addLayout(phone_layout, stretch=1)
        main_layout.addWidget(self.button)
        self.setLayout(main_layout)

    def save_entries(self) -> None:
        entry = {"name": self.name.text(),
                 "address": self.address.text(),
                 "phone": self.phone.text()}
        print(f"Hello {entry['name']}. Your address is {entry['address']} and phone number is {entry['phone']}")

        with open(Rf".\data\entry_{entry['name']}.json", "w") as file:
            entry_json = json.dumps(entry)
            file.write(entry_json)


if __name__ == "__main__":
    app = QApplication([])
    form = Form()
    form.show()
    sys.exit(app.exec_())
