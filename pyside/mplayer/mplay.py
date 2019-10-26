import sys
from PySide2.QtWidgets import (QWidget, QApplication, QLineEdit, QMenuBar, QStatusBar,
                               QPushButton, QVBoxLayout, QFileDialog, QListWidget, QLabel, QSlider,
                               # QDialog, QListWidgetItem,
                               )
from PySide2 import QtGui, QtCore
from pygame.mixer import mixer
from mutagen.mp3 import MP3  # ASF, FLAC, MP4, OGG
import os
import threading
import time
import logging
from dotenv import load_dotenv

from typing import List, Tuple, Optional as Opt, Union      # noqa: F401


# set DEBUG and logger
mplayer_path = os.path.dirname(os.path.abspath(__file__))
parent_path = os.path.dirname(mplayer_path)
env_path = os.path.join(parent_path, '.env')
load_dotenv(env_path)
DEBUG = os.environ.get("DEBUG") or False
logger = logging.getLogger()
if DEBUG: print("DEBUG mode on")


class Form(QWidget):
    """"""

    def __init__(self, parent: QApplication = None, *,
                 title: str = "wooo", width: int = 400, height: int = 600, ) -> None:
        """Constructor"""
        super().__init__(parent)
        mixer.init()  # initializethe pygame mixer

        self.assets_path: str = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'assets')

        if parent is not None:
            self.parent = parent

        """
        self.parent.iconbitmap()
        """
        horiz_pos = 100  # from left of screen
        vertic_pos = 200  # from top of screen
        self.height = height
        self.width = width
        self.title = title

        self.setGeometry(horiz_pos, vertic_pos, self.width, self.height)      # QtCore.QRect(x, y, w, h)
        self.setWindowTitle(self.title)

        self.setWindowIcon(QtGui.QIcon(self.assets_path + '/icons/melody.ico'))
        self.init_vol: int = 70
        self.paused: bool = False
        self.muted: bool = False
        self.playing: bool = False
        self.current_song: Opt[str] = None
        self.selected_song_num: Opt[int] = None
        self.playlist: List[str] = []

        self._init_ui()
        self.show()

    def _init_ui(self) -> None:
        self.layout = QVBoxLayout()
        self._menubar()

        self._create_rightframe()
        self._create_middleframe()
        self._create_leftframe()
        self._create_bottomframe()

        self.edit = QLineEdit("Write my name here")
        self.layout.addWidget(self.edit)

        self.greet_button = QPushButton("Show Greetings")
        self.greet_button.clicked.connect(self.greetings)
        self.layout.addWidget(self.greet_button)

        self._statusbar()
        self.setLayout(self.layout)

    def _menubar(self) -> None:
        menubar = QMenuBar()
        self.layout.addWidget(menubar)

        fileMenu = menubar.addMenu('File')
        fileMenu.addAction('Open', self.browse_file)
        fileMenu.addSeparator()
        fileMenu.addAction('Exit', self.close)

        helpMenu = menubar.addMenu('Help')
        helpMenu.addSeparator()
        helpMenu.addAction('About Us', self.about_us)
        # toolbar = self.addToolBar('Exit')
        # toolbar.addAction(self.play_music)

    def _statusbar(self) -> None:
        self.statusbar = QStatusBar()
        self.layout.addWidget(self.statusbar)
        self.statusbar.showMessage('Welcome', timeout=10_000)
        # status_bar = statusbar_parent.addPermanentWidget(statusbar_parent, stretch=True)

    def _create_rightframe(self) -> None:
        self.rightframe = QVBoxLayout()
        self.layout.addLayout(self.rightframe)

        self.filelabel = QLabel(text='Lets make some noise!')
        self.rightframe.addWidget(self.filelabel)

        self.lengthlabel = QLabel(text='Total Length : --:--')
        self.rightframe.addWidget(self.lengthlabel)

        self.currenttimelabel = QLabel(text='Current Time : --:--')
        self.rightframe.addWidget(self.currenttimelabel)

    def _create_leftframe(self) -> None:
        self.leftframe = QVBoxLayout()
        self.layout.addLayout(self.leftframe)

        self.playlistbox = QListWidget(self)
        self.playlistbox.setToolTip('''PlayListBox:
                                    Select song from list to play.
                                    Use browse or delete buttons to change playlist''')
        self.leftframe.addWidget(self.playlistbox)

        self.browse_button = QPushButton("Browse")
        self.browse_button.clicked.connect(self.browse_file)
        self.leftframe.addWidget(self.browse_button)

        self.delete_button = QPushButton("Delete")
        self.delete_button.clicked.connect(self.del_song)
        self.leftframe.addWidget(self.delete_button)

    def _create_middleframe(self) -> None:
        self.middleframe = QVBoxLayout()
        self.layout.addLayout(self.middleframe)

        self.play_button = QPushButton("Play")
        self.play_button.clicked.connect(self.play_music)
        play_icon = QtGui.QIcon(QtGui.QPixmap(self.assets_path + '/icons/play.png'))
        # play_icon.addPixmap(QtGui.QPixmap(self.assets_path + '/icons/play.png'))
        self.play_button.setIcon(play_icon)
        # self.play_button.setIconSize(QtCore.QSize(100, 100))
        self.middleframe.addWidget(self.play_button)

        self.stop_button = QPushButton("Stop")
        self.stop_button.clicked.connect(self.stop_music)
        stop_icon = QtGui.QIcon(QtGui.QPixmap(self.assets_path + '/icons/stop.png'))
        self.stop_button.setIcon(stop_icon)
        # self.stop_button.setIconSize(QtCore.QSize(100, 100))
        self.middleframe.addWidget(self.stop_button)

        self.pause_button = QPushButton("Pause")
        self.pause_button.clicked.connect(self.pause_music)
        pause_icon = QtGui.QIcon(QtGui.QPixmap(self.assets_path + '/icons/pause.png'))
        self.pause_button.setIcon(pause_icon)
        # self.pause_button.setIconSize(QtCore.QSize(100, 100))
        self.middleframe.addWidget(self.pause_button)

    def _create_bottomframe(self) -> None:
        self.bottomframe = QVBoxLayout()
        self.layout.addLayout(self.bottomframe)

        self.volume_button = QPushButton("Mute")
        self.mute_icon = QtGui.QIcon(QtGui.QPixmap(self.assets_path + '/icons/mute.png'))
        self.volume_icon = QtGui.QIcon(QtGui.QPixmap(self.assets_path + '/icons/volume.png'))
        self.volume_button.setIcon(self.volume_icon)
        # self.volume_button.setIconSize(QtCore.QSize(100, 100))
        self.volume_button.clicked.connect(self.mute_music)
        self.bottomframe.addWidget(self.volume_button)

        self.rewind_button = QPushButton("Rewind")
        rewind_icon = QtGui.QIcon(QtGui.QPixmap(self.assets_path + '/icons/rewind.png'))
        self.rewind_button.setIcon(rewind_icon)
        # self.volume_button.setIconSize(QtCore.QSize(100, 100))
        self.play_button.clicked.connect(self.rewind_music)
        self.bottomframe.addWidget(self.rewind_button)

        self.vol_scale = QSlider(QtCore.Qt.Horizontal)
        self.vol_scale.setMinimum(0)
        self.vol_scale.setMaximum(100)
        # self.vol_scale.setTickPosition(QSlider.TicksBelow)
        # self.vol_scale.setTickInterval(5)
        self.vol_scale.setValue(self.init_vol)
        self.vol_scale.valueChanged.connect(self.set_vol)
        self.bottomframe.addWidget(self.vol_scale)
        mixer.music.set_volume(self.vol_scale.value())

        # exitAction = QtGui.QAction('Exit', self)
        # exitAction.setShortcut('Ctrl+Q')
        # exitAction.setStatusTip('Exit application')
        # exitAction.triggered.connect(self.close)

    def set_vol(self) -> None:
        self.vol_from_slider: int = self.vol_scale.value()
        volume_percent: float = self.vol_from_slider / 100
        mixer.music.set_volume(volume_percent)  # from 0 to 1

    def mute_music(self) -> None:
        if self.muted:  # Unmute the music
            mixer.music.set_volume(self.vol_pre_mute / 100)
            self.volume_button.setIcon(self.volume_icon)
            self.vol_scale.setValue(self.vol_pre_mute)  # (self.vol_from_slider)
            self.muted = False
        else:  # mute the music
            self.vol_pre_mute: int = self.vol_scale.value()
            mixer.music.set_volume(0)
            self.volume_button.setIcon(self.mute_icon)
            self.vol_scale.setValue(0)
            self.muted = True

    def greetings(self) -> None:
        text = self.edit.text()
        print('Contents of QLineEdit widget: {}'.format(text))
        self.statusbar.showMessage(text, timeout=2_000)

    def about_us(self) -> None:
        text = self.edit.text()
        print('Contents of QLineEdit widget: {}'.format(text))

    def browse_file(self) -> None:
        get_filename_path: Tuple[str, str] = QFileDialog.getOpenFileName(self,   # if cancelled, returns ("", "")
                                                                         "Open Sound File",
                                                                         self.assets_path,
                                                                         "Sound Files (*.wav *.mp3 *.ogg)")
        print(get_filename_path)
        filename_path = get_filename_path[0]
        if filename_path:
            self.add_to_playlist(filename_path)
            mixer.music.queue(filename_path)

    def add_to_playlist(self, filepath: str) -> None:
        filename = os.path.basename(filepath)
        index = 0
        # print(self.playlist)
        # QListWidgetItem(self.playlistbox).setText(filename)  # last_added =
        self.playlistbox.insertItem(index, filename)  # .addItems([filenames])
        self.playlist.insert(index, filepath)
        index += 1

    def del_song(self) -> None:
        self.get_selected_song_num()  # update self.selected_song_num
        if self.selected_song_num is not None:  # if a song is selected
            print(self.selected_song_num)
            if self.playlist[self.selected_song_num] == self.current_song:  # if song is currently playing
                self.stop_music()                                           # stop it
            self.playlistbox.takeItem(self.selected_song_num)   # remove the song from the box, note returns the song object
            self.playlist.pop(self.selected_song_num)        # and playlist
            # self.selected_song_num remains same, so will play/del next song?
            self.reset_song()
            self.statusbar.showMessage("Song removed from playlist", timeout=1_000)
            self.selected_song_num = None  # reset self.selected_song_num"""

    def get_selected_song_num(self) -> None:
        if self.playlistbox.count() > 0:
            selected_song_from_box = self.playlistbox.currentItem()  # get current item
            if selected_song_from_box:
                self.selected_song: str = selected_song_from_box.text()  # get items text
                self.selected_song_num = self.playlistbox.currentRow()
            else:
                self.statusbar.showMessage("Choose a file from the playlist", timeout=2_000)
        else:
            self.statusbar.showMessage("No files loaded to playlist", timeout=2_000)

    def stop_music(self) -> None:
        if self.playing:
            self.playing = False
            self.current_song = None
            mixer.music.stop()
            self.statusbar.showMessage("Music Stopped", timeout=5_000)

    def pause_music(self) -> None:
        if self.playing:
            self.paused = True
            mixer.music.pause()
            self.statusbar.showMessage("Music paused", timeout=0)

    def rewind_music(self) -> None:
        if self.playing:
            self.stop_music()
            time.sleep(0.5)
            self.play_music()
            self.statusbar.showMessage("Music Rewound to start", timeout=1_000)

    def reset_song(self) -> None:
        self.current_song = None
        self.filelabel.setText("")
        self.lengthlabel.setText('Total Length : --:00')
        self.currenttimelabel.setText("Current Time : --:--")
        # self.statusbar.showMessage("", timeout=0)

    def show_details(self, play_song: str) -> None:
        self.filelabel.setText("Playing" + ' - ' + os.path.basename(play_song))
        file_data = os.path.splitext(play_song)

        if file_data[1] == '.mp3':
            audio = MP3(play_song)
            total_length = audio.info.length
        elif file_data[1] == '.wav':
            a = mixer.Sound(play_song)
            total_length = a.get_length()
        else:
            try:
                a = mixer.Sound(play_song)
                total_length = a.get_length()
            except Exception as e:
                print(e)
        self.current_song_lenth = total_length
        mins, secs = divmod(total_length, 60)  # returns (time//60, remainder)
        mins = round(mins)
        secs = round(secs)
        timeformat = '{:02d}:{:02d}'.format(mins, secs)
        self.lengthlabel.setText("Total Length" + ' - ' + timeformat)

        self.t1 = threading.Thread(target=self.start_count, args=(total_length, ))
        self.t1.start()

    def start_count(self, total_time: int) -> None:
        """"""
        current_time = 0
        while current_time <= total_time and mixer.music.get_busy():  # music.get_busy() -> Returns False when stopped
            if self.paused:
                continue  # if paused, infinite loop (don't count)
            else:
                mins, secs = divmod(current_time, 60)
                mins = round(mins)
                secs = round(secs)
                timeformat = '{:02d}:{:02d}'.format(mins, secs)
                self.currenttimelabel.setText("Current Time" + ' - ' + timeformat)
                time.sleep(1)
                current_time += 1

    def play_music(self) -> None:
        '''if not playing: play, if playing and paused, unpause'''
        self.get_selected_song_num()  # update self.selected_song_num
        if self.selected_song_num is not None and self.playlist:
            play_it: Opt[str] = self.playlist[self.selected_song_num]
        else:
            play_it = None

        if not self.playing and play_it:  # if not yet playing, play selected song
            try:
                self.stop_music()
                time.sleep(0.5)
                mixer.music.load(play_it)
                mixer.music.play()
            except Exception as e:
                # messagebox.showerror('File not found, or unknown file type. Please check again.')
                if DEBUG: print(e)
            else:
                self.playing = True
                self.current_song = play_it
                self.show_details(play_it)
                self.statusbar.showMessage("Playing music" + ' - ' + os.path.basename(play_it))
        elif self.playing and self.paused:  # if paused, resume
            mixer.music.unpause()
            # self.statusbar.showMessage("Playing music" + ' - ' + os.path.basename(play_it))
            self.statusbar.showMessage("Music Resumed", timeout=1_000)
            self.paused = False
        elif self.playing and not self.paused:
            if play_it == self.current_song and play_it is not None:  # if already playing song, do nothing
                self.statusbar.showMessage("Playing music" + ' - ' + os.path.basename(play_it), timeout=0)  # TODO timout current song len
            else:           # if different song selected, retry
                self.playing = False
                self.play_music()

    def close(self) -> None:
        try:
            self.stop_music()
            QApplication.closeAllWindows()
        except Exception as e:
            sys.exit(1)
            if DEBUG: print(e)
        else:
            print('App closed')


if __name__ == "__main__":
    app = QApplication(sys.argv)
    form = Form()
    sys.exit(app.exec_())
