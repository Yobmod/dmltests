from tkinter import (messagebox, filedialog, PhotoImage, Menu, Listbox, Tk,  # Frame, Label, Scale, Button,
                     HORIZONTAL, LEFT, BOTTOM, X, W, SUNKEN, GROOVE, )
from tkinter.ttk import Button, Scale, Label, Frame
# import tkinter as tk
# from tkinter import ttk
from ttkthemes import themed_tk as tk
from pygame import mixer
from mutagen.mp3 import MP3  # ASF, FLAC, MP4, OGG
import os
import threading
import time
import logging
from dotenv import load_dotenv

from typing import List, Tuple, Optional as Opt, Union


# set DEBUG and logger
mplayer_path = os.path.dirname(os.path.abspath(__file__))
parent_path = os.path.dirname(mplayer_path)
env_path = os.path.join(parent_path, '.env')
load_dotenv(env_path)
DEBUG = os.environ.get("DEBUG") or False
logger = logging.getLogger()
if DEBUG: print("DEBUG mode on")


class Mplay(Frame):
    """Music player made with tkinter and pygame / mutagen
    Usage: app = Mplay(master: tk.Tk, *, title: str=, width: int=, height=)"""
    master: Frame  # shut up mypy

    def __init__(self,
                 parent: Union[Tk, tk.ThemedTk] = None,
                 *,
                 title: str = "Music Player",
                 width: int = 600,
                 height: int = 400,
                 ) -> None:
        super().__init__(parent)  # call ttk.Frame constructor
        mixer.init()  # initializethe pygame mixer
        self.assets_path: str = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'assets')

        if parent is not None:
            self.parent = parent
        else:
            self.parent = self.master

        self.parent.geometry(f'{width}x{height}')
        self.parent.title(title)
        self.parent.minsize(width // 2, height // 2)
        self.parent.iconbitmap(self.assets_path + '/icons/melody.ico')
        self.parent.protocol("WM_DELETE_WINDOW", self.on_closing)

        self.init_vol: int = 70
        self.paused: bool = False
        self.muted: bool = False
        self.playing: bool = False
        self.current_song: Opt[str] = None
        self.selected_song_num: Opt[int] = None
        self.playlist: List[str] = []

        self._init_ui()

    def _init_ui(self) -> None:
        self._menubar()
        self._statusbar()
        self._create_leftframe()
        self._create_rightframe()
        self._create_middleframe()
        self._create_bottomframe()

    def about_us(self) -> None:
        messagebox.showinfo('About Melody', 'This is a music player built using Python Tkinter by @meee')

    def browse_file(self) -> None:
        filename_path = filedialog.askopenfilename()
        if filename_path:
            self.add_to_playlist(filename_path)
            mixer.music.queue(filename_path)

    def add_to_playlist(self, filepath: str) -> None:
        filename = os.path.basename(filepath)
        index = 0
        self.playlistbox.insert(index, filename)
        self.playlist.insert(index, filepath)
        index += 1

    def _create_leftframe(self) -> None:
        self.leftframe = Frame(self.parent)
        self.leftframe.pack(side=LEFT, padx=30)

        self.playlistbox = Listbox(self.leftframe)
        self.playlistbox.pack()

        addBtn = Button(self.leftframe, text="+ Add", command=self.browse_file)
        addBtn.pack(side=LEFT)

        delBtn = Button(self.leftframe, text="- Del", command=self.del_song)
        delBtn.pack(side=LEFT)

    def _statusbar(self) -> None:
        self.statusbar = Label(self.parent, text="Welcome to Melody", relief=SUNKEN, anchor=W)
        self.statusbar.pack(side=BOTTOM, fill=X)

    def _menubar(self) -> None:
        menubar = Menu(self.parent)
        root.config(menu=menubar)
        # Create the submenu1
        subMenu1 = Menu(menubar, tearoff=0)
        menubar.add_cascade(label="File", menu=subMenu1)
        subMenu1.add_command(label="Open", command=self.browse_file)
        subMenu1.add_command(label="Exit", command=root.destroy)
        # Create the submenu2
        subMenu2 = Menu(menubar, tearoff=0)
        menubar.add_cascade(label="Help", menu=subMenu2)
        subMenu2.add_command(label="About Us", command=self.about_us)

    def del_song(self) -> None:
        self.get_selected_song_num()  # update self.selected_song_num
        if self.selected_song_num is not None:  # if a song is selected
            if self.playlist[self.selected_song_num] == self.current_song:  # if song is currently playing
                self.stop_music()                                           # stop it
            self.playlistbox.delete(self.selected_song_num)  # delete the song from the box
            self.playlist.pop(self.selected_song_num)        # and playlist
            # self.selected_song_num remains same, so will play/del next song?
            self.reset_song()
            self.selected_song_num = None  # reset self.selected_song_num

    def _create_rightframe(self) -> None:
        self.rightframe = Frame(self.parent)
        self.rightframe.pack()

        self.filelabel = Label(self.rightframe, text='Lets make some noise!')
        self.filelabel.pack(pady=10)

        self.lengthlabel = Label(self.rightframe, text='Total Length : --:--')
        self.lengthlabel.pack()

        self.currenttimelabel = Label(self.rightframe, text='Current Time : --:--', relief=GROOVE)
        self.currenttimelabel.pack()

    def start_count(self, total_time: int) -> None:
        """."""
        current_time = 0
        while current_time <= total_time and mixer.music.get_busy():  # music.get_busy() -> Returns False when stopped
            if self.paused:
                continue  # if paused, infinite loop (don't count)
            else:
                mins, secs = divmod(current_time, 60)
                mins = round(mins)
                secs = round(secs)
                timeformat = '{:02d}:{:02d}'.format(mins, secs)
                self.currenttimelabel['text'] = "Current Time" + ' - ' + timeformat
                time.sleep(1)
                current_time += 1

    def reset_song(self) -> None:
        self.current_song = None
        self.filelabel['text'] = ""
        self.lengthlabel['text'] = 'Total Length : --:--'
        self.currenttimelabel['text'] = "Current Time : --:--"
        self.statusbar['text'] = ""

    def show_details(self, play_song: str) -> None:
        self.filelabel['text'] = "Playing" + ' - ' + os.path.basename(play_song)
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
        # div - total_length/60, mod - total_length % 60
        mins, secs = divmod(total_length, 60)  # returns (time//60, remainder)
        mins = round(mins)
        secs = round(secs)
        timeformat = '{:02d}:{:02d}'.format(mins, secs)
        self.lengthlabel['text'] = "Total Length" + ' - ' + timeformat

        t1 = threading.Thread(target=self.start_count, args=(total_length, ))
        t1.start()

    def pause_music(self) -> None:
        if self.playing:
            self.paused = True
            mixer.music.pause()
            self.statusbar['text'] = "Music Paused"

    def get_selected_song_num(self) -> None:
        try:
            selected_song_from_box: Tuple[int] = self.playlistbox.curselection()
            self.selected_song_num = int(selected_song_from_box[0])
        except IndexError as e:  # no files in the playlistbox tuple
            self.statusbar['text'] = "Choose a file from the playlist"
            if DEBUG: print(e)
        except Exception as e:
            messagebox.showerror('File not found, or unknown file type. Please check again.')
            if DEBUG: print(e)

    def play_music(self) -> None:
        """if not playing: play, if playing and paused, unpause"""
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
                messagebox.showerror('File not found, or unknown file type. Please check again.')
                if DEBUG: print(e)
            else:
                self.playing = True
                self.current_song = play_it
                self.show_details(play_it)
                self.statusbar['text'] = "Playing music" + ' - ' + os.path.basename(play_it)
        elif self.playing and self.paused:  # if paused, resume
            mixer.music.unpause()
            self.statusbar['text'] = "Music Resumed"
            self.paused = False
        elif self.playing and not self.paused:
            if play_it == self.current_song and play_it is not None:  # if already playing song, do nothing
                self.statusbar['text'] = "Playing music" + ' - ' + os.path.basename(play_it)
            else:           # if different song selected, retry
                self.playing = False
                self.play_music()

    def stop_music(self) -> None:
        if self.playing:
            self.playing = False
            self.current_song = None
            mixer.music.stop()
            self.statusbar['text'] = "Music Stopped"

    def rewind_music(self) -> None:
        if self.playing:
            self.stop_music()
            time.sleep(0.5)
            self.play_music()
            self.statusbar['text'] = "Music Rewound to start"

    def set_vol(self, val: str) -> None:
        vol_float = float(val)
        volume = int(vol_float) / 100
        mixer.music.set_volume(volume)
        # set_volume of mixer takes value only from 0 to 1

    def mute_music(self) -> None:
        if self.muted:  # Unmute the music
            mixer.music.set_volume(0.7)
            self.volumeBtn.configure(image=self.volumePhoto)
            self.scale.set(70)
            self.muted = False
        else:  # mute the music
            mixer.music.set_volume(0)
            self.volumeBtn.configure(image=self.mutePhoto)
            self.scale.set(0)
            self.muted = True

    def _create_middleframe(self) -> None:
        self.middleframe = Frame(self.rightframe)
        self.middleframe.pack(pady=30, padx=30)

        self.playPhoto = PhotoImage(file=self.assets_path + '/icons/play.png')
        playBtn = Button(self.middleframe, image=self.playPhoto, command=self.play_music)
        playBtn.grid(row=0, column=1, padx=10)

        self.stopPhoto = PhotoImage(file=self.assets_path + '/icons/stop.png')
        stopBtn = Button(self.middleframe, image=self.stopPhoto, command=self.stop_music)
        stopBtn.grid(row=0, column=2, padx=10)

        self.pausePhoto = PhotoImage(file=self.assets_path + '/icons/pause.png')
        pauseBtn = Button(self.middleframe, image=self.pausePhoto, command=self.pause_music)
        pauseBtn.grid(row=0, column=3, padx=10)

    def _create_bottomframe(self) -> None:
        self.bottomframe = Frame(self.rightframe)
        self.bottomframe.pack()

        self.mutePhoto = PhotoImage(file=self.assets_path + '/icons/mute.png')
        self.volumePhoto = PhotoImage(file=self.assets_path + '/icons/volume.png')
        self.volumeBtn = Button(self.bottomframe, image=self.volumePhoto, command=self.mute_music)
        self.volumeBtn.grid(row=0, column=1)

        self.rewindPhoto = PhotoImage(file=self.assets_path + '/icons/rewind.png')
        rewindBtn = Button(self.bottomframe, image=self.rewindPhoto, command=self.rewind_music)
        rewindBtn.grid(row=0, column=0)

        self.scale = Scale(self.bottomframe, from_=0, to=100, orient=HORIZONTAL, command=self.set_vol)
        self.scale.set(self.init_vol)
        mixer.music.set_volume(self.init_vol / 100)
        self.scale.grid(row=0, column=2, pady=15, padx=30)

    def on_closing(self) -> None:
        try:
            self.stop_music()
            self.parent.destroy()
        except Exception as e:
            if DEBUG: print(e)
        else:
            print('App closed')


if __name__ == "__main__":
    try:
        root = tk.ThemedTk()
        root.get_themes()                 # Returns a list of all themes that can be set
        root.set_theme("plastik")
    except AttributeError as e:
        root = tk.Tk()
        if DEBUG: print("Themed Tk not loaded")
    finally:
        mplay_app = Mplay(root, title="DML Music Player")
        root.mainloop()
