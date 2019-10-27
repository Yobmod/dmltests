import sys
import json

import sqlite3
from sqlite3 import Error

from PySide2.QtWidgets import QDialog, QApplication
from PySide2.QtWidgets import QHBoxLayout, QVBoxLayout
from PySide2.QtWidgets import QLineEdit, QLabel, QPushButton

from typing import Optional as Opt, Dict, Union


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
        """save entry as json file and to SQLite database"""
        entry = {"name": self.name.text(),
                 "address": self.address.text(),
                 "phone": self.phone.text()}
        print(f"Hello {entry['name']}. Your address is {entry['address']} and phone number is {entry['phone']}")

        # TODO check data folder exists or create
        # TODO pass data path as arg to json and db funcs

        self.save_as_json(entry)
        self.save_to_db(entry)


    def save_as_json(self, entry_dict: Dict[str, Union[str, int]]) -> None:
        with open(Rf".\data\entry_{entry_dict['name']}.json", "w") as file:
            entry_json = json.dumps(entry_dict)
            file.write(entry_json)


    def save_to_db(self, entry_dict: Dict[str, Union[str, int]]) -> None: 
        db_conn = self.create_connection(R".\data\pythonsqlite.db")
        if db_conn is not None:
            self.create_table(db_conn)
            db_conn.close


    def create_connection(self, db_file: str) -> Opt[sqlite3.Connection]:
        """ create a database connection to a SQLite database """
        conn = None
        try:
            conn = sqlite3.connect(db_file)
            print(f"Database version SQLite {sqlite3.version}")
        except Error as e:
            print(e)
            return None
        else: 
            return conn

    def create_table(self, conn: sqlite3.Connection) -> None:
        create_table_sql = """ CREATE TABLE IF NOT EXISTS projects (
                                        id integer PRIMARY KEY,
                                        name text NOT NULL,
                                        address text,
                                        phone text ); """
        try:
            c = conn.cursor()
            c.execute(create_table_sql)
        except Error as e:
            print(e)


if __name__ == "__main__":
    app = QApplication([])
    form = Form()
    form.show()
    sys.exit(app.exec_())
