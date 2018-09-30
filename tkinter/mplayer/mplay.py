from tkinter import (messagebox, filedialog, PhotoImage, Menu, Listbox,  # Frame, Label, Scale, Button,
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

from typing import List, Tuple


# set DEBUG and logger
mplayer_path = os.path.dirname(os.path.abspath(__file__))
parent_path = os.path.dirname(mplayer_path)
devenv_path = os.path.join(parent_path, '.env')
load_dotenv(devenv_path)
DEBUG = os.environ.get("DEBUG") or False
logger = logging.getLogger()
if DEBUG: print("DEBUG mode on")


try:
    root = tk.ThemedTk()
    root.get_themes()                 # Returns a list of all themes that can be set
    root.set_theme("plastik")
except AttributeError as e:
    root = tk.Tk()
    if DEBUG: print("Themed Tk not loaded")


mixer.init()  # initializing the mixer

statusbar = Label(root, text="Welcome to Melody", relief=SUNKEN, anchor=W)
statusbar.pack(side=BOTTOM, fill=X)

# Create the menubar
menubar = Menu(root)
root.config(menu=menubar)

# Set initial values
init_vol = 70
paused = False
muted = False
playing = False
current_song = None
filename: str
filename_path: str
playlist: List[str] = []

# add submenu1 commands


def browse_file() -> None:
    global filename_path
    filename_path = filedialog.askopenfilename()
    add_to_playlist(filename_path)
    mixer.music.queue(filename_path)


def add_to_playlist(filename: str) -> None:
    filename = os.path.basename(filename)
    index = 0
    playlistbox.insert(index, filename)
    playlist.insert(index, filename_path)
    index += 1


# Create the submenu1
subMenu1 = Menu(menubar, tearoff=0)
menubar.add_cascade(label="File", menu=subMenu1)
subMenu1.add_command(label="Open", command=browse_file)
subMenu1.add_command(label="Exit", command=root.destroy)

# add submenu2 commands


def about_us() -> None:
    messagebox.showinfo('About Melody', 'This is a music player built using Python Tkinter by @meee')


# Create the submenu2
subMenu2 = Menu(menubar, tearoff=0)
menubar.add_cascade(label="Help", menu=subMenu2)
subMenu2.add_command(label="About Us", command=about_us)


root.geometry('600x400')
root.minsize(400, 400)
root.title("Melody")
root.iconbitmap(mplayer_path + R'\assets\icons\melody.ico')


leftframe = Frame(root)
leftframe.pack(side=LEFT, padx=30)

playlistbox = Listbox(leftframe)
playlistbox.pack()

addBtn = Button(leftframe, text="+ Add", command=browse_file)
addBtn.pack(side=LEFT)


def del_song() -> None:
    selected_song_from_box: Tuple[int] = playlistbox.curselection()
    if selected_song_from_box:
        selected_song = int(selected_song_from_box[0])
        playlistbox.delete(selected_song)
        playlist.pop(selected_song)


delBtn = Button(leftframe, text="- Del", command=del_song)
delBtn.pack(side=LEFT)


rightframe = Frame(root)
rightframe.pack()


filelabel = Label(rightframe, text='Lets make some noise!')
filelabel.pack(pady=10)

lengthlabel = Label(rightframe, text='Total Length : --:--')
lengthlabel.pack()

currenttimelabel = Label(rightframe, text='Current Time : --:--', relief=GROOVE)
currenttimelabel.pack()


def start_count(total_time: int) -> None:
    global paused

    # mixer.music.get_busy(): - Returns FALSE when we press the stop button (music stop playing)
    # Continue - Ignores all of the statements below it. We check if music is paused or not.
    current_time = 0
    while current_time <= total_time and mixer.music.get_busy():
        if paused:
            continue
        else:
            mins, secs = divmod(current_time, 60)
            mins = round(mins)
            secs = round(secs)
            timeformat = '{:02d}:{:02d}'.format(mins, secs)
            currenttimelabel['text'] = "Current Time" + ' - ' + timeformat
            time.sleep(1)
            current_time += 1


def show_details(play_song: str) -> None:
    filelabel['text'] = "Playing" + ' - ' + os.path.basename(play_song)
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
    lengthlabel['text'] = "Total Length" + ' - ' + timeformat

    t1 = threading.Thread(target=start_count, args=(total_length, ))
    t1.start()


def pause_music() -> None:
    global paused
    paused = True
    mixer.music.pause()
    statusbar['text'] = "Music Paused"


def play_music() -> None:
    """if not playing: play, if playing and paused, unpause"""
    global paused
    global playing
    global current_song
    try:
        selected_song_from_box: Tuple[int] = playlistbox.curselection()
        selected_song = int(selected_song_from_box[0])
        play_it = playlist[selected_song]
    except IndexError as e:  # no files in the playlistbox tuple
        statusbar['text'] = "Choose a file from the playlist"
        if DEBUG:
            print(e)
    except Exception as e:
        messagebox.showerror('File not found, or unknown file type. Please check again.')
        if DEBUG:
            print(e)

    if not playing:  # if not yet playing, play selected song
        try:
            stop_music()
            time.sleep(0.5)
            mixer.music.load(play_it)
            mixer.music.play()
        except Exception as e:
            messagebox.showerror('File not found, or unknown file type. Please check again.')
            if DEBUG:
                print(e)
        else:
            playing = True
            current_song = play_it
            show_details(play_it)
            statusbar['text'] = "Playing music" + ' - ' + os.path.basename(play_it)
    elif playing and paused:  # if paused, resume
        mixer.music.unpause()
        statusbar['text'] = "Music Resumed"
        paused = False
    elif playing and not paused:
        if current_song == play_it:  # if already playing song, do nothing
            statusbar['text'] = "Playing music" + ' - ' + os.path.basename(play_it)
        else:           # if different song selected, retry
            playing = False
            play_music()


def stop_music() -> None:
    global playing
    global current_song
    playing = False
    current_song = None
    mixer.music.stop()
    statusbar['text'] = "Music Stopped"


def rewind_music() -> None:
    play_music()
    statusbar['text'] = "Music Rewound to start"


def set_vol(val: str) -> None:
    vol_float = float(val)
    volume = int(vol_float) / 100
    mixer.music.set_volume(volume)
    # set_volume of mixer takes value only from 0 to 1


def mute_music() -> None:
    global muted
    if muted:  # Unmute the music
        mixer.music.set_volume(0.7)
        volumeBtn.configure(image=volumePhoto)
        scale.set(70)
        muted = False
    else:  # mute the music
        mixer.music.set_volume(0)
        volumeBtn.configure(image=mutePhoto)
        scale.set(0)
        muted = True


middleframe = Frame(rightframe)
middleframe.pack(pady=30, padx=30)


playPhoto = PhotoImage(file=mplayer_path + '/assets/icons/play.png')
playBtn = Button(middleframe, image=playPhoto, command=play_music)
playBtn.grid(row=0, column=1, padx=10)

stopPhoto = PhotoImage(file=mplayer_path + '/assets/icons/stop.png')
stopBtn = Button(middleframe, image=stopPhoto, command=stop_music)
stopBtn.grid(row=0, column=2, padx=10)

pausePhoto = PhotoImage(file=mplayer_path + '/assets/icons/pause.png')
pauseBtn = Button(middleframe, image=pausePhoto, command=pause_music)
pauseBtn.grid(row=0, column=3, padx=10)


bottomframe = Frame(rightframe)
bottomframe.pack()


mutePhoto = PhotoImage(file=mplayer_path + '/assets/icons/mute.png')
volumePhoto = PhotoImage(file=mplayer_path + '/assets/icons/volume.png')
volumeBtn = Button(bottomframe, image=volumePhoto, command=mute_music)
volumeBtn.grid(row=0, column=1)


rewindPhoto = PhotoImage(file=mplayer_path + '/assets/icons/rewind.png')
rewindBtn = Button(bottomframe, image=rewindPhoto, command=rewind_music)
rewindBtn.grid(row=0, column=0)

scale = Scale(bottomframe, from_=0, to=100, orient=HORIZONTAL, command=set_vol)
scale.set(init_vol)
mixer.music.set_volume(init_vol / 100)
scale.grid(row=0, column=2, pady=15, padx=30)


def on_closing() -> None:
    try:
        stop_music()
        root.destroy()
    except Exception as e:
        if DEBUG: print(e)
    else:
        print('App closed')


root.protocol("WM_DELETE_WINDOW", on_closing)

if __name__ == "__main__":
    root.mainloop()
